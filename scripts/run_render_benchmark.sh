#!/usr/bin/env bash
# Drive the application with the rendering profiler enabled and turn the
# collected numbers into a Markdown report.
#
# The measurement is repeated (10 runs by default) because a single run says
# nothing about the spread: the report lists every run and the aggregate.
#
# The runs are headless by default (SDL dummy video driver), which measures the
# LVGL software rendering cost without a compositor in the way. Use
# --video-driver x11 to measure a real window instead.
set -euo pipefail

SCRIPT_NAME="$(basename "$0")"
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

BUILD_DIR="${PROJECT_ROOT}/build/linux-release"
DURATION_MS=5000
RUNS=10
VIDEO_DRIVER="dummy"
FORCE_REDRAW=1
OUTPUT=""

print_usage() {
    cat <<EOF
Usage: ${SCRIPT_NAME} [options]

Options:
  --build-dir PATH      Directory holding lvgl_coffee_dispenser; default: build/linux-release
  --duration-ms MS      Runtime of a single run; default: ${DURATION_MS}
  --runs N              Number of repeated runs; default: ${RUNS}
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
        --runs) shift; RUNS="$1" ;;
        --video-driver) shift; VIDEO_DRIVER="$1" ;;
        --idle) FORCE_REDRAW=0 ;;
        --output) shift; OUTPUT="$1" ;;
        --help|-h) print_usage; exit 0 ;;
        *) echo "Unknown argument: $1" >&2; print_usage; exit 2 ;;
    esac
    shift
done

if [[ ! "${RUNS}" =~ ^[0-9]+$ ]] || [[ "${RUNS}" -lt 1 ]]; then
    echo "--runs needs a positive number" >&2
    exit 2
fi

executable="${BUILD_DIR}/lvgl_coffee_dispenser"
if [[ ! -x "${executable}" ]]; then
    echo "executable not found: ${executable}" >&2
    echo "build it first, for example: cmake --preset linux-release && cmake --build --preset linux-release" >&2
    exit 1
fi

project_version="$(sed -n 's/^[[:space:]]*VERSION[[:space:]]\+\([0-9]\+\.[0-9]\+\.[0-9]\+\)[[:space:]]*$/\1/p' "${PROJECT_ROOT}/CMakeLists.txt" | head -1)"
lvgl_version="$(sed -n 's/^#define LVGL_VERSION_\(MAJOR\|MINOR\|PATCH\)[[:space:]]\+\([0-9]\+\)$/\2/p' "${PROJECT_ROOT}/external/lvgl/lv_version.h" | paste -sd. -)"
refresh_period="$(sed -n 's/^#define LV_DEF_REFR_PERIOD[[:space:]]\+\([0-9]\+\).*/\1/p' \
    "${PROJECT_ROOT}/config/lv_conf.h" "${PROJECT_ROOT}/external/lvgl/lv_conf_template.h" | head -1)"
OUTPUT="${OUTPUT:-${PROJECT_ROOT}/LVGL_${project_version}_benchmark.md}"

work_dir="$(mktemp -d)"
trap 'rm -rf "${work_dir}"' EXIT

# field <log> <stage> <key>: the line is selected first, then the key is read
# from it - a single pattern would need a separator before the first key.
field() {
    sed -n "/\[PERF\] stage=$2 /s/.*[[:space:]]$3=\([^[:space:]]*\).*/\1/p" "$1" | head -1
}

for run in $(seq 1 "${RUNS}"); do
    log_file="${work_dir}/run_${run}.log"
    echo "[INFO] run ${run}/${RUNS}: ${DURATION_MS} ms (driver=${VIDEO_DRIVER}, force_redraw=${FORCE_REDRAW})"
    SDL_VIDEODRIVER="${VIDEO_DRIVER}" \
        COFFEE_PERF_PROFILE=1 \
        COFFEE_PERF_FORCE_REDRAW="${FORCE_REDRAW}" \
        COFFEE_EXIT_AFTER_STARTUP_MS="${DURATION_MS}" \
        "${executable}" > "${log_file}" 2>&1

    if ! grep -q '\[PERF\] stage=summary' "${log_file}"; then
        echo "run ${run} produced no profiling output" >&2
        cat "${log_file}" >&2
        exit 1
    fi
done

# Aggregate every run into one table plus the overall figures. The helper is
# written to a file because `python3 - <<EOF` would take the script from stdin
# and leave nothing there for the data.
aggregate_script="${work_dir}/aggregate.py"
cat > "${aggregate_script}" <<'PY'
import statistics
import sys

rows = [line.split() for line in sys.stdin.read().splitlines() if line.strip()]
columns = list(zip(*[[float(cell) for cell in row] for row in rows]))


def fmt(value):
    return f"{value:.0f}" if value >= 100 else f"{value:.2f}"


print(" ".join(
    "|".join((fmt(statistics.fmean(column)), fmt(min(column)), fmt(max(column)),
              fmt(statistics.pstdev(column))))
    for column in columns
))
PY

aggregate() {
    python3 "${aggregate_script}"
}

run_table=""
render_means=""
flush_means=""
fps_values=""
frame_counts=""
for run in $(seq 1 "${RUNS}"); do
    log_file="${work_dir}/run_${run}.log"
    render_mean="$(field "${log_file}" render mean_us)"
    render_p95="$(field "${log_file}" render p95_us)"
    render_max="$(field "${log_file}" render max_us)"
    flush_mean="$(field "${log_file}" flush mean_us)"
    frames="$(field "${log_file}" summary frames)"
    fps="$(field "${log_file}" summary fps)"

    run_table+="| ${run} | ${frames} | ${render_mean} | ${render_p95} | ${render_max} | ${flush_mean} | ${fps} |"$'\n'
    render_means+="${render_mean}"$'\n'
    flush_means+="${flush_mean}"$'\n'
    fps_values+="${fps}"$'\n'
    frame_counts+="${frames}"$'\n'
done

read -r render_agg flush_agg fps_agg frames_agg <<<"$(paste -d' ' \
    <(printf '%s' "${render_means}") \
    <(printf '%s' "${flush_means}") \
    <(printf '%s' "${fps_values}") \
    <(printf '%s' "${frame_counts}") | aggregate)"

split_field() { printf '%s' "$1" | cut -d'|' -f"$2"; }

render_mean_avg="$(split_field "${render_agg}" 1)"
flush_mean_avg="$(split_field "${flush_agg}" 1)"
frame_us="$(python3 -c "print(round(float('${render_mean_avg}') + float('${flush_mean_avg}')))")"
capacity_fps="$(python3 -c "print(round(1000000 / ${frame_us}))")"

first_log="${work_dir}/run_1.log"
cpu_model="$(sed -n 's/^model name[[:space:]]*:[[:space:]]*//p' /proc/cpuinfo | head -1)"
compiler="$(cc --version | head -1)"
width="$(field "${first_log}" summary width)"
height="$(field "${first_log}" summary height)"
color_depth="$(field "${first_log}" summary color_depth)"

agg_row() {
    printf '| %s | %s | %s | %s | %s |\n' "$1" \
        "$(split_field "$2" 1)" "$(split_field "$2" 2)" "$(split_field "$2" 3)" "$(split_field "$2" 4)"
}

{
    printf '# Rendering benchmark - LVGL Coffee Dispenser %s\n\n' "${project_version}"
    printf -- '- Date: %s\n' "$(date -u '+%Y-%m-%d %H:%M:%SZ')"
    printf -- '- Application version: %s\n' "${project_version}"
    printf -- '- LVGL version: %s (software renderer, single draw unit, no GPU)\n' "${lvgl_version}"
    printf -- '- Resolution: %s x %s, LV_COLOR_DEPTH %s\n' "${width}" "${height}" "${color_depth}"
    printf -- '- SDL video driver: `%s`\n' "${VIDEO_DRIVER}"
    printf -- '- Workload: %s\n' \
        "$([[ "${FORCE_REDRAW}" -eq 1 ]] && echo 'full-screen invalidation every main-loop iteration' || echo 'idle UI, only the invalidations the application triggers itself')"
    printf -- '- Runs: %s x %s ms\n' "${RUNS}" "${DURATION_MS}"
    printf -- '- CPU: %s\n' "${cpu_model}"
    printf -- '- Compiler: %s\n' "${compiler}"
    printf -- '- Kernel: %s\n\n' "$(uname -sr)"

    printf '## Per run\n\n'
    printf '| Run | Frames | render mean (us) | render p95 (us) | render max (us) | flush mean (us) | fps |\n'
    printf '| ---: | ---: | ---: | ---: | ---: | ---: | ---: |\n'
    printf '%s\n' "${run_table}"

    printf '## Across the %s runs\n\n' "${RUNS}"
    printf '| Metric | mean | min | max | stddev |\n'
    printf '| --- | ---: | ---: | ---: | ---: |\n'
    agg_row 'render mean (us)' "${render_agg}"
    agg_row 'flush mean (us)' "${flush_agg}"
    agg_row 'frames per run' "${frames_agg}"
    agg_row 'fps' "${fps_agg}"

    printf '\nOne fully invalidated frame costs about %s us of CPU time (render + flush), which is a ' "${frame_us}"
    printf 'capacity of roughly %s frames/s. The measured frame rate is the rate LVGL asks for: it ' "${capacity_fps}"
    printf 'refreshes at most every LV_DEF_REFR_PERIOD = %s ms, so about %s frames/s is the ceiling of ' \
        "${refresh_period}" "$((1000 / refresh_period))"
    printf 'this configuration, and the difference between the two numbers is the headroom that is left '
    printf 'for application logic on a slower target.\n\n'
    printf '`render` is the LVGL software rendering of the invalidated area, `flush` is handing the '
    printf 'rendered buffer to SDL. Both are measured inside the display driver through the LVGL render '
    printf 'and flush events, so the numbers exclude the main loop delay. With the `dummy` video driver '
    printf 'no GPU or compositor is involved; use `--video-driver x11` to include the real presentation '
    printf 'path.\n\n'
    printf 'Reproduce with:\n\n'
    printf '```bash\n./scripts/run_render_benchmark.sh --runs %s --duration-ms %s%s\n```\n' \
        "${RUNS}" "${DURATION_MS}" "$([[ "${FORCE_REDRAW}" -eq 1 ]] && echo '' || echo ' --idle')"
} > "${OUTPUT}"

echo "[INFO] report written to ${OUTPUT}"
