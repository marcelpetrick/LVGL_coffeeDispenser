# AGENTS.md

This file provides guidance to coding agents (Claude Code, Codex, and friends) when working with code in this repository.

## Project

Desktop-first LVGL 9.x prototype of a touch coffee-dispenser HMI. Runs on Linux/SDL2 against a simulated dispenser backend, but the layering is meant to keep the controller and beverage model portable to embedded targets.

The LVGL sources live in `external/lvgl` as a git submodule and must be initialized before configuring:

```bash
git submodule update --init --recursive
```

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

Registered tests are `beverage_model`, `app_controller`, and `app_startup_smoke` (see `tests/CMakeLists.txt`).

Full local validation (this is the canonical pre-commit gate, not just `ctest`):

```bash
./localPipeline.sh --no-run         # skip the final smoke launch
./localPipeline.sh --verbose        # surface command output for every stage
```

The pipeline runs: submodule init → configure → build → ctest → `clang-format --dry-run --Werror` → coverage build + report → Doxygen → Cppcheck → optional smoke launch. **It enforces an 80% line-coverage gate** (`COVERAGE_MIN_LINE_PERCENT` in `localPipeline.sh`) — dropping below the threshold fails the pipeline. `tools/full_check.sh` is just a wrapper around it.

Coverage uses a **separate build directory** so debug and coverage objects do not collide:

```bash
cmake -S . -B build-coverage -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug -DCOFFEE_BACKEND=SDL \
  -DCOFFEE_BUILD_TESTS=ON -DCOFFEE_ENABLE_COVERAGE=ON
cmake --build build-coverage --target coverage-html
```

Static analysis and docs (both also run inside the pipeline):

```bash
./scripts/run_cppcheck.sh --build-dir build/linux-debug
cmake --build build/linux-debug --target doxygen   # non-empty warnings.txt fails the pipeline
```

Formatting check used by CI/local pipeline:

```bash
find config src tests -type f \( -name '*.c' -o -name '*.h' \) -print \
  | xargs clang-format --dry-run --Werror
```

`.clang-format` is LLVM-based with `ColumnLimit: 100`, `IndentWidth: 4`, Linux braces, right-aligned pointers.

## Architecture

The project intentionally splits along layers so the simulated backend and SDL frontend can be replaced without touching the core. The **rule** documented in `docs/architecture.md` is: the UI only requests state changes through `app_controller`; the controller is the only thing that talks to a `coffee_dispenser_service_t`.

```
src/main.c          SDL bring-up, lv_init, tick loop, env-driven exit timer
src/app/            beverage_model + app_controller state machine (HW-independent)
src/service/        coffee_dispenser_service_t vtable + sim_dispenser_service
src/ui/             ui_manager + screens/* (LVGL widgets only)
src/platform/       platform_log, platform_time wrappers
config/             app_config.h (timings, default 800x480) + lv_conf.h
external/lvgl/      submodule, built via add_subdirectory
```

State machine (`src/app/app_state.h`): `BOOTING → READY → BEVERAGE_SELECTED → CONFIRMING → DISPENSING → {COMPLETED, CANCELLED, ERROR} → READY`, plus `MAINTENANCE` and `SHUTDOWN`. The controller validates the request, asks the service `can_dispense`, only enters `DISPENSING` after the service acknowledges `start`, and maps `coffee_dispense_snapshot_t` progress into the visible state. UI flow in `docs/ui-flow.md`.

The dispenser service is a vtable struct (`src/service/dispenser_service.h`) — `init`, `machine_snapshot`, `can_dispense`, `start`, `cancel`, `dispense_snapshot`, `tick`. To add a real backend, implement these and hand a populated `coffee_dispenser_service_t` to `coffee_app_controller_init`. `sim_dispenser_service` is the only implementation today.

Beverages are static metadata in `src/app/beverage_model.c` (`COFFEE_BEV_*` enum, including `HOT_WATER` modeled as a regular beverage with stricter copy). Sizes/shots/milk/water variants are encoded as `coffee_beverage_option_t`; each beverage advertises which options it supports.

CMake split: `coffee_core` static library holds everything HW-independent (used by tests). The `lvgl_coffee_dispenser` executable adds `main.c`, `ui/`, screens, and links SDL2 + LVGL. Tests link only `coffee_core` so they stay display-independent.

Build-time options (top of `CMakeLists.txt`):

- `COFFEE_BUILD_TESTS` (default ON)
- `COFFEE_ENABLE_COVERAGE` (default OFF; requires GCC/Clang and `COFFEE_BUILD_TESTS=ON`)
- `COFFEE_ENABLE_DIAGNOSTICS` (default ON; surfaces the diagnostics screen)
- `COFFEE_ENABLE_FILE_LOGGING` (default OFF)
- `COFFEE_DEFAULT_WIDTH` / `COFFEE_DEFAULT_HEIGHT` (default 800x480)

When porting to embedded Linux, keep `src/app` and `src/service/dispenser_service.h` stable and replace `src/main.c` SDL bring-up plus the simulated service.
