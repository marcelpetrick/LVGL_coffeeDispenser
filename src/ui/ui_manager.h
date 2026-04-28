#ifndef COFFEE_UI_MANAGER_H
#define COFFEE_UI_MANAGER_H

#include "app/app_controller.h"

#include "lvgl.h"

#include <stdbool.h>

typedef struct coffee_ui_manager coffee_ui_manager_t;

void coffee_ui_manager_init(coffee_ui_manager_t *ui,
                            coffee_app_controller_t *app);
void coffee_ui_manager_tick(coffee_ui_manager_t *ui, uint32_t elapsed_ms);
bool coffee_ui_manager_wants_quit(const coffee_ui_manager_t *ui);

struct coffee_ui_manager {
  coffee_app_controller_t *app;
  coffee_app_state_t visible_state;
  uint32_t splash_elapsed_ms;
  bool splash_visible;
  bool wants_quit;
  lv_obj_t *progress_bar;
  lv_obj_t *progress_label;
  lv_obj_t *step_label;
};

#endif
