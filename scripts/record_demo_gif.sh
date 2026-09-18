#!/usr/bin/env bash
# Record the scripted UI tour as an animated GIF for the README.
#
# The application runs on its own Xvfb display, so the recording is independent
# of the desktop session and reproducible on a build machine. The tour itself is
# driven from inside the application (COFFEE_DEMO_TOUR), which needs no input
# injection tooling.
set -euo pipefail

SCRIPT_NAME="$(basename "$0")"
PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"

BUILD_DIR="${PROJECT_ROOT}/build/linux-release"
OUTPUT="${PROJECT_ROOT}/media/demo.gif"
DURATION_S=11
FPS=10
DISPLAY_NUM=":97"
WIDTH=800
HEIGHT=480
GIF_WIDTH=640
MAX_COLORS=96

print_usage() {
    cat <<EOF
Usage: ${SCRIPT_NAME} [options]

Options:
  --build-dir PATH   Directory holding lvgl_coffee_dispenser; default: build/linux-release
  --output FILE      GIF to write; default: media/demo.gif
  --duration-s S     Recording length; default: ${DURATION_S}
  --fps N            GIF frame rate; default: ${FPS}
  --gif-width PX     Width of the produced GIF; default: ${GIF_WIDTH}
  --display NUM      X display for Xvfb; default: ${DISPLAY_NUM}
  --help, -h         Show this help
EOF
}

while [[ "$#" -gt 0 ]]; do
    case "$1" in
        --build-dir) shift; BUILD_DIR="$1" ;;
        --output) shift; OUTPUT="$1" ;;
        --duration-s) shift; DURATION_S="$1" ;;
        --fps) shift; FPS="$1" ;;
        --gif-width) shift; GIF_WIDTH="$1" ;;
        --display) shift; DISPLAY_NUM="$1" ;;
        --help|-h) print_usage; exit 0 ;;
        *) echo "Unknown argument: $1" >&2; print_usage; exit 2 ;;
    esac
    shift
done

for tool in Xvfb ffmpeg; do
    if ! command -v "${tool}" >/dev/null 2>&1; then
        echo "required tool not found: ${tool}" >&2
        exit 1
    fi
done

executable="${BUILD_DIR}/lvgl_coffee_dispenser"
if [[ ! -x "${executable}" ]]; then
    echo "executable not found: ${executable}" >&2
    exit 1
fi

work_dir="$(mktemp -d)"
xvfb_pid=""
app_pid=""
cleanup() {
    [[ -n "${app_pid}" ]] && kill "${app_pid}" 2>/dev/null || true
    [[ -n "${xvfb_pid}" ]] && kill "${xvfb_pid}" 2>/dev/null || true
    rm -rf "${work_dir}"
}
trap cleanup EXIT

echo "[INFO] starting Xvfb on ${DISPLAY_NUM} (${WIDTH}x${HEIGHT})"
Xvfb "${DISPLAY_NUM}" -screen 0 "${WIDTH}x${HEIGHT}x24" -nolisten tcp >"${work_dir}/xvfb.log" 2>&1 &
xvfb_pid=$!
for _ in $(seq 1 50); do
    if DISPLAY="${DISPLAY_NUM}" xdpyinfo >/dev/null 2>&1; then
        break
    fi
    sleep 0.1
done

echo "[INFO] starting the application with the scripted demo tour"
DISPLAY="${DISPLAY_NUM}" SDL_VIDEODRIVER=x11 COFFEE_DEMO_TOUR=1 \
    COFFEE_EXIT_AFTER_STARTUP_MS="$((DURATION_S * 1000 + 1500))" \
    "${executable}" >"${work_dir}/app.log" 2>&1 &
app_pid=$!
sleep 1

echo "[INFO] recording ${DURATION_S} s at ${FPS} fps"
ffmpeg -loglevel error -y -f x11grab -framerate "${FPS}" -video_size "${WIDTH}x${HEIGHT}" \
    -i "${DISPLAY_NUM}" -t "${DURATION_S}" "${work_dir}/demo.mp4"

wait "${app_pid}" 2>/dev/null || true
app_pid=""

echo "[INFO] converting to GIF"
mkdir -p "$(dirname "${OUTPUT}")"
# The cross-fades touch nearly every pixel, so a downscaled frame and a small
# palette keep the file in a size a README can carry.
ffmpeg -loglevel error -y -i "${work_dir}/demo.mp4" \
    -vf "fps=${FPS},scale=${GIF_WIDTH}:-1:flags=lanczos,palettegen=max_colors=${MAX_COLORS}:stats_mode=diff" \
    "${work_dir}/palette.png"
ffmpeg -loglevel error -y -i "${work_dir}/demo.mp4" -i "${work_dir}/palette.png" \
    -lavfi "fps=${FPS},scale=${GIF_WIDTH}:-1:flags=lanczos[x];[x][1:v]paletteuse=dither=bayer:bayer_scale=5:diff_mode=rectangle" \
    "${OUTPUT}"

echo "[INFO] wrote ${OUTPUT} ($(du -h "${OUTPUT}" | cut -f1))"
