#include "ui/screens/screens.h"

#include "ui/ui_manager.h"
#include "ui/ui_theme.h"

static void home_cb(lv_event_t *e) {
  coffee_app_controller_home(
      ((coffee_ui_manager_t *)lv_event_get_user_data(e))->app);
}

void coffee_screen_show_error(coffee_ui_manager_t *ui) {
  lv_obj_t *screen = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(screen, coffee_ui_color_bg(), 0);
  lv_obj_set_style_pad_all(screen, 34, 0);
  lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_align(screen, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER,
                        LV_FLEX_ALIGN_CENTER);

  lv_obj_t *title = lv_label_create(screen);
  lv_label_set_text(title, "Unable to dispense");
  lv_obj_set_style_text_font(title, &lv_font_montserrat_32, 0);
  lv_obj_set_style_text_color(title, coffee_ui_color_warning(), 0);

  lv_obj_t *message = lv_label_create(screen);
  lv_label_set_text(message, coffee_app_controller_message(ui->app));
  lv_obj_set_style_text_color(message, coffee_ui_color_text(), 0);
  lv_obj_set_style_text_align(message, LV_TEXT_ALIGN_CENTER, 0);

  lv_obj_t *button = lv_button_create(screen);
  lv_obj_set_size(button, 220, 58);
  lv_obj_add_event_cb(button, home_cb, LV_EVENT_CLICKED, ui);
  lv_obj_t *label = lv_label_create(button);
  lv_label_set_text(label, "Back to home");
  lv_obj_center(label);

  lv_screen_load(screen);
}
