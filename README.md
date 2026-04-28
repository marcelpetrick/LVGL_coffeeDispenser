# LVGL Coffee Dispenser HMI

Desktop-first LVGL prototype for a touch coffee dispenser. The current build targets Linux x86_64 with SDL2 and a simulated dispenser backend, while keeping the UI, controller, model, service, and platform code separated for later embedded deployment.

## Features

- LVGL 9.x desktop simulator window at 800 x 480 by default.
- Home screen with Coffee, Espresso, Latte Macchiato, Cappuccino, Americano, and a dedicated Hot Water workflow.
- Beverage confirmation, simulated dispensing progress, completion, cancellation, and error screens.
- Settings and diagnostics screens enabled for the prototype.
- Unit tests for beverage model rules and state-machine transitions.

## Dependencies

Debian/Ubuntu-like systems:

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

`cppcheck-htmlreport` is optional but recommended; when present it generates an HTML static-analysis report.

Initialize dependencies after cloning:

```bash
git submodule update --init --recursive
```

## Build

```bash
cmake --preset linux-debug
cmake --build --preset linux-debug
```

Manual equivalent:

```bash
cmake -S . -B build/linux-debug -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCOFFEE_BACKEND=SDL
cmake --build build/linux-debug
```

## Run

```bash
./build/linux-debug/lvgl_coffee_dispenser
```

Mouse input simulates touch input.

## Test

```bash
ctest --preset linux-debug
```

The registered tests include unit tests for the beverage model and controller plus a headless SDL startup smoke test.

## Local Pipeline

Run the full local validation pipeline:

```bash
./localPipeline.sh --no-run
```

The pipeline initializes submodules, configures, builds, runs CTest, checks formatting without editing files, builds coverage, enforces the coverage gate, generates Doxygen docs, runs Cppcheck, and optionally launches the app briefly.

Useful options:

```bash
./localPipeline.sh --help
./localPipeline.sh --no-run
./localPipeline.sh --verbose
./localPipeline.sh --preset linux-debug
```

`tools/full_check.sh` is kept as a compatibility wrapper around `localPipeline.sh --no-run`.

## Formatting

The repository uses `.clang-format`. Check formatting:

```bash
find config src tests -type f \( -name '*.c' -o -name '*.h' \) -print \
  | xargs clang-format --dry-run --Werror
```

Apply formatting:

```bash
find config src tests -type f \( -name '*.c' -o -name '*.h' \) -print \
  | xargs clang-format -i
```

## Static Analysis

Cppcheck uses the CMake compilation database:

```bash
cmake --preset linux-debug
./scripts/run_cppcheck.sh --build-dir build/linux-debug
```

Reports:

- `reports/cppcheck/cppcheck.xml`
- `reports/cppcheck/html/index.html` when `cppcheck-htmlreport` is available

## Documentation

Generate Doxygen HTML documentation:

```bash
cmake --preset linux-debug
cmake --build build/linux-debug --target doxygen
```

Reports:

- `build/linux-debug/doxygen/html/index.html`
- `build/linux-debug/doxygen/warnings.txt`

The local pipeline treats non-empty Doxygen warnings as a failure.

## Coverage

Coverage is opt-in and uses `gcov`/`gcovr`:

```bash
cmake -S . -B build-coverage -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCOFFEE_BACKEND=SDL \
  -DCOFFEE_BUILD_TESTS=ON \
  -DCOFFEE_ENABLE_COVERAGE=ON
cmake --build build-coverage
cmake --build build-coverage --target coverage-html
```

Reports:

- `build-coverage/coverage/coverage.txt`
- `build-coverage/coverage/summary.json`
- `build-coverage/coverage/html/index.html`

The current local pipeline gate requires at least 80% line coverage.

## Package

```bash
./tools/package_linux.sh build/linux-release dist/lvgl-coffee-dispenser-linux-x86_64
```

## Embedded Path

The desktop SDL integration is isolated to `src/main.c` and the LVGL configuration. Real hardware work should add a backend under `src/platform` and keep dispenser hardware behind `src/service/dispenser_service.h`. The controller and beverage model are display-independent and covered by unit tests.
