#!/usr/bin/env bash
set -euo pipefail

if [[ $# -ne 2 ]]; then
  echo "usage: $0 <build-dir> <output-dir>" >&2
  exit 2
fi

build_dir="$1"
out_dir="$2"
exe="$build_dir/lvgl_coffee_dispenser"

if [[ ! -x "$exe" ]]; then
  echo "executable not found: $exe" >&2
  exit 1
fi

mkdir -p "$out_dir/bin" "$out_dir/docs"
cp "$exe" "$out_dir/bin/"
cp README.md "$out_dir/"
cp docs/*.md "$out_dir/docs/"

cat > "$out_dir/run.sh" <<'SCRIPT'
#!/usr/bin/env bash
set -euo pipefail
cd "$(dirname "$0")"
exec ./bin/lvgl_coffee_dispenser
SCRIPT
chmod +x "$out_dir/run.sh"

echo "packaged to $out_dir"
