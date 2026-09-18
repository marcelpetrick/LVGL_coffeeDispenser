# LVGL Coffee Dispenser HMI

[![CI](https://github.com/marcelpetrick/LVGL_coffeeDispenser/actions/workflows/ci.yml/badge.svg)](https://github.com/marcelpetrick/LVGL_coffeeDispenser/actions/workflows/ci.yml)
[![Release](https://github.com/marcelpetrick/LVGL_coffeeDispenser/actions/workflows/release.yml/badge.svg)](https://github.com/marcelpetrick/LVGL_coffeeDispenser/actions/workflows/release.yml)
[![License: GPL v3 or later](https://img.shields.io/badge/license-GPLv3%20or%20later-blue.svg)](LICENSE)
[![LVGL 9.3.0](https://img.shields.io/badge/LVGL-9.3.0-4c9a2a.svg)](https://lvgl.io/)
[![SDL 2](https://img.shields.io/badge/SDL-2-1d4e89.svg)](https://www.libsdl.org/)
[![CMake 3.30+](https://img.shields.io/badge/CMake-3.30%2B-064f8c.svg)](https://cmake.org/)
[![C23](https://img.shields.io/badge/C-23-00599c.svg)](https://en.cppreference.com/w/c/23)
[![Coverage 82.9%](https://img.shields.io/badge/coverage-82.9%25-brightgreen.svg)](#quality-gate)
[![Platform: Linux x86-64](https://img.shields.io/badge/platform-Linux%20x86--64-lightgrey.svg)](#quick-start)
[![SemVer](https://img.shields.io/badge/semver-0.3.5-orange.svg)](#versioning)

A desktop-first LVGL prototype of a touch coffee-dispenser HMI: beverage selection, confirmation, dispensing progress, completion, cancellation, settings, diagnostics, and error handling. It runs on Linux/SDL2 against a simulated dispenser backend, with application logic, UI, service abstraction, platform helpers, tests, and tooling kept in separate layers.

**Author: Marcel Petrick <mail@marcelpetrick.it>**

**Note: projected is generated with AI.**

**License: GPLv3 or later. See [LICENSE](LICENSE).**

![](media/currentState.png)

### View to showcase available LVGL elements for a quick preview & test
![](media/currentState_ui_elements_view.png)

## Scope

| Included | Not included |
| --- | --- |
| SDL desktop simulator, 800 x 480, mouse as touch | Real pumps, valves, heaters, grinders, milk systems, sensors |
| Beverages: Coffee, Espresso, Latte Macchiato, Cappuccino, Americano, Hot Water | Appliance safety logic and certification |
| Simulated dispenser service behind a vtable, unit-tested controller state machine | Payment, cloud connectivity, user accounts |
| Local pipeline: build, test, format, coverage, Doxygen, Cppcheck, smoke launch | Localization beyond the prototype scope |

## Quick Start

Dependencies on Debian/Ubuntu-like systems (`cppcheck-htmlreport` is optional and only adds an HTML report):

```bash
sudo apt update
sudo apt install -y build-essential clang-format cmake cppcheck doxygen gcovr \
  graphviz ninja-build pkg-config libsdl2-dev git
```

Clone, build, run:

```bash
git submodule update --init --recursive
cmake --preset linux-debug            # or linux-release
cmake --build --preset linux-debug
./build/linux-debug/lvgl_coffee_dispenser
```

Headless run, e.g. for a smoke test:

```bash
SDL_VIDEODRIVER=dummy timeout 5s ./build/linux-debug/lvgl_coffee_dispenser
```

## Quality Gate

`localPipeline.sh` is the canonical gate; CI runs exactly the same script. It performs submodule init, the semantic-version check, configure, build, CTest, a non-mutating `clang-format` check, the coverage build with an **80% line-coverage threshold**, Doxygen with an empty-warning-log requirement, Cppcheck, and an optional smoke launch.

```bash
./localPipeline.sh --no-run          # skip the final smoke launch
./localPipeline.sh --verbose         # show the output of every stage
./localPipeline.sh --help            # all options
```

`tools/full_check.sh` is a compatibility wrapper that always adds `--no-run`.

The individual steps, should one of them need to be run alone:

```bash
ctest --preset linux-debug                                 # unit + smoke tests
find config src tests -type f \( -name '*.c' -o -name '*.h' \) -print \
  | xargs clang-format --dry-run --Werror                  # formatting
./scripts/run_cppcheck.sh --build-dir build/linux-debug    # static analysis
cmake --build build/linux-debug --target doxygen           # API documentation
cmake -S . -B build-coverage -G Ninja -DCMAKE_BUILD_TYPE=Debug \
  -DCOFFEE_BACKEND=SDL -DCOFFEE_BUILD_TESTS=ON -DCOFFEE_ENABLE_COVERAGE=ON
cmake --build build-coverage --target coverage-html        # coverage
```

Generated output:

| What | Where |
| --- | --- |
| Coverage | `build-coverage/coverage/{coverage.txt,summary.json,html/index.html}` |
| Doxygen | `build/linux-debug/doxygen/html/index.html`, `warnings.txt` |
| Cppcheck | `reports/cppcheck/cppcheck.xml`, `reports/cppcheck/html/index.html` |

The last local run reported 82.9% line, 88.2% function, and 66.9% branch coverage.

## Versioning

Semantic versioning, with `project(... VERSION <major>.<minor>.<patch>)` in `CMakeLists.txt` as the single source of truth: it is compiled in as `COFFEE_APP_VERSION` and used as the Doxygen `PROJECT_NUMBER`.

- Every commit bumps at least the patch level.
- A notable feature bumps the minor level.
- The major level is bumped on explicit request only.

The pipeline enforces this: the version must be a valid `MAJOR.MINOR.PATCH` triple and greater than the baseline - the version at `HEAD` for a dirty working tree, at `HEAD~1` for a clean one.

## CI and Releases

- [`ci.yml`](.github/workflows/ci.yml) runs `./localPipeline.sh --no-run --verbose` on Ubuntu 24.04 for every push and pull request and uploads the coverage, Doxygen, and Cppcheck reports.
- [`release.yml`](.github/workflows/release.yml) reacts to a `v*` tag: it checks the tag against the project version, runs the same pipeline, builds the release preset, packages the build, starts the packaged binary headlessly, and publishes the archives.

```bash
git tag v0.3.5     # must equal the version in CMakeLists.txt
git push origin v0.3.5
```

A package can also be built locally:

```bash
cmake --preset linux-release
cmake --build --preset linux-release
./tools/package_linux.sh build/linux-release dist/lvgl-coffee-dispenser-linux-x86_64
```

## Architecture

The SDL integration is isolated from the core: the UI only requests state changes through `app_controller`, and the controller is the only component talking to a `coffee_dispenser_service_t`. Controller and beverage model are display-independent and unit-tested, so an embedded port keeps `src/app` and `src/service/dispenser_service.h` and replaces `src/main.c` plus the simulated service.

```
src/main.c        SDL bring-up, lv_init, tick loop
src/app/          beverage model + controller state machine (hardware-independent)
src/service/      dispenser service vtable + simulated implementation
src/ui/           ui_manager, theme, assets, screens
src/platform/     logging and time wrappers
config/           app_config.h + lv_conf.h
```

## Documentation

- [Requirements](documents/00_requirements.md) - what the prototype is supposed to do.
- [Architecture](docs/architecture.md) - layering rules and the UI/controller/service split.
- [UI flow](docs/ui-flow.md) - screens and the transitions between them.
- [Build and deploy](docs/build-and-deploy.md) - build paths, tooling outputs, packaging.
- [Agent guide](AGENTS.md) - repository conventions for coding agents.
- [Software engineering plan](SWE_PLAN.md) - the engineering plan this repository follows.
- [License](LICENSE) - GPLv3 or later.
