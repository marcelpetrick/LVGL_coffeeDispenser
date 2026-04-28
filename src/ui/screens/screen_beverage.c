#include "ui/screens/screens.h"

#include "ui/ui_manager.h"
#include "ui/ui_theme.h"

static void confirm_cb(lv_event_t *e)
{
    coffee_app_controller_confirm(((coffee_ui_manager_t *)lv_event_get_user_data(e))->app);
}

static void cancel_cb(lv_event_t *e)
{
    coffee_app_controller_cancel(((coffee_ui_manager_t *)lv_event_get_user_data(e))->app);
}

void coffee_screen_show_beverage(coffee_ui_manager_t *ui)
{
    const coffee_beverage_t *beverage = coffee_app_controller_selected(ui->app);
    lv_obj_t *screen = lv_obj_create(NULL);
    coffee_ui_apply_screen_background(screen);
    lv_obj_set_style_pad_all(screen, 30, 0);

    lv_obj_t *panel = lv_obj_create(screen);
    lv_obj_set_size(panel, LV_PCT(92), LV_PCT(86));
    lv_obj_center(panel);
    lv_obj_set_style_radius(panel, 8, 0);
    coffee_ui_apply_glass_panel(panel, LV_OPA_80);
    lv_obj_set_style_pad_all(panel, 28, 0);
    lv_obj_set_flex_flow(panel, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(panel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    lv_obj_t *title = lv_label_create(panel);
    lv_label_set_text_fmt(title, "%s %s", beverage->symbol, beverage->display_name);
    lv_obj_set_style_text_font(title, &lv_font_montserrat_32, 0);
    lv_obj_set_style_text_color(title, coffee_ui_color_text(), 0);

    lv_obj_t *info = lv_label_create(panel);
    lv_label_set_text_fmt(info, "%u ml  |  about %u s  |  %s", ui->app->request.volume_ml,
                          ui->app->request.estimated_time_s,
                          coffee_beverage_option_label(ui->app->request.option));
    lv_obj_set_style_text_color(info, lv_color_hex(0xb6c0ca), 0);

    lv_obj_t *note = lv_label_create(panel);
    lv_label_set_text(note, beverage->id == COFFEE_BEV_HOT_WATER
                                ? "Hot water requires explicit confirmation."
                                : "Confirm to start the simulated dispenser.");
    lv_obj_set_style_text_color(note,
                                beverage->id == COFFEE_BEV_HOT_WATER ? coffee_ui_color_warning()
                                                                     : coffee_ui_color_primary(),
                                0);

    lv_obj_t *actions = lv_obj_create(panel);
    lv_obj_set_width(actions, LV_PCT(100));
    lv_obj_set_height(actions, 86);
    lv_obj_set_style_bg_opa(actions, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(actions, 0, 0);
    lv_obj_set_flex_flow(actions, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(actions, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);

    lv_obj_t *cancel = lv_button_create(actions);
    lv_obj_set_size(cancel, 180, 58);
    lv_obj_add_event_cb(cancel, cancel_cb, LV_EVENT_CLICKED, ui);
    lv_obj_t *cancel_label = lv_label_create(cancel);
    lv_label_set_text(cancel_label, "Cancel");
    lv_obj_center(cancel_label);

    lv_obj_t *confirm = lv_button_create(actions);
    lv_obj_set_size(confirm, 220, 58);
    lv_obj_set_style_bg_color(confirm, coffee_ui_color_primary(), 0);
    lv_obj_add_event_cb(confirm, confirm_cb, LV_EVENT_CLICKED, ui);
    lv_obj_t *confirm_label = lv_label_create(confirm);
    lv_label_set_text(confirm_label, "Start");
    lv_obj_center(confirm_label);

    lv_screen_load(screen);
}
