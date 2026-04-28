# LVGL Coffee Dispenser HMI

This repository contains a desktop-first LVGL prototype for a touch-based coffee dispenser HMI. It is a test project and software-engineering exercise: the current implementation runs on Linux with SDL2 and a simulated dispenser backend, while the code is structured so application logic, UI, service abstraction, platform helpers, tests, and tooling stay separated.

Author: mail@marcelpetrick.it  
License: GPLv3, see `LICENSE`

## Project Overview

The application demonstrates a coffee-machine user interface with beverage selection, confirmation, dispensing progress, completion, cancellation, settings, diagnostics, and error handling. It uses LVGL 9.x for the UI, CMake for builds, CTest for tests, gcov/gcovr for coverage, Doxygen for generated documentation, clang-format for formatting checks, and Cppcheck for static analysis.

The default target is a Linux x86_64 desktop simulator with an 800 x 480 SDL window. Mouse input is used as touch input during simulation.

## Current State

- Given: LVGL desktop simulator using the SDL backend and a default 800 x 480 layout.
- Given: beverage workflows for Coffee, Espresso, Latte Macchiato, Cappuccino, Americano, and Hot Water.
- Given: simulated dispenser service with controller state-machine logic and unit tests.
- Given: local engineering pipeline for build, test, formatting, coverage, Doxygen, Cppcheck, and smoke launch.
- Not given: integration with real pumps, valves, heaters, grinders, milk systems, sensors, or appliance safety logic.
- Not given: production features such as payment, cloud connectivity, user accounts, localization beyond the prototype scope, or certified embedded deployment.

![](media/currentState.png)

## Dependencies

On Debian/Ubuntu-like systems:

```bash
sudo apt update
sudo apt install -y \
  build-essential \
  clang-format \
  cmake \
  cppcheck \
  doxygen \
  gcovr \
  graphviz \
  ninja-build \
  pkg-config \
  libsdl2-dev \
  git
```

`cppcheck-htmlreport` is optional. When available, the static-analysis script also writes an HTML report.

Initialize the LVGL submodule after cloning:

```bash
git submodule update --init --recursive
```

## Build

Configure and build the default debug preset:

```bash
cmake --preset linux-debug
cmake --build --preset linux-debug
```

Equivalent manual command:

```bash
cmake -S . -B build/linux-debug -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCOFFEE_BACKEND=SDL \
  -DCOFFEE_BUILD_TESTS=ON
cmake --build build/linux-debug
```

The release preset is also available:

```bash
cmake --preset linux-release
cmake --build --preset linux-release
```

## Run

Run the desktop simulator:

```bash
./build/linux-debug/lvgl_coffee_dispenser
```

For a headless smoke run, SDL can use the dummy video backend:

```bash
SDL_VIDEODRIVER=dummy timeout 5s ./build/linux-debug/lvgl_coffee_dispenser
```

## Test

Run the registered CTest suite:

```bash
ctest --preset linux-debug
```

The current tests cover the beverage model, controller state transitions, and a startup smoke path. The project intentionally keeps tests independent from real coffee-machine hardware.

## Local Pipeline

The preferred local validation command is:

```bash
./localPipeline.sh --no-run
```

The local pipeline performs:

- git submodule initialization
- CMake configure with the selected preset
- build
- CTest execution
- non-mutating clang-format check
- coverage build and coverage report generation
- coverage gate with an 80% line-coverage threshold
- Doxygen documentation generation
- Cppcheck static analysis
- optional short application smoke launch

Useful options:

```bash
./localPipeline.sh --help
./localPipeline.sh --no-run
./localPipeline.sh --verbose
./localPipeline.sh --preset linux-debug
```

`tools/full_check.sh` is kept as a compatibility wrapper around the local pipeline.

## Software Engineering Tooling

Formatting is checked without modifying files:

```bash
find config src tests -type f \( -name '*.c' -o -name '*.h' \) -print \
  | xargs clang-format --dry-run --Werror
```

Static analysis uses the CMake compilation database:

```bash
cmake --preset linux-debug
./scripts/run_cppcheck.sh --build-dir build/linux-debug
```

Cppcheck reports are written to:

- `reports/cppcheck/cppcheck.xml`
- `reports/cppcheck/html/index.html` when HTML report generation is available

Doxygen API documentation can be generated with:

```bash
cmake --build build/linux-debug --target doxygen
```

Doxygen output is written to:

- `build/linux-debug/doxygen/html/index.html`
- `build/linux-debug/doxygen/warnings.txt`

The pipeline treats non-empty Doxygen warnings as a failure.

## Coverage

Coverage is opt-in and uses `gcov` plus `gcovr`:

```bash
cmake -S . -B build-coverage -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCOFFEE_BACKEND=SDL \
  -DCOFFEE_BUILD_TESTS=ON \
  -DCOFFEE_ENABLE_COVERAGE=ON
cmake --build build-coverage
cmake --build build-coverage --target coverage-html
```

Coverage reports are written to:

- `build-coverage/coverage/coverage.txt`
- `build-coverage/coverage/summary.json`
- `build-coverage/coverage/html/index.html`

The local pipeline currently requires at least 80% line coverage.

## Package

Create a simple Linux runtime package from a release build:

```bash
cmake --preset linux-release
cmake --build --preset linux-release
./tools/package_linux.sh build/linux-release dist/lvgl-coffee-dispenser-linux-x86_64
```

## Architecture Notes

The SDL desktop integration is isolated from the core application logic. The controller and beverage model are display-independent and covered by tests. Future embedded work should keep `src/app` and `src/service/dispenser_service.h` stable where possible, then replace the simulated service and SDL-specific platform code with target-specific hardware and LVGL display/input integration.

Related documentation:

- `documents/00_requirements.md`
- `docs/architecture.md`
- `docs/ui-flow.md`
- `docs/build-and-deploy.md`
