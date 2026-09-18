# Build and Deploy Notes

The default host build is Linux SDL:

```bash
cmake --preset linux-debug
cmake --build --preset linux-debug
ctest --preset linux-debug
```

The preferred local validation command is:

```bash
./localPipeline.sh --no-run
```

It performs the normal build/test path plus the semantic-version check, formatting, coverage, Doxygen, and Cppcheck checks. Omit `--no-run` to include a short app smoke launch. The coverage gate requires at least 95% line coverage, and a non-empty Doxygen warning log fails the run.

## Tooling Outputs

- Formatting: non-mutating `clang-format --dry-run --Werror`.
- Coverage: `build-coverage/coverage/coverage.txt`, `summary.json`, and `html/index.html`.
- Doxygen: `build/linux-debug/doxygen/html/index.html` and `warnings.txt`.
- Cppcheck: `reports/cppcheck/cppcheck.xml` and optional `reports/cppcheck/html/index.html`.

Generated build, coverage, and report folders are ignored by git.

## Optional Manual Commands

```bash
./scripts/run_cppcheck.sh --build-dir build/linux-debug
cmake --build build/linux-debug --target doxygen
cmake --build build-coverage --target coverage-html
```

For embedded Linux, keep `src/app` and `src/service/dispenser_service.h` unchanged where possible and replace the SDL-specific LVGL display/input initialization with framebuffer, DRM/KMS, Wayland, or the target vendor driver.

Runtime packaging is intentionally simple for the prototype. `tools/package_linux.sh` copies the executable and docs into a distributable folder.

## Measurement and Media Scripts

```bash
./scripts/run_render_benchmark.sh --runs 10 --pin-cpu 0   # LVGL_<lvgl version>_benchmark.md
./scripts/record_demo_gif.sh                              # media/demo.gif, needs Xvfb and ffmpeg
```

Both drive the release build: build it with `cmake --preset linux-release && cmake --build --preset linux-release` first. The benchmark needs `--pin-cpu` on machines with frequency scaling or hybrid cores, and the GIF recorder runs the application's own scripted tour (`COFFEE_DEMO_TOUR=1`) on a private X display.
