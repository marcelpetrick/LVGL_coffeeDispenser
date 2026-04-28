#include "ui/ui_manager.h"

#include "app_config.h"
#include "ui/screens/screens.h"
#include "ui/ui_theme.h"

#include <string.h>

void coffee_ui_manager_init(coffee_ui_manager_t *ui,
                            coffee_app_controller_t *app) {
  memset(ui, 0, sizeof(*ui));
  ui->app = app;
  ui->visible_state = COFFEE_APP_BOOTING;
  ui->splash_visible = true;
  coffee_ui_theme_apply();
  coffee_screen_show_splash(ui);
}

static void show_for_state(coffee_ui_manager_t *ui) {
  switch (coffee_app_controller_state(ui->app)) {
  case COFFEE_APP_READY:
    coffee_screen_show_home(ui);
    break;
  case COFFEE_APP_BEVERAGE_SELECTED:
    coffee_screen_show_beverage(ui);
    break;
  case COFFEE_APP_DISPENSING:
    coffee_screen_show_dispense(ui);
    break;
  case COFFEE_APP_COMPLETED:
    coffee_screen_show_completion(ui, false);
    break;
  case COFFEE_APP_CANCELLED:
    coffee_screen_show_completion(ui, true);
    break;
  case COFFEE_APP_ERROR:
    coffee_screen_show_error(ui);
    break;
  default:
    break;
  }
}

void coffee_ui_manager_tick(coffee_ui_manager_t *ui, uint32_t elapsed_ms) {
  if (ui->splash_visible) {
    ui->splash_elapsed_ms += elapsed_ms;
    if (ui->splash_elapsed_ms >= COFFEE_SPLASH_MS) {
      ui->splash_visible = false;
      ui->visible_state = coffee_app_controller_state(ui->app);
      show_for_state(ui);
    }
    return;
  }

  coffee_app_state_t state = coffee_app_controller_state(ui->app);
  if (state != ui->visible_state) {
    ui->visible_state = state;
    show_for_state(ui);
  }

  if (state == COFFEE_APP_DISPENSING) {
    coffee_screen_update_dispense(ui);
  }

  if ((state == COFFEE_APP_COMPLETED &&
       ui->app->state_elapsed_ms > COFFEE_COMPLETION_MS) ||
      (state == COFFEE_APP_CANCELLED &&
       ui->app->state_elapsed_ms > COFFEE_CANCELLED_MS)) {
    coffee_app_controller_home(ui->app);
  }
}

bool coffee_ui_manager_wants_quit(const coffee_ui_manager_t *ui) {
  return ui->wants_quit;
}
