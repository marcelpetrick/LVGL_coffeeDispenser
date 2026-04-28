#include "ui/screens/screens.h"

#include "ui/ui_manager.h"
#include "ui/ui_theme.h"

#include <stdint.h>

static void select_cb(lv_event_t *e) {
  coffee_ui_manager_t *ui = lv_event_get_user_data(e);
  uintptr_t raw = (uintptr_t)lv_obj_get_user_data(lv_event_get_target_obj(e));
  coffee_beverage_id_t id = (coffee_beverage_id_t)raw;
  const coffee_beverage_t *beverage = coffee_beverage_get(id);
  if (beverage != NULL && beverage->option_count > 0) {
    coffee_app_controller_select(ui->app, id,
                                 beverage->options[beverage->option_count / 2]);
  }
}

static void settings_cb(lv_event_t *e) {
  coffee_screen_show_settings(lv_event_get_user_data(e));
}

static void diagnostics_cb(lv_event_t *e) {
  coffee_screen_show_diagnostics(lv_event_get_user_data(e));
}

static lv_obj_t *make_button(lv_obj_t *parent, const char *text,
                             lv_event_cb_t cb, void *user_data) {
  lv_obj_t *btn = lv_button_create(parent);
  lv_obj_set_size(btn, LV_PCT(100), 54);
  lv_obj_add_event_cb(btn, cb, LV_EVENT_CLICKED, user_data);
  lv_obj_t *label = lv_label_create(btn);
  lv_label_set_text(label, text);
  lv_obj_center(label);
  return btn;
}

void coffee_screen_show_splash(coffee_ui_manager_t *ui) {
  LV_UNUSED(ui);
  lv_obj_t *screen = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(screen, coffee_ui_color_bg(), 0);
  lv_obj_set_style_pad_all(screen, 32, 0);

  lv_obj_t *title = lv_label_create(screen);
  lv_label_set_text(title, "Coffee Dispenser");
  lv_obj_set_style_text_color(title, coffee_ui_color_text(), 0);
  lv_obj_set_style_text_font(title, &lv_font_montserrat_32, 0);
  lv_obj_align(title, LV_ALIGN_CENTER, 0, -28);

  lv_obj_t *sub = lv_label_create(screen);
  lv_label_set_text(sub, "LVGL desktop prototype");
  lv_obj_set_style_text_color(sub, lv_color_hex(0xb6c0ca), 0);
  lv_obj_align(sub, LV_ALIGN_CENTER, 0, 20);
  lv_screen_load(screen);
}

void coffee_screen_show_home(coffee_ui_manager_t *ui) {
  lv_obj_t *screen = lv_obj_create(NULL);
  lv_obj_set_style_bg_color(screen, coffee_ui_color_bg(), 0);
  lv_obj_set_style_pad_all(screen, 18, 0);
  lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);
  lv_obj_set_flex_align(screen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER,
                        LV_FLEX_ALIGN_CENTER);

  coffee_machine_snapshot_t machine = coffee_app_controller_machine(ui->app);

  lv_obj_t *header = lv_obj_create(screen);
  lv_obj_set_width(header, LV_PCT(100));
  lv_obj_set_height(header, 70);
  lv_obj_set_style_bg_color(header, coffee_ui_color_panel(), 0);
  lv_obj_set_style_border_width(header, 0, 0);
  lv_obj_set_style_radius(header, 8, 0);
  lv_obj_set_flex_flow(header, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(header, LV_FLEX_ALIGN_SPACE_BETWEEN,
                        LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

  lv_obj_t *title = lv_label_create(header);
  lv_label_set_text(title, "Select drink");
  lv_obj_set_style_text_font(title, &lv_font_montserrat_28, 0);
  lv_obj_set_style_text_color(title, coffee_ui_color_text(), 0);

  lv_obj_t *status = lv_label_create(header);
  lv_label_set_text_fmt(status, "Status: %s",
                        coffee_machine_status_label(machine.status));
  lv_obj_set_style_text_color(status, coffee_ui_color_primary(), 0);

  lv_obj_t *grid = lv_obj_create(screen);
  lv_obj_set_width(grid, LV_PCT(100));
  lv_obj_set_flex_grow(grid, 1);
  lv_obj_set_style_bg_opa(grid, LV_OPA_TRANSP, 0);
  lv_obj_set_style_border_width(grid, 0, 0);
  lv_obj_set_style_pad_all(grid, 0, 0);
  lv_obj_set_layout(grid, LV_LAYOUT_GRID);
  static int32_t cols[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_FR(1),
                           LV_GRID_TEMPLATE_LAST};
  static int32_t rows[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
  lv_obj_set_grid_dsc_array(grid, cols, rows);

  size_t count = 0;
  const coffee_beverage_t *beverages = coffee_beverage_all(&count);
  for (size_t i = 0; i < count; ++i) {
    lv_obj_t *card = lv_button_create(grid);
    lv_obj_set_user_data(card, (void *)(uintptr_t)beverages[i].id);
    lv_obj_add_event_cb(card, select_cb, LV_EVENT_CLICKED, ui);
    lv_obj_set_grid_cell(card, LV_GRID_ALIGN_STRETCH, (int32_t)(i % 3), 1,
                         LV_GRID_ALIGN_STRETCH, (int32_t)(i / 3), 1);
    lv_obj_set_style_radius(card, 8, 0);
    lv_obj_set_style_bg_color(card,
                              beverages[i].id == COFFEE_BEV_HOT_WATER
                                  ? lv_color_hex(0x2c6f8f)
                                  : coffee_ui_color_panel(),
                              0);
    lv_obj_set_style_border_width(card, 1, 0);
    lv_obj_set_style_border_color(card, lv_color_hex(0x3b4652), 0);
    lv_obj_set_flex_flow(card, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(card, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);

    lv_obj_t *icon = lv_label_create(card);
    lv_label_set_text(icon, beverages[i].symbol);
    lv_obj_set_style_text_font(icon, &lv_font_montserrat_32, 0);
    lv_obj_set_style_text_color(icon, coffee_ui_color_primary(), 0);

    lv_obj_t *label = lv_label_create(card);
    lv_label_set_text(label, beverages[i].display_name);
    lv_obj_set_style_text_color(label, coffee_ui_color_text(), 0);
    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
  }

  lv_obj_t *nav = lv_obj_create(screen);
  lv_obj_set_width(nav, LV_PCT(100));
  lv_obj_set_height(nav, 62);
  lv_obj_set_style_bg_opa(nav, LV_OPA_TRANSP, 0);
  lv_obj_set_style_border_width(nav, 0, 0);
  lv_obj_set_flex_flow(nav, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(nav, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER,
                        LV_FLEX_ALIGN_CENTER);
  make_button(nav, "Settings", settings_cb, ui);
#if COFFEE_ENABLE_DIAGNOSTICS
  make_button(nav, "Diagnostics", diagnostics_cb, ui);
#endif

  lv_screen_load(screen);
}
