#include "ui/screens/screens.h"

#include "ui/ui_manager.h"
#include "ui/ui_theme.h"

static void home_cb(lv_event_t *e) {
  coffee_screen_show_home(lv_event_get_user_data(e));
}

void coffee_screen_show_settings(coffee_ui_manager_t *ui) {
  lv_obj_t *screen = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(screen, coffee_ui_color_bg(), 0);
  lv_obj_set_style_pad_all(screen, 24, 0);
  lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);

  lv_obj_t *title = lv_label_create(screen);
  lv_label_set_text(title, "Settings");
  lv_obj_set_style_text_font(title, &lv_font_montserrat_28, 0);
  lv_obj_set_style_text_color(title, coffee_ui_color_text(), 0);

  lv_obj_t *language = lv_label_create(screen);
  lv_label_set_text(language, "Language: English");
  lv_obj_set_style_text_color(language, lv_color_hex(0xb6c0ca), 0);

  lv_obj_t *brightness = lv_label_create(screen);
  lv_label_set_text(brightness, "Brightness simulation");
  lv_obj_set_style_text_color(brightness, lv_color_hex(0xb6c0ca), 0);

  lv_obj_t *slider = lv_slider_create(screen);
  lv_obj_set_width(slider, LV_PCT(70));
  lv_slider_set_range(slider, 20, 100);
  lv_slider_set_value(slider, 85, LV_ANIM_OFF);

  lv_obj_t *sound = lv_label_create(screen);
  lv_label_set_text(sound, "Sound simulation");
  lv_obj_set_style_text_color(sound, lv_color_hex(0xb6c0ca), 0);

  lv_obj_t *sw = lv_switch_create(screen);
  lv_obj_add_state(sw, LV_STATE_CHECKED);

  lv_obj_t *home = lv_button_create(screen);
  lv_obj_set_size(home, 180, 54);
  lv_obj_add_event_cb(home, home_cb, LV_EVENT_CLICKED, ui);
  lv_obj_t *home_label = lv_label_create(home);
  lv_label_set_text(home_label, "Home");
  lv_obj_center(home_label);

  lv_screen_load(screen);
}
