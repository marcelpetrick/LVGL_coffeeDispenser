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
sudo apt install -y build-essential cmake ninja-build pkg-config libsdl2-dev git
```

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

## Full Check

Run the full local validation script:

```bash
./tools/full_check.sh
```

It initializes submodules, configures, builds, runs tests, and runs a `clang-format` dry-run when `clang-format` is available.

## Package

```bash
./tools/package_linux.sh build/linux-release dist/lvgl-coffee-dispenser-linux-x86_64
```

## Embedded Path

The desktop SDL integration is isolated to `src/main.c` and the LVGL configuration. Real hardware work should add a backend under `src/platform` and keep dispenser hardware behind `src/service/dispenser_service.h`. The controller and beverage model are display-independent and covered by unit tests.
