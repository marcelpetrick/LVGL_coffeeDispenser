# Architecture

The prototype follows the component split required in `documents/00_requirements.md`.

- `src/app`: beverage model and explicit application state machine.
- `src/service`: abstract dispenser service plus a simulated backend.
- `src/ui`: LVGL screens, theme, and screen transitions.
- `src/platform`: logging and timing wrappers.
- `config`: compile-time application and LVGL configuration.
- `tests`: display-independent unit tests.

The UI only requests state changes through `app_controller`. The controller validates options, asks the dispenser service whether a request is allowed, starts dispensing only after backend acknowledgement, and maps service progress into visible states.
