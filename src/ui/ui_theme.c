#include "ui/ui_theme.h"

void coffee_ui_theme_apply(void)
{
    lv_display_t *display = lv_display_get_default();
    lv_theme_t *theme =
        lv_theme_default_init(display, coffee_ui_color_primary(), lv_palette_main(LV_PALETTE_TEAL),
                              true, LV_FONT_DEFAULT);
    lv_display_set_theme(display, theme);
}

void coffee_ui_apply_screen_background(lv_obj_t *screen)
{
    lv_obj_set_style_bg_color(screen, coffee_ui_color_bg(), 0);
    lv_obj_set_style_bg_grad_color(screen, coffee_ui_color_bg_bottom(), 0);
    lv_obj_set_style_bg_grad_dir(screen, LV_GRAD_DIR_VER, 0);

    lv_obj_t *shine = lv_obj_create(screen);
    lv_obj_remove_style_all(shine);
    lv_obj_add_flag(shine, LV_OBJ_FLAG_IGNORE_LAYOUT);
    lv_obj_add_flag(shine, LV_OBJ_FLAG_FLOATING);
    lv_obj_set_size(shine, LV_PCT(70), LV_PCT(60));
    lv_obj_align(shine, LV_ALIGN_TOP_RIGHT, 120, -120);
    lv_obj_set_style_radius(shine, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(shine, lv_color_hex(0xf6c16e), 0);
    lv_obj_set_style_bg_opa(shine, LV_OPA_20, 0);

    lv_obj_t *cool_glow = lv_obj_create(screen);
    lv_obj_remove_style_all(cool_glow);
    lv_obj_add_flag(cool_glow, LV_OBJ_FLAG_IGNORE_LAYOUT);
    lv_obj_add_flag(cool_glow, LV_OBJ_FLAG_FLOATING);
    lv_obj_set_size(cool_glow, LV_PCT(56), LV_PCT(54));
    lv_obj_align(cool_glow, LV_ALIGN_BOTTOM_LEFT, -120, 120);
    lv_obj_set_style_radius(cool_glow, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(cool_glow, lv_color_hex(0x2b8da3), 0);
    lv_obj_set_style_bg_opa(cool_glow, LV_OPA_20, 0);
}

void coffee_ui_apply_glass_panel(lv_obj_t *obj, uint8_t opa)
{
    lv_obj_set_style_bg_color(obj, coffee_ui_color_panel(), 0);
    lv_obj_set_style_bg_grad_color(obj, lv_color_hex(0x303946), 0);
    lv_obj_set_style_bg_grad_dir(obj, LV_GRAD_DIR_VER, 0);
    lv_obj_set_style_bg_opa(obj, opa, 0);
    lv_obj_set_style_border_width(obj, 1, 0);
    lv_obj_set_style_border_color(obj, lv_color_hex(0x6f7d8a), 0);
    lv_obj_set_style_border_opa(obj, LV_OPA_30, 0);
    lv_obj_set_style_shadow_width(obj, 18, 0);
    lv_obj_set_style_shadow_opa(obj, LV_OPA_20, 0);
    lv_obj_set_style_shadow_color(obj, lv_color_hex(0x05080b), 0);
    lv_obj_set_style_shadow_offset_y(obj, 6, 0);
}

lv_color_t coffee_ui_color_bg(void)
{
    return lv_color_hex(0x111821);
}

lv_color_t coffee_ui_color_bg_bottom(void)
{
    return lv_color_hex(0x261b16);
}

lv_color_t coffee_ui_color_panel(void)
{
    return lv_color_hex(0x1d2530);
}

lv_color_t coffee_ui_color_primary(void)
{
    return lv_color_hex(0xd8964a);
}

lv_color_t coffee_ui_color_warning(void)
{
    return lv_color_hex(0xd85c4a);
}

lv_color_t coffee_ui_color_text(void)
{
    return lv_color_hex(0xf5f0e8);
}
