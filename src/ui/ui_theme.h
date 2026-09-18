#ifndef COFFEE_UI_THEME_H
#define COFFEE_UI_THEME_H

#include "lvgl.h"

void coffee_ui_theme_apply(void);

/**
 * Show a screen with the shared transition.
 *
 * Every screen is built fresh before it is shown, so the previous one is
 * deleted once the animation has finished.
 */
void coffee_ui_load_screen(lv_obj_t *screen);
void coffee_ui_apply_screen_background(lv_obj_t *screen);
void coffee_ui_apply_glass_panel(lv_obj_t *obj, uint8_t opa);
lv_color_t coffee_ui_color_bg(void);
lv_color_t coffee_ui_color_bg_bottom(void);
lv_color_t coffee_ui_color_panel(void);
lv_color_t coffee_ui_color_primary(void);
lv_color_t coffee_ui_color_warning(void);
lv_color_t coffee_ui_color_text(void);

#endif
