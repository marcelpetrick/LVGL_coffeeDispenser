# Software Engineering Tooling Plan

This plan adapts the tooling ideas from `documents/llm_compat_output.md` to the LVGL Coffee Dispenser HMI. The goal is to improve engineering feedback without blocking the current prototype workflow or copying Qt-specific pieces that do not apply.

## Principles

- Keep all checks runnable locally with one script.
- Prefer clear failures over best-effort hidden warnings.
- Keep generated artifacts out of git.
- Make optional tools degrade explicitly when they are missing, except in the full pipeline where missing required tooling should fail early.
- Keep target code portable to embedded builds; desktop-only tooling stays in CMake options, scripts, or tests.

## Task 1: Baseline Formatting And Pipeline Hardening

Add repository-local formatting rules and make the local validation script stricter.

Work items:
- Add `.clang-format` for C headers and C sources.
- Rename or complement `tools/full_check.sh` with a top-level `localPipeline.sh` entry point modeled after the reference project.
- Keep formatting validation non-mutating in the default pipeline (`clang-format --dry-run --Werror`).
- Make the script print a concise stage summary.
- Keep support for `--no-run`, `--verbose`, `--build-dir`, and `--help`.

Acceptance:
- `./localPipeline.sh --no-run` configures, builds, runs tests, and checks formatting.
- A formatting drift fails the pipeline instead of rewriting files silently.
- `./tools/full_check.sh` remains available as a compatibility wrapper or documented alias.

Commit:
- `chore: add local validation pipeline`

## Task 2: Static Analysis

Add Cppcheck static analysis using the CMake compilation database.

Work items:
- Set `CMAKE_EXPORT_COMPILE_COMMANDS ON`.
- Add `scripts/run_cppcheck.sh`.
- Generate `reports/cppcheck/cppcheck.xml`.
- Generate `reports/cppcheck/html/index.html` when `cppcheck-htmlreport` is installed.
- Filter analysis to project-owned `src/`, `tests/`, and `config/`, excluding `external/lvgl` and build directories.
- Integrate Cppcheck into `localPipeline.sh`.

Acceptance:
- `./scripts/run_cppcheck.sh --build-dir build/linux-debug` runs after configure.
- Tool setup errors fail; findings are reported clearly. Initial policy can be informational unless severe findings are found.
- Reports are ignored by git.

Commit:
- `chore: add cppcheck static analysis`

## Task 3: Doxygen Documentation

Add generated API documentation for the C codebase.

Work items:
- Add `Doxyfile.in`.
- Add a CMake `doxygen` target when Doxygen is installed.
- Include `README.md`, `docs/`, `config/`, and `src/`.
- Write warnings to `build/<preset>/doxygen/warnings.txt`.
- Integrate Doxygen into `localPipeline.sh`.

Acceptance:
- `cmake --build build/linux-debug --target doxygen` generates `build/linux-debug/doxygen/html/index.html` when Doxygen is available.
- The pipeline fails if Doxygen runs and produces warnings.
- Missing Doxygen is reported clearly.

Commit:
- `docs: add doxygen generation`

## Task 4: Coverage

Add opt-in gcov coverage for unit-testable code.

Work items:
- Add `COFFEE_ENABLE_COVERAGE` CMake option.
- Require GCC or Clang-compatible coverage flags when coverage is enabled.
- Add a dedicated coverage build path in `localPipeline.sh`.
- Add CMake targets `coverage` and `coverage-html`.
- Prefer `gcovr` for HTML and JSON summary; fall back to `lcov` plus `genhtml` where practical.
- Filter reports to project-owned source and test code, excluding `external/lvgl`.
- Add a line coverage gate. Start with a realistic threshold for the current prototype, then raise as tests grow.

Acceptance:
- `cmake -S . -B build-coverage -DCOFFEE_ENABLE_COVERAGE=ON -DCOFFEE_BUILD_TESTS=ON` builds.
- Coverage output includes `build-coverage/coverage/coverage.txt`.
- HTML coverage writes `build-coverage/coverage/html/index.html` when supported tooling is installed.
- `localPipeline.sh --no-run` runs coverage and enforces the configured threshold.

Commit:
- `test: add gcov coverage targets`

## Task 5: Test And Runtime Smoke Coverage

Expand tests around the state machine and add a headless startup smoke test.

Work items:
- Add CTest target for a short application startup smoke test.
- Add an app option or environment variable to exit after startup so the smoke test does not require manual window closing.
- Use SDL dummy video driver for headless environments when possible.
- Add controller tests for backend rejection, simulated failure, cancellation, and unavailable resources.
- Add beverage model tests for every initial beverage and invalid option combinations.

Acceptance:
- `ctest --preset linux-debug --output-on-failure` includes the smoke test and deterministic unit tests.
- The smoke test does not hang and has a timeout.
- Tests remain independent of real coffee-machine hardware.

Commit:
- `test: broaden controller and startup coverage`

## Task 6: Documentation And Developer Workflow

Update user-facing docs so the new workflow is discoverable.

Work items:
- Expand `README.md` with local pipeline, formatting, Cppcheck, Doxygen, coverage, and packaging sections.
- Add a tooling overview in `docs/build-and-deploy.md`.
- Document required and optional dependencies.
- Keep generated report paths explicit.

Acceptance:
- A new developer can run the full local validation command from the README.
- The docs describe what is optional, what fails the pipeline, and where reports are written.

Commit:
- `docs: document local engineering workflow`

## Task 7: Final Verification

Run and record the finished validation state.

Work items:
- Run `./localPipeline.sh --no-run`.
- Run a short app smoke launch when a display is available or with SDL dummy if supported.
- Check `git status`.

Acceptance:
- Pipeline passes or any unavailable host tool is documented with exact command output.
- Worktree contains only intentional untracked local files.

Commit:
- Use a small cleanup commit only if final verification requires changes.
