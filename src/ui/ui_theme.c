#include "ui/ui_theme.h"

void coffee_ui_theme_apply(void) {
  lv_display_t *display = lv_display_get_default();
  lv_theme_t *theme = lv_theme_default_init(display, coffee_ui_color_primary(),
                                            lv_palette_main(LV_PALETTE_TEAL),
                                            true, LV_FONT_DEFAULT);
  lv_display_set_theme(display, theme);
}

lv_color_t coffee_ui_color_bg(void) { return lv_color_hex(0x111418); }

lv_color_t coffee_ui_color_panel(void) { return lv_color_hex(0x20262d); }

lv_color_t coffee_ui_color_primary(void) { return lv_color_hex(0xd8964a); }

lv_color_t coffee_ui_color_warning(void) { return lv_color_hex(0xd85c4a); }

lv_color_t coffee_ui_color_text(void) { return lv_color_hex(0xf5f0e8); }
