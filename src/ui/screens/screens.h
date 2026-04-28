#ifndef COFFEE_UI_SCREENS_H
#define COFFEE_UI_SCREENS_H

#include "app/app_controller.h"

#include "lvgl.h"

#include <stdbool.h>

typedef struct coffee_ui_manager coffee_ui_manager_t;

void coffee_screen_show_splash(coffee_ui_manager_t *ui);
void coffee_screen_show_home(coffee_ui_manager_t *ui);
void coffee_screen_show_beverage(coffee_ui_manager_t *ui);
void coffee_screen_show_dispense(coffee_ui_manager_t *ui);
void coffee_screen_update_dispense(coffee_ui_manager_t *ui);
void coffee_screen_show_completion(coffee_ui_manager_t *ui, bool cancelled);
void coffee_screen_show_error(coffee_ui_manager_t *ui);
void coffee_screen_show_settings(coffee_ui_manager_t *ui);
void coffee_screen_show_diagnostics(coffee_ui_manager_t *ui);

#endif
