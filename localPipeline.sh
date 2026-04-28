#!/usr/bin/env bash
set -u
set -o pipefail

readonly SCRIPT_NAME="$(basename "$0")"
readonly PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
readonly DEFAULT_PRESET="linux-debug"
readonly DEFAULT_COVERAGE_BUILD_DIR="${PROJECT_ROOT}/build-coverage"
readonly COVERAGE_MIN_LINE_PERCENT="80.0"

PRESET="${DEFAULT_PRESET}"
NO_RUN=0
VERBOSE=0
BUILD_DIR=""
COVERAGE_BUILD_DIR="${DEFAULT_COVERAGE_BUILD_DIR}"
declare -a RESULTS=()

print_usage() {
    cat <<EOF
Usage: ${SCRIPT_NAME} [--preset NAME] [--build-dir PATH] [--coverage-build-dir PATH] [--no-run] [--verbose] [--help]

Run the local LVGL Coffee Dispenser validation pipeline.

Stages:
  1. Initialize git submodules
  2. Configure with CMake preset
  3. Build
  4. Run CTest
  5. Run clang-format in non-mutating check mode
  6. Build coverage configuration and generate coverage reports
  7. Generate Doxygen documentation
  8. Run Cppcheck static analysis
  9. Optionally launch the app briefly as a smoke run

Options:
  --preset NAME      CMake preset to use; default: ${DEFAULT_PRESET}
  --build-dir PATH   Override build directory for the smoke-run executable lookup
  --coverage-build-dir PATH
                     Override coverage build directory; default: build-coverage
  --no-run           Skip the final application smoke launch
  --verbose          Print command output for all stages
  --help, -h         Show this help
EOF
}

log() {
    printf '[INFO] %s\n' "$*"
}

warn() {
    printf '[WARN] %s\n' "$*" >&2
}

error() {
    printf '[ERROR] %s\n' "$*" >&2
}

record_result() {
    RESULTS+=("$1|$2|$3")
}

print_summary() {
    printf '\n========== Local Pipeline Summary ==========\n'
    local item stage status detail
    for item in "${RESULTS[@]}"; do
        IFS='|' read -r stage status detail <<<"${item}"
        printf '%-20s : %-4s %s\n' "${stage}" "${status}" "${detail}"
    done
    printf '============================================\n'
}

run_command() {
    if [[ "${VERBOSE}" -eq 1 ]]; then
        "$@"
    else
        "$@" >/dev/null
    fi
}

resolve_ctest() {
    local cmake_path
    cmake_path="$(command -v cmake 2>/dev/null || true)"
    if [[ -n "${cmake_path}" && -x "$(dirname "${cmake_path}")/ctest" ]]; then
        printf '%s\n' "$(dirname "${cmake_path}")/ctest"
        return 0
    fi
    command -v ctest
}

parse_arguments() {
    while [[ "$#" -gt 0 ]]; do
        case "$1" in
            --preset)
                shift
                if [[ "$#" -eq 0 ]]; then
                    error "Missing value for --preset."
                    exit 2
                fi
                PRESET="$1"
                ;;
            --build-dir)
                shift
                if [[ "$#" -eq 0 ]]; then
                    error "Missing value for --build-dir."
                    exit 2
                fi
                BUILD_DIR="$1"
                ;;
            --coverage-build-dir)
                shift
                if [[ "$#" -eq 0 ]]; then
                    error "Missing value for --coverage-build-dir."
                    exit 2
                fi
                COVERAGE_BUILD_DIR="$1"
                ;;
            --no-run|--noRun)
                NO_RUN=1
                ;;
            --verbose)
                VERBOSE=1
                ;;
            --help|-h)
                print_usage
                exit 0
                ;;
            *)
                error "Unknown argument: $1"
                print_usage
                exit 2
                ;;
        esac
        shift
    done
}

require_command() {
    local command_name="$1"
    if ! command -v "${command_name}" >/dev/null 2>&1; then
        error "Required command '${command_name}' was not found in PATH."
        return 1
    fi
}

stage_submodules() {
    log "Checking submodules."
    if run_command git submodule update --init --recursive; then
        record_result "Submodules" "PASS" "Dependencies initialized"
        return 0
    fi
    record_result "Submodules" "FAIL" "git submodule update failed"
    return 1
}

stage_configure() {
    log "Configuring preset '${PRESET}'."
    if run_command cmake --preset "${PRESET}"; then
        record_result "Configure" "PASS" "Preset ${PRESET} configured"
        return 0
    fi
    record_result "Configure" "FAIL" "CMake configure failed"
    return 1
}

stage_build() {
    log "Building preset '${PRESET}'."
    if run_command cmake --build --preset "${PRESET}"; then
        record_result "Build" "PASS" "Preset ${PRESET} built"
        return 0
    fi
    record_result "Build" "FAIL" "CMake build failed"
    return 1
}

stage_tests() {
    local ctest_bin
    ctest_bin="$(resolve_ctest)" || {
        record_result "Unit Tests" "FAIL" "ctest not found"
        return 1
    }

    log "Running unit tests."
    if run_command "${ctest_bin}" --preset "${PRESET}" --output-on-failure; then
        record_result "Unit Tests" "PASS" "CTest completed without failures"
        return 0
    fi
    record_result "Unit Tests" "FAIL" "CTest reported failures"
    return 1
}

extract_summary_json_number() {
    local json_file="$1"
    local key="$2"
    python3 - "${json_file}" "${key}" <<'PY'
import json
import sys

with open(sys.argv[1], "r", encoding="utf-8") as handle:
    data = json.load(handle)
value = data.get(sys.argv[2])
if value is None:
    sys.exit(1)
print(value)
PY
}

number_greater_equal() {
    python3 - "$1" "$2" <<'PY'
import sys

actual = float(sys.argv[1])
minimum = float(sys.argv[2])
sys.exit(0 if actual >= minimum else 1)
PY
}

stage_coverage() {
    if ! command -v gcov >/dev/null 2>&1; then
        record_result "Coverage" "FAIL" "gcov not found"
        return 1
    fi
    if ! command -v gcovr >/dev/null 2>&1; then
        record_result "Coverage" "FAIL" "gcovr not found"
        return 1
    fi

    local coverage_dir="${COVERAGE_BUILD_DIR}"
    if [[ "${coverage_dir}" != /* ]]; then
        coverage_dir="${PROJECT_ROOT}/${coverage_dir}"
    fi

    log "Configuring coverage build."
    if ! run_command cmake -S "${PROJECT_ROOT}" -B "${coverage_dir}" -G Ninja \
        -DCMAKE_BUILD_TYPE=Debug \
        -DCOFFEE_BACKEND=SDL \
        -DCOFFEE_BUILD_TESTS=ON \
        -DCOFFEE_ENABLE_COVERAGE=ON; then
        record_result "Coverage" "FAIL" "Coverage configure failed"
        return 1
    fi

    log "Building coverage configuration."
    if ! run_command cmake --build "${coverage_dir}"; then
        record_result "Coverage" "FAIL" "Coverage build failed"
        return 1
    fi

    log "Generating coverage report."
    if ! run_command cmake --build "${coverage_dir}" --target coverage-html; then
        record_result "Coverage" "FAIL" "Coverage report generation failed"
        return 1
    fi

    local summary_file="${coverage_dir}/coverage/summary.json"
    local html_index="${coverage_dir}/coverage/html/index.html"
    if [[ ! -f "${summary_file}" || ! -f "${html_index}" ]]; then
        record_result "Coverage" "FAIL" "Coverage output missing"
        return 1
    fi

    local line_percent
    line_percent="$(extract_summary_json_number "${summary_file}" "line_percent")" || {
        record_result "Coverage" "FAIL" "Could not parse line_percent"
        return 1
    }

    if number_greater_equal "${line_percent}" "${COVERAGE_MIN_LINE_PERCENT}"; then
        record_result "Coverage" "PASS" "Line coverage ${line_percent}%"
        record_result "Coverage Gate" "PASS" "Threshold ${COVERAGE_MIN_LINE_PERCENT}%"
        return 0
    fi

    record_result "Coverage" "PASS" "Line coverage ${line_percent}%"
    record_result "Coverage Gate" "FAIL" "Threshold ${COVERAGE_MIN_LINE_PERCENT}%"
    return 1
}

stage_format() {
    if ! command -v clang-format >/dev/null 2>&1; then
        record_result "clang-format" "FAIL" "clang-format not found"
        return 1
    fi

    mapfile -t sources < <(find config src tests -type f \( -name '*.c' -o -name '*.h' \) -print | sort)
    if ((${#sources[@]} == 0)); then
        record_result "clang-format" "SKIP" "No C sources found"
        return 0
    fi

    log "Checking clang-format."
    if run_command clang-format --dry-run --Werror "${sources[@]}"; then
        record_result "clang-format" "PASS" "Source formatting is clean"
        return 0
    fi
    record_result "clang-format" "FAIL" "Run clang-format -i on changed source files"
    return 1
}

stage_cppcheck() {
    if ! command -v cppcheck >/dev/null 2>&1; then
        record_result "Cppcheck" "FAIL" "cppcheck not found"
        return 1
    fi

    local build_dir="${BUILD_DIR}"
    if [[ -z "${build_dir}" ]]; then
        build_dir="${PROJECT_ROOT}/build/${PRESET}"
    fi

    log "Running Cppcheck."
    local args=(--build-dir "${build_dir}")
    if [[ "${VERBOSE}" -eq 1 ]]; then
        args+=(--verbose)
    fi

    if run_command "${PROJECT_ROOT}/scripts/run_cppcheck.sh" "${args[@]}"; then
        record_result "Cppcheck" "PASS" "Static analysis report generated"
        return 0
    fi
    record_result "Cppcheck" "FAIL" "Static analysis failed"
    return 1
}

stage_doxygen() {
    if ! command -v doxygen >/dev/null 2>&1; then
        record_result "Doxygen" "FAIL" "doxygen not found"
        return 1
    fi

    local build_dir="${BUILD_DIR}"
    if [[ -z "${build_dir}" ]]; then
        build_dir="${PROJECT_ROOT}/build/${PRESET}"
    fi
    if [[ "${build_dir}" != /* ]]; then
        build_dir="${PROJECT_ROOT}/${build_dir}"
    fi

    log "Generating Doxygen documentation."
    if ! run_command cmake --build "${build_dir}" --target doxygen; then
        record_result "Doxygen" "FAIL" "Documentation generation failed"
        return 1
    fi

    local warnings_file="${build_dir}/doxygen/warnings.txt"
    local index_file="${build_dir}/doxygen/html/index.html"
    if [[ ! -f "${index_file}" ]]; then
        record_result "Doxygen" "FAIL" "Missing HTML entry point"
        return 1
    fi

    if [[ -s "${warnings_file}" ]]; then
        record_result "Doxygen" "FAIL" "warnings.txt is not empty"
        return 1
    fi

    record_result "Doxygen" "PASS" "HTML generated without warnings"
    return 0
}

stage_smoke_run() {
    if [[ "${NO_RUN}" -eq 1 ]]; then
        record_result "Launch App" "SKIP" "--no-run selected"
        return 0
    fi

    local binary_dir="${BUILD_DIR}"
    if [[ -z "${binary_dir}" ]]; then
        binary_dir="${PROJECT_ROOT}/build/${PRESET}"
    elif [[ "${binary_dir}" != /* ]]; then
        binary_dir="${PROJECT_ROOT}/${binary_dir}"
    fi

    local executable="${binary_dir}/lvgl_coffee_dispenser"
    if [[ ! -x "${executable}" ]]; then
        record_result "Launch App" "FAIL" "Executable not found: ${executable}"
        return 1
    fi

    log "Launching app smoke test for 5 seconds."
    SDL_VIDEODRIVER="${SDL_VIDEODRIVER:-dummy}" timeout 5s "${executable}" >/dev/null 2>&1
    local status=$?
    if [[ "${status}" -eq 0 ]]; then
        record_result "Launch App" "PASS" "Application exited during smoke run"
        return 0
    fi

    if [[ "${status}" -eq 124 ]]; then
        record_result "Launch App" "PASS" "Application stayed alive for smoke timeout"
        return 0
    fi

    record_result "Launch App" "FAIL" "Application exited with status ${status}"
    return 1
}

main() {
    parse_arguments "$@"

    cd "${PROJECT_ROOT}" || exit 1
    log "Project root: ${PROJECT_ROOT}"
    log "Preset: ${PRESET}"

    local missing=0
    require_command git || missing=1
    require_command cmake || missing=1
    require_command clang-format || missing=1
    require_command cppcheck || missing=1
    require_command doxygen || missing=1
    require_command gcov || missing=1
    require_command gcovr || missing=1
    require_command python3 || missing=1
    require_command timeout || missing=1
    if [[ "${missing}" -ne 0 ]]; then
        record_result "Prerequisites" "FAIL" "Required command missing"
        print_summary
        exit 1
    fi

    local failed=0
    stage_submodules || failed=1
    stage_configure || failed=1
    stage_build || failed=1
    stage_tests || failed=1
    stage_format || failed=1
    stage_coverage || failed=1
    stage_doxygen || failed=1
    stage_cppcheck || failed=1
    stage_smoke_run || failed=1

    print_summary
    return "${failed}"
}

main "$@"
