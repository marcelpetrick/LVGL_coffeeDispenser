# Requirements and Design Document: LVGL Coffee Dispenser HMI

## 1. Document Control

**Project name:** LVGL Coffee Dispenser HMI
**Target platform:** Linux desktop x86_64 for simulation and development; portable to embedded Linux or MCU-based LVGL targets
**Primary framework:** LVGL 9.x
**Primary language:** C, with C++ compatibility allowed for hardware-abstraction modules
**Build system:** CMake
**Document status:** Initial requirements and design specification

## 2. Project Vision

The project shall implement a touch-capable graphical user interface for a coffee dispenser using the LVGL framework. The application shall allow users to select and dispense common hot drinks such as coffee, espresso, and latte macchiato. It shall also include a dedicated water-dispensing function.

The software shall be usable as a complete desktop simulation project on Linux x86_64 and shall be structured so that the same UI logic can later be deployed to an embedded Linux device or an embedded target with LVGL support.

## 3. Goals

The project shall:

1. Provide a polished LVGL-based HMI for a coffee dispenser.
2. Support beverage selection, configuration, confirmation, dispensing progress, completion, and cancellation workflows.
3. Include a dedicated water-dispense button.
4. Be buildable and runnable on Linux desktop x86_64.
5. Use CMake as the build system.
6. Separate UI, application logic, hardware abstraction, configuration, assets, and tests.
7. Provide clear build, run, test, and deployment instructions.
8. Be suitable for future migration to real dispenser hardware.

## 4. Non-Goals for the First Version

The first version is not required to:

1. Control real heaters, pumps, valves, grinders, milk systems, or sensors directly.
2. Implement payment handling.
3. Implement cloud connectivity.
4. Implement user accounts.
5. Implement machine-learning beverage recommendations.
6. Support multiple physical display resolutions beyond the defined responsive layouts.
7. Provide certified safety compliance for commercial appliances.

The architecture shall, however, leave clear extension points for these future capabilities.

## 5. Stakeholders

| Stakeholder                | Interest                                                  |
| -------------------------- | --------------------------------------------------------- |
| End user                   | Selects drinks and receives clear feedback                |
| Product owner              | Defines supported beverages and user experience           |
| UI designer                | Defines visual style, layout, assets, and animations      |
| Embedded software engineer | Integrates UI with hardware and machine controller        |
| Test engineer              | Verifies UI behavior and state-machine correctness        |
| Maintainer                 | Builds, deploys, updates, and debugs the application      |
| Service technician         | Uses diagnostics and error information during maintenance |

## 6. Operating Assumptions

1. The Linux desktop target is x86_64.
2. The desktop simulation shall use SDL or an equivalent LVGL-supported Linux backend.
3. The production target may later use Linux framebuffer, DRM/KMS, Wayland, X11, SDL, or another LVGL display/input backend.
4. The first implementation shall use simulated hardware services.
5. The UI shall be touch-first but must also be usable with a mouse during desktop simulation.
6. The application shall be able to run without real coffee-machine hardware.

## 7. System Context

The LVGL Coffee Dispenser HMI is one subsystem of a larger coffee dispenser product. It interacts with a beverage-control subsystem through an abstract service interface.

```text
+---------------------------+
| User                      |
| Touch / Mouse             |
+-------------+-------------+
              |
              v
+---------------------------+
| LVGL Coffee HMI           |
| Screens, widgets, themes  |
+-------------+-------------+
              |
              v
+---------------------------+
| Application Controller    |
| State machine, validation |
+-------------+-------------+
              |
              v
+---------------------------+
| Dispenser Service API     |
| Simulated or real backend |
+-------------+-------------+
              |
              v
+---------------------------+
| Hardware Controller       |
| Pumps, valves, sensors    |
+---------------------------+
```

## 8. Functional Requirements

### 8.1 Startup

**FR-001:** The application shall initialize LVGL, the selected display backend, the selected input backend, application configuration, UI assets, and the beverage model.
**FR-002:** The application shall show a startup/splash screen for a configurable duration.
**FR-003:** The application shall transition automatically from startup to the home screen.
**FR-004:** If startup fails, the application shall display a recoverable error screen when possible and log the failure.

### 8.2 Home Screen

**FR-010:** The application shall provide a home screen showing available drink options.
**FR-011:** The home screen shall provide drink buttons for at least:

1. Coffee
2. Espresso
3. Latte macchiato
4. Cappuccino
5. Americano
6. Hot water

**FR-012:** The hot-water function shall be visually available as a dedicated button.
**FR-013:** Each beverage button shall show a readable label and an icon or symbolic illustration.
**FR-014:** The home screen shall show machine status, such as Ready, Heating, Dispensing, Cleaning required, Water empty, or Error.
**FR-015:** The home screen shall expose access to settings and service/diagnostics if enabled by configuration.

### 8.3 Beverage Selection

**FR-020:** When the user selects a beverage, the application shall open a beverage detail screen or confirmation dialog.
**FR-021:** The beverage detail screen shall show the selected beverage name, estimated volume, estimated preparation time, and configurable options.
**FR-022:** The user shall be able to confirm or cancel the selected beverage.
**FR-023:** The application shall prevent beverage confirmation if the machine state does not allow dispensing.

### 8.4 Beverage Customization

**FR-030:** The application shall support configurable beverage options where applicable.
**FR-031:** Coffee and americano shall support at least size selection: Small, Medium, Large.
**FR-032:** Espresso shall support at least Single and Double.
**FR-033:** Milk-based drinks shall support milk amount selection if the backend reports milk control capability.
**FR-034:** The customization UI shall clearly show the selected option.
**FR-035:** The application shall validate all customization options before starting dispense.

### 8.5 Hot Water Dispensing

**FR-040:** The application shall provide a dedicated hot-water dispense function.
**FR-041:** The hot-water flow shall support fixed presets, for example 100 ml, 200 ml, and 300 ml.
**FR-042:** The hot-water screen shall include a confirmation step to reduce accidental dispensing.
**FR-043:** The hot-water screen shall provide a stop/cancel button during dispensing.
**FR-044:** If water temperature or level is not ready, the application shall display a clear unavailable message.

### 8.6 Dispensing Workflow

**FR-050:** After confirmation, the application shall transition to a dispensing screen.
**FR-051:** The dispensing screen shall show the selected beverage, current step, progress percentage, and estimated remaining time.
**FR-052:** The user shall be able to cancel dispensing if the backend reports cancellation is safe.
**FR-053:** The application shall show a completion screen when dispensing succeeds.
**FR-054:** The completion screen shall automatically return to the home screen after a configurable timeout.
**FR-055:** If dispensing fails, the application shall show an error screen with a user-readable explanation.

### 8.7 Machine Status Handling

**FR-060:** The application shall consume machine status updates from the dispenser service.
**FR-061:** The application shall show status indicators for at least:

1. Ready
2. Heating
3. Dispensing
4. Water tank empty
5. Bean hopper empty
6. Milk unavailable
7. Cleaning required
8. Drip tray full
9. Door open
10. General error

**FR-062:** The UI shall disable unavailable drinks based on current machine capability and resource state.
**FR-063:** The UI shall explain why a drink is unavailable when the user attempts to select it.
**FR-064:** Critical machine errors shall interrupt normal operation and display a blocking error screen.

### 8.8 Settings

**FR-070:** The application shall provide a settings screen if enabled in configuration.
**FR-071:** Settings shall include language, brightness simulation, sound on/off simulation, theme selection, and timeout values.
**FR-072:** Settings shall persist across application restarts when persistence is enabled.
**FR-073:** Invalid settings shall be rejected and logged.

### 8.9 Diagnostics and Service Mode

**FR-080:** The application shall provide a diagnostics screen if enabled in build or runtime configuration.
**FR-081:** Diagnostics shall show application version, LVGL version, backend type, uptime, and simulated hardware state.
**FR-082:** Diagnostics shall include test actions for simulated pump, valve, heater, and sensor states.
**FR-083:** Service mode shall be protected by configuration, PIN, build flag, or hidden gesture before production use.

### 8.10 Localization

**FR-090:** User-facing strings shall be centralized.
**FR-091:** The first version shall support English.
**FR-092:** The architecture shall allow adding German and other languages later.
**FR-093:** Text layout shall tolerate longer translated labels without clipping.

### 8.11 Logging

**FR-100:** The application shall log startup, shutdown, screen transitions, beverage requests, dispensing state changes, errors, and backend events.
**FR-101:** On Linux desktop, logs shall be written to standard output by default.
**FR-102:** Optional file logging shall be configurable.
**FR-103:** Logs shall not contain sensitive information.

## 9. User Interface Requirements

### 9.1 Display Resolution

**UI-001:** The primary design resolution shall be 800 × 480 pixels.
**UI-002:** The UI shall also support 1024 × 600 pixels without redesign.
**UI-003:** The layout shall use relative sizing and LVGL layout mechanisms where practical.
**UI-004:** The minimum supported pointer target size shall be 48 × 48 pixels.

### 9.2 Visual Design

**UI-010:** The design shall use a modern appliance-style interface with high contrast, large controls, and minimal clutter.
**UI-011:** The home screen shall use a card/grid layout for beverages.
**UI-012:** Primary actions shall be visually distinct from secondary actions.
**UI-013:** Error states shall use clear color, iconography, and concise text.
**UI-014:** Disabled buttons shall remain readable but visibly inactive.
**UI-015:** The UI shall use consistent spacing, typography, corner radius, and icon style.

### 9.3 Navigation

**UI-020:** Navigation depth from home to dispense start shall not exceed two user decisions for default beverages.
**UI-021:** Every non-modal screen except splash and blocking error shall provide a clear way back to home.
**UI-022:** Confirmation dialogs shall have both confirm and cancel actions.
**UI-023:** The active screen state shall be obvious to the user.

### 9.4 Feedback and Animation

**UI-030:** Button presses shall provide immediate visual feedback.
**UI-031:** Screen transitions may use short LVGL animations if they do not reduce responsiveness.
**UI-032:** Dispensing progress shall be animated or updated periodically.
**UI-033:** Long operations shall never leave the user without feedback.

### 9.5 Accessibility

**UI-040:** Text shall be large enough for appliance use at arm length.
**UI-041:** The interface shall avoid conveying critical information by color alone.
**UI-042:** Touch targets shall be suitable for finger input.
**UI-043:** Important messages shall use plain language.
**UI-044:** The default theme shall provide sufficient contrast for typical indoor lighting.

## 10. Beverage Model Requirements

### 10.1 Beverage Data Structure

Each beverage shall be represented by a static or configurable model containing:

1. Beverage ID
2. Display name string ID
3. Category
4. Icon asset ID
5. Default volume in ml
6. Minimum and maximum volume where adjustable
7. Default preparation time estimate
8. Required resources: water, beans, milk, heater, grinder
9. Supported options
10. Availability state

### 10.2 Initial Beverage Set

| ID              |    Display name | Default volume | Options                | Required resources         |
| --------------- | --------------: | -------------: | ---------------------- | -------------------------- |
| coffee          |          Coffee |         180 ml | Small / Medium / Large | Water, beans, heater       |
| espresso        |        Espresso |          40 ml | Single / Double        | Water, beans, heater       |
| latte_macchiato | Latte Macchiato |         250 ml | Milk level             | Water, beans, milk, heater |
| cappuccino      |      Cappuccino |         180 ml | Milk level             | Water, beans, milk, heater |
| americano       |       Americano |         200 ml | Small / Medium / Large | Water, beans, heater       |
| hot_water       |       Hot Water |         200 ml | 100 / 200 / 300 ml     | Water, heater              |

## 11. State Machine Requirements

### 11.1 Main Application States

The application shall use an explicit state machine with at least these states:

1. Booting
2. Ready
3. BeverageSelected
4. Confirming
5. Dispensing
6. Completed
7. Cancelled
8. Error
9. Maintenance
10. Shutdown

### 11.2 State Transitions

| From             | Event                          | To                          |
| ---------------- | ------------------------------ | --------------------------- |
| Booting          | Initialization successful      | Ready                       |
| Booting          | Initialization failed          | Error                       |
| Ready            | Beverage selected              | BeverageSelected            |
| BeverageSelected | User confirms                  | Confirming                  |
| BeverageSelected | User cancels                   | Ready                       |
| Confirming       | Backend accepts request        | Dispensing                  |
| Confirming       | Backend rejects request        | Error or Ready with message |
| Dispensing       | Progress complete              | Completed                   |
| Dispensing       | User cancels safely            | Cancelled                   |
| Dispensing       | Backend error                  | Error                       |
| Completed        | Timeout or user closes         | Ready                       |
| Cancelled        | Cleanup complete               | Ready                       |
| Error            | Error acknowledged and cleared | Ready or Maintenance        |

## 12. Software Architecture

### 12.1 Architectural Principles

1. Keep LVGL screen construction separate from business logic.
2. Keep hardware interaction behind an interface.
3. Make the desktop simulator the default development target.
4. Keep build options explicit in CMake.
5. Avoid global mutable state except where LVGL integration requires it.
6. Ensure UI code can be tested with simulated backend events.

### 12.2 Proposed Components

| Component               | Responsibility                                                |
| ----------------------- | ------------------------------------------------------------- |
| `main`                  | Process entry point, LVGL init, backend selection, main loop  |
| `app_controller`        | State machine and use-case orchestration                      |
| `ui_manager`            | Screen creation, transitions, theme application               |
| `screens`               | Home, beverage detail, dispense, settings, error, diagnostics |
| `beverage_model`        | Drink definitions and option validation                       |
| `dispenser_service`     | Abstract interface for machine/backend operations             |
| `sim_dispenser_service` | Simulated backend for Linux desktop                           |
| `platform`              | SDL, Linux, timing, filesystem, logging wrappers              |
| `assets`                | Fonts, icons, images, compiled LVGL assets                    |
| `config`                | Compile-time and runtime configuration                        |
| `tests`                 | Unit and integration tests                                    |

## 13. Recommended Repository Layout

```text
lvgl-coffee-dispenser/
├── CMakeLists.txt
├── CMakePresets.json
├── README.md
├── LICENSE
├── docs/
│   ├── requirements.md
│   ├── architecture.md
│   ├── build-and-deploy.md
│   └── ui-flow.md
├── external/
│   └── lvgl/                  # Git submodule or fetched dependency
├── config/
│   ├── lv_conf.h
│   └── app_config.h
├── assets/
│   ├── fonts/
│   ├── icons/
│   └── generated/
├── src/
│   ├── main.c
│   ├── app/
│   │   ├── app_controller.c
│   │   ├── app_controller.h
│   │   ├── app_state.h
│   │   ├── beverage_model.c
│   │   └── beverage_model.h
│   ├── ui/
│   │   ├── ui_manager.c
│   │   ├── ui_manager.h
│   │   ├── ui_theme.c
│   │   ├── ui_theme.h
│   │   └── screens/
│   │       ├── screen_home.c
│   │       ├── screen_beverage.c
│   │       ├── screen_dispense.c
│   │       ├── screen_settings.c
│   │       ├── screen_error.c
│   │       └── screen_diagnostics.c
│   ├── service/
│   │   ├── dispenser_service.h
│   │   ├── sim_dispenser_service.c
│   │   └── sim_dispenser_service.h
│   └── platform/
│       ├── platform_time.c
│       ├── platform_log.c
│       └── platform_linux_sdl.c
├── tests/
│   ├── CMakeLists.txt
│   ├── test_beverage_model.c
│   └── test_app_controller.c
└── tools/
    ├── convert_assets.sh
    └── package_linux.sh
```

## 14. Build Requirements

**BR-001:** The project shall build with CMake on Linux x86_64.
**BR-002:** The default compiler shall be GCC or Clang.
**BR-003:** Ninja shall be supported as the preferred generator.
**BR-004:** The project shall support Debug and Release builds.
**BR-005:** LVGL shall be integrated either as a Git submodule or via CMake `FetchContent`.
**BR-006:** The desktop build shall use SDL2 by default.
**BR-007:** Build configuration shall expose options for simulator backend, diagnostics mode, logging level, and test builds.
**BR-008:** The build shall fail on missing required dependencies with clear messages.
**BR-009:** The project shall provide CMake presets for common Linux builds.

## 15. Example CMake Options

```cmake
option(COFFEE_BUILD_TESTS "Build unit tests" ON)
option(COFFEE_ENABLE_DIAGNOSTICS "Enable diagnostics screen" ON)
option(COFFEE_ENABLE_FILE_LOGGING "Enable file logging" OFF)
set(COFFEE_BACKEND "SDL" CACHE STRING "Display/input backend: SDL, FBDEV, DRM")
set(COFFEE_DEFAULT_WIDTH "800" CACHE STRING "Default display width")
set(COFFEE_DEFAULT_HEIGHT "480" CACHE STRING "Default display height")
```

## 16. Linux Desktop Development Requirements

**LD-001:** The application shall run on Linux x86_64 as a normal desktop process.
**LD-002:** The desktop application shall open a window representing the target display.
**LD-003:** Mouse input shall simulate touch input.
**LD-004:** The simulator shall not require root privileges.
**LD-005:** The simulator shall not require physical coffee-machine hardware.
**LD-006:** The simulator shall support deterministic backend scenarios for testing error states.
**LD-007:** The simulator shall be executable from the build directory using a single command.

## 17. Build Instructions: Linux x86_64 Desktop

### 17.1 Install Dependencies

For Debian/Ubuntu-like systems:

```bash
sudo apt update
sudo apt install -y \
  build-essential \
  cmake \
  ninja-build \
  pkg-config \
  libsdl2-dev \
  git
```

### 17.2 Clone Project

```bash
git clone https://example.com/lvgl-coffee-dispenser.git
cd lvgl-coffee-dispenser
git submodule update --init --recursive
```

If LVGL is fetched with CMake instead of a submodule, the submodule command is not required.

### 17.3 Configure

```bash
cmake --preset linux-debug
```

Alternative manual configuration:

```bash
cmake -S . -B build/linux-debug -G Ninja \
  -DCMAKE_BUILD_TYPE=Debug \
  -DCOFFEE_BACKEND=SDL \
  -DCOFFEE_BUILD_TESTS=ON
```

### 17.4 Build

```bash
cmake --build build/linux-debug
```

### 17.5 Run

```bash
./build/linux-debug/lvgl_coffee_dispenser
```

### 17.6 Run Tests

```bash
ctest --test-dir build/linux-debug --output-on-failure
```

## 18. Deployment Requirements

### 18.1 Desktop Deployment

**DEP-001:** The project shall provide a packaging script for Linux desktop builds.
**DEP-002:** The package shall include the executable, runtime assets, configuration files, and README.
**DEP-003:** The packaged application shall document required dynamic libraries.
**DEP-004:** The application shall be runnable without access to the source tree.

### 18.2 Embedded Linux Deployment

**DEP-010:** The architecture shall support switching from SDL to framebuffer, DRM/KMS, Wayland, or another LVGL-supported backend.
**DEP-011:** Platform-specific backend code shall be isolated in `src/platform`.
**DEP-012:** Runtime paths for assets, logs, and configuration shall be configurable.
**DEP-013:** Embedded deployment shall support launching from systemd or an equivalent init mechanism.
**DEP-014:** Production deployment shall define permissions for input devices, display devices, and any machine-control device nodes.

### 18.3 Example Desktop Packaging Command

```bash
./tools/package_linux.sh build/linux-release dist/lvgl-coffee-dispenser-linux-x86_64
```

## 19. Runtime Configuration Requirements

**CFG-001:** The application shall support compile-time defaults in `app_config.h`.
**CFG-002:** Runtime configuration may be loaded from a file such as `coffee_dispenser.json` or a simple key-value format.
**CFG-003:** Runtime configuration shall include screen size, language, diagnostics visibility, timeout values, and simulator scenario.
**CFG-004:** Invalid runtime configuration shall fall back to safe defaults and log warnings.
**CFG-005:** Configuration parsing shall not block UI startup for an unacceptable duration.

## 20. Error Handling Requirements

**ERR-001:** All backend errors shall be translated into user-readable error messages.
**ERR-002:** Technical details shall be logged but not shown prominently to end users.
**ERR-003:** Critical errors shall block dispensing until cleared.
**ERR-004:** Non-critical warnings shall be shown as banners or status indicators.
**ERR-005:** The application shall handle backend disconnection or unavailability.
**ERR-006:** The application shall not crash on unavailable assets; it shall use fallback visuals when possible.

## 21. Safety-Related Requirements

This software document does not claim appliance safety certification. Nevertheless, the HMI shall follow safety-oriented design principles.

**SAFE-001:** The UI shall require explicit confirmation before dispensing hot water or hot beverages.
**SAFE-002:** The UI shall provide a visible stop/cancel action during dispensing where safe cancellation is supported.
**SAFE-003:** The UI shall not allow dispensing when the machine reports unsafe status.
**SAFE-004:** The UI shall clearly show heating, dispensing, and error states.
**SAFE-005:** The backend, not the UI alone, shall be responsible for hard real-time and safety-critical machine control.
**SAFE-006:** The UI shall never assume that a command succeeded without backend acknowledgement.
**SAFE-007:** The application shall handle repeated button presses without sending duplicate unsafe commands.

## 22. Performance Requirements

**PERF-001:** The UI shall remain responsive during normal operation.
**PERF-002:** Screen transitions should complete within 300 ms on the desktop target.
**PERF-003:** Button press feedback should appear within 100 ms.
**PERF-004:** The LVGL task handler shall be called at a suitable period for smooth UI operation.
**PERF-005:** Long-running backend operations shall be asynchronous or simulated asynchronously.
**PERF-006:** The application shall avoid blocking the UI thread with file I/O, sleeps, or backend waits.

## 23. Reliability Requirements

**REL-001:** The application shall recover gracefully from simulated backend failures.
**REL-002:** State transitions shall be deterministic.
**REL-003:** Invalid UI events in the current state shall be ignored or handled safely.
**REL-004:** The application shall support repeated beverage-selection cycles without memory growth.
**REL-005:** The application shall avoid dynamic allocation in tight update loops where practical.
**REL-006:** Resource creation and destruction shall follow LVGL lifecycle rules.

## 24. Security Requirements

**SEC-001:** Service and diagnostics mode shall not be exposed in production without protection.
**SEC-002:** Runtime configuration files shall be validated.
**SEC-003:** The application shall not execute commands from configuration files.
**SEC-004:** Logs shall not expose secrets.
**SEC-005:** If network features are added later, they shall require a separate security design.

## 25. Test Requirements

### 25.1 Unit Tests

**TEST-001:** Beverage model validation shall be unit-tested.
**TEST-002:** Application state transitions shall be unit-tested.
**TEST-003:** Configuration parsing shall be unit-tested.
**TEST-004:** Error mapping shall be unit-tested.

### 25.2 Integration Tests

**TEST-010:** The simulated backend shall support scripted status changes.
**TEST-011:** Beverage dispensing success and failure flows shall be integration-tested.
**TEST-012:** Hot-water dispensing shall be integration-tested separately.
**TEST-013:** Unavailable resources shall disable affected drinks.
**TEST-014:** Cancel handling shall be tested for safe and unsafe cancellation modes.

### 25.3 Manual UI Tests

Manual tests shall cover:

1. Startup and transition to home.
2. Selecting each beverage.
3. Confirming and cancelling beverage preparation.
4. Hot-water dispensing.
5. Error states.
6. Disabled drink states.
7. Settings screen.
8. Diagnostics screen.
9. Screen resizing if supported.
10. Repeated operation for at least 50 cycles.

## 26. Acceptance Criteria

The first version shall be accepted when:

1. The project builds on Linux x86_64 using CMake.
2. The application runs as a desktop LVGL simulator window.
3. The home screen shows coffee, espresso, latte macchiato, cappuccino, americano, and hot water.
4. Each beverage can be selected and confirmed.
5. The hot-water button has a dedicated workflow.
6. Dispensing progress is shown using a simulated backend.
7. Successful, cancelled, and failed dispensing states are visible.
8. Unavailable machine states are represented in the UI.
9. Unit tests for beverage model and state machine pass.
10. Build, run, test, and package instructions are documented.

## 27. Suggested Implementation Milestones

### Milestone 1: Project Skeleton

1. Create CMake project.
2. Add LVGL dependency.
3. Add Linux SDL desktop backend.
4. Open an empty LVGL window.
5. Add logging and basic configuration.

### Milestone 2: Static UI Prototype

1. Implement theme.
2. Implement splash and home screen.
3. Add beverage cards.
4. Add hot-water button.
5. Add placeholder assets.

### Milestone 3: Application State Machine

1. Implement beverage model.
2. Implement state machine.
3. Connect button events to application controller.
4. Add beverage detail and confirmation screens.

### Milestone 4: Simulated Dispensing

1. Implement simulated backend.
2. Add progress screen.
3. Add completion, cancellation, and error flows.
4. Add simulated resource states.

### Milestone 5: Settings, Diagnostics, and Tests

1. Add settings screen.
2. Add diagnostics screen.
3. Add unit tests.
4. Add integration test scenarios.
5. Document packaging and embedded deployment path.

## 28. Open Questions

1. What is the final production display resolution?
2. Is the final input method capacitive touch, resistive touch, encoder, physical buttons, or mixed input?
3. Which real hardware backend will be used later?
4. Which languages are required at launch?
5. Is milk dispensing controlled by the same backend or a separate subsystem?
6. Should the hot-water function dispense immediately after confirmation or support press-and-hold operation?
7. Are there appliance-specific safety standards that the final product must satisfy?
8. Should the UI be designed with SquareLine Studio or manually coded in LVGL?
9. Does the product require branding, custom icons, or animation assets?
10. Is persistent usage statistics or maintenance logging required?

## 29. Recommended First Technical Decisions

1. Use LVGL 9.x.
2. Use C as the primary implementation language.
3. Use CMake and Ninja.
4. Use SDL2 for the Linux desktop simulator.
5. Use 800 × 480 as the primary UI resolution.
6. Use a simulated dispenser backend first.
7. Keep real hardware support behind `dispenser_service.h`.
8. Implement an explicit state machine before adding advanced visual polish.
9. Keep all strings centralized for later localization.
10. Treat hot water as a first-class beverage with stricter confirmation.

## 30. Minimal Definition of Done for the Initial Repository

A repository is considered complete for the initial version when it contains:

1. `README.md` with dependency, build, run, test, and deploy instructions.
2. CMake project building the application on Linux x86_64.
3. LVGL dependency integrated reproducibly.
4. SDL-based simulator backend.
5. Home, beverage detail, hot water, dispensing, completion, and error screens.
6. Simulated dispenser service.
7. Unit tests for beverage model and state machine.
8. Example configuration file.
9. Basic asset pipeline or documented placeholder assets.
10. Packaging script for Linux desktop.
