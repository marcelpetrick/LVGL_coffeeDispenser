# AGENTS.md

This file provides guidance to coding agents (Claude Code, Codex, and friends) when working with code in this repository.

## Working Rules

Good software craftsmanship is the point of this repository, so the process is part of the deliverable:

- **Atomic commits.** One concern per commit, with a [Conventional Commits](https://www.conventionalcommits.org/) subject (`feat`, `fix`, `docs`, `test`, `ci`, `chore`, `refactor`) and a body that says *why*. A fix and the test that pins it belong together; unrelated cleanups do not.
- **Bump the version in the same commit.** See [Versioning](#versioning); the pipeline rejects a commit that does not.
- **Run the gate before committing:** `./localPipeline.sh --no-run`. Every stage has to pass, not just the tests.
- **Cover what you add.** The line-coverage gate is 95%, the suite is at 100% of `coffee_core`; keep it there. Logic worth testing belongs in `coffee_core`, not in the LVGL layer, so it stays testable without a display.
- **Fix the cause, not the symptom.** When a gate fails or a line stays uncovered, check whether the code is wrong before adjusting the test: the uncovered clamp in `sim_tick` and the unreachable p95 guard were both real defects.
- **Keep the docs in step.** README, this file, and the generated docs are part of the change, not a follow-up.

## Project

Desktop-first LVGL 9.x prototype of a touch coffee-dispenser HMI. Runs on Linux/SDL2 against a simulated dispenser backend, but the layering is meant to keep the controller and beverage model portable to embedded targets.

The LVGL sources live in `external/lvgl` as a git submodule and must be initialized before configuring:

```bash
git submodule update --init --recursive
```

## Versioning

`project(... VERSION <major>.<minor>.<patch>)` in `CMakeLists.txt` is the single source of truth. It is injected into the build as the `COFFEE_APP_VERSION` compile definition and into the generated docs as the Doxygen `PROJECT_NUMBER`.

Strict semantic versioning applies, starting from the `0.1.0` baseline:

- **every commit** bumps at least the **patch** level, in the same commit as the change itself;
- a notable feature bumps the **minor** level and resets the patch level to `0`;
- the **major** level is bumped **only** when the repository owner explicitly asks for it.

`localPipeline.sh` enforces this in its `Version` stage: the version must be a valid `MAJOR.MINOR.PATCH` triple and must be strictly greater than the baseline version (the version at `HEAD` when the working tree is dirty, otherwise the version at `HEAD~1`).

Releases are cut by tagging `v<version>`; the release workflow refuses a tag that disagrees with `CMakeLists.txt`.

## Common Commands

Configure + build (preferred path uses presets):

```bash
cmake --preset linux-debug          # or linux-release
cmake --build --preset linux-debug
```

Both presets enable `COFFEE_BUILD_TESTS=ON` and force `COFFEE_BACKEND=SDL` — the CMake script `FATAL_ERROR`s on any other backend, even though `FBDEV`/`DRM` are listed as cache options.

Run the simulator:

```bash
./build/linux-debug/lvgl_coffee_dispenser
```

Headless smoke run (used by the `app_startup_smoke` CTest case): set `SDL_VIDEODRIVER=dummy` and `COFFEE_EXIT_AFTER_STARTUP_MS=<ms>` so `main.c` exits after the runtime timer elapses instead of waiting on a window-close event.

Tests:

```bash
ctest --preset linux-debug                                         # all tests
ctest --preset linux-debug -R beverage_model --output-on-failure   # single test by name
ctest --test-dir build/linux-debug -R app_controller -V            # alternative
```

Registered tests are `beverage_model`, `app_controller`, `perf_stats`, `sim_dispenser_service`, and `app_startup_smoke` (see `tests/CMakeLists.txt`). The first four link `coffee_core` only, so they stay display-independent; the last one starts the real binary headlessly.

Note that `ctest` may resolve to a pip-installed shim without the `cmake` module; use `/usr/bin/ctest` when that happens (the pipeline resolves the binary next to `cmake` by itself).

Full local validation (this is the canonical pre-commit gate, not just `ctest`):

```bash
./localPipeline.sh --no-run         # skip the final smoke launch
./localPipeline.sh --verbose        # surface command output for every stage
```

The pipeline runs: submodule init → version gate → configure → build → ctest → `clang-format --dry-run --Werror` → coverage build + report → Doxygen → Cppcheck → optional smoke launch. **It enforces a 95% line-coverage gate** (`COVERAGE_MIN_LINE_PERCENT` in `localPipeline.sh`) — dropping below the threshold fails the pipeline. `tools/full_check.sh` runs the same pipeline with `--no-run` forced.

Every tool the pipeline touches is a hard requirement; a missing one aborts before the first stage: `git`, `cmake`, `clang-format`, `cppcheck`, `doxygen`, `gcov`, `gcovr`, `python3`, `timeout`.

Coverage uses a **separate build directory** so debug and coverage objects do not collide:

```bash
cmake -S . -B build-coverage -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug -DCOFFEE_BACKEND=SDL \
  -DCOFFEE_BUILD_TESTS=ON -DCOFFEE_ENABLE_COVERAGE=ON
cmake --build build-coverage --target coverage-html
```

The `coverage` / `coverage-html` targets only exist when `gcovr` is found at configure time; both build the test executables, run CTest, and write `build-coverage/coverage/{coverage.txt,summary.json,html/index.html}`. Counter files from an older compiler make gcov fail with a version mismatch - the pipeline deletes stale `*.gcda` for that reason; do the same by hand when running the targets directly.

Static analysis and docs (both also run inside the pipeline):

```bash
./scripts/run_cppcheck.sh --build-dir build/linux-debug   # reports/cppcheck/{cppcheck.xml,html/}
cmake --build build/linux-debug --target doxygen          # non-empty warnings.txt fails the pipeline
```

Formatting check used by CI/local pipeline:

```bash
find config src tests -type f \( -name '*.c' -o -name '*.h' \) -print \
  | xargs clang-format --dry-run --Werror
```

`.clang-format` is LLVM-based with `ColumnLimit: 100`, `IndentWidth: 4`, Linux braces, right-aligned pointers.

Packaging a runnable folder (used by the release workflow):

```bash
./tools/package_linux.sh build/linux-release dist/lvgl_coffee_dispenser
```

## Rendering Benchmark

The binary profiles its own rendering when the environment asks for it, which keeps the normal run free of instrumentation:

```bash
COFFEE_PERF_PROFILE=1 COFFEE_PERF_FORCE_REDRAW=1 COFFEE_EXIT_AFTER_STARTUP_MS=10000 \
  SDL_VIDEODRIVER=dummy ./build/linux-release/lvgl_coffee_dispenser

./scripts/run_render_benchmark.sh --runs 10              # repeated runs, plus a Markdown report
```

`src/ui/perf_probe.c` hooks `LV_EVENT_RENDER_START/READY` and `LV_EVENT_FLUSH_START/FINISH`, the percentile math is `src/platform/perf_stats.c` in `coffee_core` (and therefore unit-tested). The report lands in `LVGL_<version>_benchmark.md` and covers ten runs, so the spread is visible; keep the latest one committed, drop the superseded one, and reference it from the README. Measured FPS is capped by `LV_DEF_REFR_PERIOD` (33 ms), so the meaningful number is the per-frame render + flush cost.

## Demo Recording

`src/ui/demo_tour.c` clicks through the UI on a timer when `COFFEE_DEMO_TOUR=1` is set. Steps name the caption of the control they activate, so the script follows the widgets rather than pixel coordinates; a caption that is not on the active screen is logged and skipped. `scripts/record_demo_gif.sh` runs that tour on a private Xvfb display and turns the capture into `media/demo.gif`, which the README embeds. Re-record it when the UI changes visibly.

## Continuous Integration

`.github/workflows/ci.yml` runs the same `./localPipeline.sh --no-run --verbose` on every push/PR, so a green local pipeline is the best predictor of a green CI run. `.github/workflows/release.yml` is tag-driven (`v*`) and publishes the packaged Linux build plus the Doxygen HTML. Both check out submodules and full history (the version gate needs `HEAD~1`).

## Architecture

The project intentionally splits along layers so the simulated backend and SDL frontend can be replaced without touching the core. The **rule** documented in `docs/architecture.md` is: the UI only requests state changes through `app_controller`; the controller is the only thing that talks to a `coffee_dispenser_service_t`.

```
src/main.c          SDL bring-up, lv_init, tick loop, env-driven exit timer
src/app/            beverage_model + app_controller state machine (HW-independent)
src/service/        coffee_dispenser_service_t vtable + sim_dispenser_service
src/ui/             ui_manager + ui_theme + perf_probe + demo_tour + screens/* (LVGL)
src/platform/       platform_log, platform_time, perf_stats (percentile math)
config/             app_config.h (timings, default 800x480) + lv_conf.h
docs/               architecture.md, ui-flow.md, build-and-deploy.md
tools/, scripts/    packaging wrapper, Cppcheck driver, render benchmark
external/lvgl/      submodule, built via add_subdirectory
```

Screens are `home`, `beverage`, `dispense`, `error`, `settings`, `diagnostics` (compiled in via `COFFEE_ENABLE_DIAGNOSTICS`), and `showcase` — the last one is a pure LVGL widget gallery including the virtual keyboard, useful for eyeballing theming changes.

State machine (`src/app/app_state.h`): `BOOTING → READY → BEVERAGE_SELECTED → CONFIRMING → DISPENSING → {COMPLETED, CANCELLED, ERROR} → READY`, plus `MAINTENANCE` and `SHUTDOWN`. The controller validates the request, asks the service `can_dispense`, only enters `DISPENSING` after the service acknowledges `start`, and maps `coffee_dispense_snapshot_t` progress into the visible state. UI flow in `docs/ui-flow.md`.

The dispenser service is a vtable struct (`src/service/dispenser_service.h`) — `init`, `machine_snapshot`, `can_dispense`, `start`, `cancel`, `dispense_snapshot`, `tick`. To add a real backend, implement these and hand a populated `coffee_dispenser_service_t` to `coffee_app_controller_init`. `sim_dispenser_service` is the only implementation today.

Beverages are static metadata in `src/app/beverage_model.c` (`COFFEE_BEV_*` enum, including `HOT_WATER` modeled as a regular beverage with stricter copy). Sizes/shots/milk/water variants are encoded as `coffee_beverage_option_t`; each beverage advertises which options it supports.

CMake split: `coffee_core` static library holds everything HW-independent (used by tests). The `lvgl_coffee_dispenser` executable adds `main.c`, `ui/`, screens, and links SDL2 + LVGL. Tests link only `coffee_core` so they stay display-independent.

Build-time options (top of `CMakeLists.txt`):

- `COFFEE_BUILD_TESTS` (default ON)
- `COFFEE_ENABLE_COVERAGE` (default OFF; requires GCC/Clang and `COFFEE_BUILD_TESTS=ON`)
- `COFFEE_ENABLE_DIAGNOSTICS` (default ON; surfaces the diagnostics screen)
- `COFFEE_ENABLE_FILE_LOGGING` (default OFF)
- `COFFEE_BACKEND` (cache options `SDL`/`FBDEV`/`DRM`, but only `SDL` is implemented)
- `COFFEE_DEFAULT_WIDTH` / `COFFEE_DEFAULT_HEIGHT` (default 800x480)

Timings (`config/app_config.h`): `COFFEE_SPLASH_MS`, `COFFEE_COMPLETION_MS`, `COFFEE_CANCELLED_MS`, `COFFEE_TICK_MS`.

When porting to embedded Linux, keep `src/app` and `src/service/dispenser_service.h` stable and replace `src/main.c` SDL bring-up plus the simulated service.
