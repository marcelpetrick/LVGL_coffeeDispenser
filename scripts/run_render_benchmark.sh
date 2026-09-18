#!/usr/bin/env bash
# Drive the application with the rendering profiler enabled and turn the
# collected numbers into a Markdown report.
#
# The run is headless by default (SDL dummy video driver), which measures the
# LVGL software rendering cost without a compositor in the way. Use
# --video-driver x11 to measure a real window instead.
set -euo pipefail

SCRIPT_NAME="$(basename "$0")"
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

BUILD_DIR="${PROJECT_ROOT}/build/linux-release"
DURATION_MS=10000
VIDEO_DRIVER="dummy"
FORCE_REDRAW=1
OUTPUT=""

print_usage() {
    cat <<EOF
Usage: ${SCRIPT_NAME} [options]

Options:
  --build-dir PATH      Directory holding lvgl_coffee_dispenser; default: build/linux-release
  --duration-ms MS      Measured runtime; default: ${DURATION_MS}
  --video-driver NAME   SDL video driver; default: ${VIDEO_DRIVER} (headless)
  --idle                Do not force redraws; measures the idle UI instead
  --output FILE         Markdown report; default: LVGL_<project version>_benchmark.md
  --help, -h            Show this help
EOF
}

while [[ "$#" -gt 0 ]]; do
    case "$1" in
        --build-dir) shift; BUILD_DIR="$1" ;;
        --duration-ms) shift; DURATION_MS="$1" ;;
        --video-driver) shift; VIDEO_DRIVER="$1" ;;
        --idle) FORCE_REDRAW=0 ;;
        --output) shift; OUTPUT="$1" ;;
        --help|-h) print_usage; exit 0 ;;
        *) echo "Unknown argument: $1" >&2; print_usage; exit 2 ;;
    esac
    shift
done

executable="${BUILD_DIR}/lvgl_coffee_dispenser"
if [[ ! -x "${executable}" ]]; then
    echo "executable not found: ${executable}" >&2
    echo "build it first, for example: cmake --preset linux-release && cmake --build --preset linux-release" >&2
    exit 1
fi

project_version="$(sed -n 's/^[[:space:]]*VERSION[[:space:]]\+\([0-9]\+\.[0-9]\+\.[0-9]\+\)[[:space:]]*$/\1/p' "${PROJECT_ROOT}/CMakeLists.txt" | head -1)"
lvgl_version="$(sed -n 's/^#define LVGL_VERSION_\(MAJOR\|MINOR\|PATCH\)[[:space:]]\+\([0-9]\+\)$/\2/p' "${PROJECT_ROOT}/external/lvgl/lv_version.h" | paste -sd. -)"
OUTPUT="${OUTPUT:-${PROJECT_ROOT}/LVGL_${project_version}_benchmark.md}"

log_file="$(mktemp)"
trap 'rm -f "${log_file}"' EXIT

echo "[INFO] running ${executable} for ${DURATION_MS} ms (driver=${VIDEO_DRIVER}, force_redraw=${FORCE_REDRAW})"
SDL_VIDEODRIVER="${VIDEO_DRIVER}" \
    COFFEE_PERF_PROFILE=1 \
    COFFEE_PERF_FORCE_REDRAW="${FORCE_REDRAW}" \
    COFFEE_EXIT_AFTER_STARTUP_MS="${DURATION_MS}" \
    "${executable}" | tee "${log_file}"

if ! grep -q '\[PERF\] stage=summary' "${log_file}"; then
    echo "no profiling output was produced" >&2
    exit 1
fi

field() {
    # The line is selected first, then the key is read from it: a pattern that
    # spans both would need a separator before the first key, which is not there.
    sed -n "/\[PERF\] stage=$1 /s/.*[[:space:]]$2=\([^[:space:]]*\).*/\1/p" "${log_file}" | head -1
}

render_row() {
    local stage="$1"
    printf '| %s | %s | %s | %s | %s | %s | %s |\n' \
        "${stage}" \
        "$(field "${stage}" count)" \
        "$(field "${stage}" min_us)" \
        "$(field "${stage}" mean_us)" \
        "$(field "${stage}" median_us)" \
        "$(field "${stage}" p95_us)" \
        "$(field "${stage}" max_us)"
}

refresh_period="$(sed -n 's/^#define LV_DEF_REFR_PERIOD[[:space:]]\+\([0-9]\+\).*/\1/p' \
    "${PROJECT_ROOT}/config/lv_conf.h" "${PROJECT_ROOT}/external/lvgl/lv_conf_template.h" | head -1)"

cpu_model="$(sed -n 's/^model name[[:space:]]*:[[:space:]]*//p' /proc/cpuinfo | head -1)"
compiler="$(cc --version | head -1)"
frames="$(field summary frames)"
fps="$(field summary fps)"
runtime="$(field summary runtime_ms)"
width="$(field summary width)"
height="$(field summary height)"
color_depth="$(field summary color_depth)"

{
    printf '# Rendering benchmark - LVGL Coffee Dispenser %s\n\n' "${project_version}"
    printf -- '- Date: %s\n' "$(date -u '+%Y-%m-%d %H:%M:%SZ')"
    printf -- '- Application version: %s\n' "${project_version}"
    printf -- '- LVGL version: %s\n' "${lvgl_version}"
    printf -- '- Resolution: %s x %s, LV_COLOR_DEPTH %s\n' "${width}" "${height}" "${color_depth}"
    printf -- '- SDL video driver: `%s`\n' "${VIDEO_DRIVER}"
    printf -- '- Workload: %s\n' \
        "$([[ "${FORCE_REDRAW}" -eq 1 ]] && echo 'full-screen invalidation every main-loop iteration' || echo 'idle UI, only the invalidations the application triggers itself')"
    printf -- '- CPU: %s\n' "${cpu_model}"
    printf -- '- Compiler: %s\n' "${compiler}"
    printf -- '- Kernel: %s\n\n' "$(uname -sr)"
    printf 'Measured runtime %s ms, %s rendered frames, %s frames/s.\n\n' "${runtime}" "${frames}" "${fps}"
    printf '| Stage | Frames | min (us) | mean (us) | median (us) | p95 (us) | max (us) |\n'
    printf '| --- | ---: | ---: | ---: | ---: | ---: | ---: |\n'
    render_row render
    render_row flush
    frame_us=$(( $(field render mean_us) + $(field flush mean_us) ))
    printf '\nOne fully invalidated frame costs %s us of CPU time on average (render + flush), which is a '\
'capacity of about %s frames/s. The measured %s frames/s is the rate LVGL asks for: it refreshes at most '\
'every LV_DEF_REFR_PERIOD = %s ms, so roughly %s frames/s is the ceiling of this configuration, and the '\
'headroom between the two numbers is what is left for application logic on a slower target.\n' \
        "${frame_us}" "$((1000000 / frame_us))" "${fps}" "${refresh_period}" "$((1000 / refresh_period))"
    printf '\n`render` is the LVGL software rendering of the invalidated area, `flush` is handing the '
    printf 'rendered buffer to SDL. Both are measured inside the display driver through the LVGL '
    printf 'render and flush events, so the numbers exclude the main loop delay.\n\n'
    printf 'Reproduce with:\n\n'
    printf '```bash\n./scripts/run_render_benchmark.sh --duration-ms %s%s\n```\n' \
        "${DURATION_MS}" "$([[ "${FORCE_REDRAW}" -eq 1 ]] && echo '' || echo ' --idle')"
} > "${OUTPUT}"

echo "[INFO] report written to ${OUTPUT}"
