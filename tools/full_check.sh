#!/usr/bin/env bash
set -euo pipefail

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
repo_dir="$(cd "$script_dir/.." && pwd)"
preset="${1:-linux-debug}"

cd "$repo_dir"

echo "==> checking submodules"
git submodule update --init --recursive

echo "==> configuring: $preset"
cmake --preset "$preset"

echo "==> building: $preset"
cmake --build --preset "$preset"

echo "==> running tests: $preset"
ctest_bin="$(dirname "$(command -v cmake)")/ctest"
if [[ ! -x "$ctest_bin" ]]; then
  ctest_bin="$(command -v ctest)"
fi
"$ctest_bin" --preset "$preset"

if command -v clang-format >/dev/null 2>&1; then
  echo "==> checking clang-format"
  mapfile -t sources < <(find src tests config -type f \( -name '*.c' -o -name '*.h' \) -print)
  if ((${#sources[@]})); then
    clang-format --dry-run --Werror "${sources[@]}"
  fi
else
  echo "==> clang-format not found; skipping format check"
fi

echo "==> full check passed"
