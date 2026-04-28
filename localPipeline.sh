#!/usr/bin/env bash
set -u
set -o pipefail

readonly SCRIPT_NAME="$(basename "$0")"
readonly PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
readonly DEFAULT_PRESET="linux-debug"

PRESET="${DEFAULT_PRESET}"
NO_RUN=0
VERBOSE=0
BUILD_DIR=""
declare -a RESULTS=()

print_usage() {
    cat <<EOF
Usage: ${SCRIPT_NAME} [--preset NAME] [--build-dir PATH] [--no-run] [--verbose] [--help]

Run the local LVGL Coffee Dispenser validation pipeline.

Stages:
  1. Initialize git submodules
  2. Configure with CMake preset
  3. Build
  4. Run CTest
  5. Run clang-format in non-mutating check mode
  6. Optionally launch the app briefly as a smoke run

Options:
  --preset NAME      CMake preset to use; default: ${DEFAULT_PRESET}
  --build-dir PATH   Override build directory for the smoke-run executable lookup
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
    if SDL_VIDEODRIVER="${SDL_VIDEODRIVER:-dummy}" timeout 5s "${executable}" >/dev/null 2>&1; then
        record_result "Launch App" "PASS" "Application exited during smoke run"
        return 0
    fi

    local status=$?
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
    stage_smoke_run || failed=1

    print_summary
    return "${failed}"
}

main "$@"
