#include "ui/screens/screens.h"

#include "ui/ui_manager.h"
#include "ui/ui_theme.h"

static void stop_cb(lv_event_t *e)
{
    coffee_app_controller_cancel(((coffee_ui_manager_t *)lv_event_get_user_data(e))->app);
}

void coffee_screen_show_dispense(coffee_ui_manager_t *ui)
{
    const coffee_beverage_t *beverage = coffee_app_controller_selected(ui->app);
    lv_obj_t *screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen, coffee_ui_color_bg(), 0);
    lv_obj_set_style_pad_all(screen, 32, 0);
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(screen, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    lv_obj_t *title = lv_label_create(screen);
    lv_label_set_text_fmt(title, "Preparing %s",
                          beverage != NULL ? beverage->display_name : "drink");
    lv_obj_set_style_text_font(title, &lv_font_montserrat_32, 0);
    lv_obj_set_style_text_color(title, coffee_ui_color_text(), 0);

    ui->step_label = lv_label_create(screen);
    lv_obj_set_style_text_color(ui->step_label, coffee_ui_color_primary(), 0);

    ui->progress_bar = lv_bar_create(screen);
    lv_obj_set_size(ui->progress_bar, LV_PCT(76), 34);
    lv_bar_set_range(ui->progress_bar, 0, 100);

    ui->progress_label = lv_label_create(screen);
    lv_obj_set_style_text_color(ui->progress_label, lv_color_hex(0xb6c0ca), 0);

    lv_obj_t *stop = lv_button_create(screen);
    lv_obj_set_size(stop, 200, 58);
    lv_obj_set_style_bg_color(stop, coffee_ui_color_warning(), 0);
    lv_obj_add_event_cb(stop, stop_cb, LV_EVENT_CLICKED, ui);
    lv_obj_t *stop_label = lv_label_create(stop);
    lv_label_set_text(stop_label, "Stop");
    lv_obj_center(stop_label);

    lv_screen_load(screen);
    coffee_screen_update_dispense(ui);
}

void coffee_screen_update_dispense(coffee_ui_manager_t *ui)
{
    coffee_dispense_snapshot_t snap = coffee_app_controller_dispense(ui->app);
    if (ui->progress_bar != NULL)
        lv_bar_set_value(ui->progress_bar, snap.progress_pct, LV_ANIM_ON);
    if (ui->step_label != NULL)
        lv_label_set_text(ui->step_label,
                          snap.current_step != NULL ? snap.current_step : "Working");
    if (ui->progress_label != NULL) {
        lv_label_set_text_fmt(ui->progress_label, "%u%%  |  %u s remaining", snap.progress_pct,
                              snap.remaining_s);
    }
}

static void done_home_cb(lv_event_t *e)
{
    coffee_app_controller_home(((coffee_ui_manager_t *)lv_event_get_user_data(e))->app);
}

void coffee_screen_show_completion(coffee_ui_manager_t *ui, bool cancelled)
{
    const coffee_beverage_t *beverage = coffee_app_controller_selected(ui->app);
    lv_obj_t *screen = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(screen, coffee_ui_color_bg(), 0);
    lv_obj_set_style_pad_all(screen, 34, 0);
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(screen, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);

    lv_obj_t *title = lv_label_create(screen);
    lv_label_set_text(title, cancelled ? "Dispensing cancelled" : "Drink ready");
    lv_obj_set_style_text_font(title, &lv_font_montserrat_32, 0);
    lv_obj_set_style_text_color(
        title, cancelled ? coffee_ui_color_warning() : coffee_ui_color_primary(), 0);

    lv_obj_t *message = lv_label_create(screen);
    lv_label_set_text_fmt(message, cancelled ? "The cycle stopped safely." : "%s is complete.",
                          beverage != NULL ? beverage->display_name : "Your drink");
    lv_obj_set_style_text_color(message, coffee_ui_color_text(), 0);

    lv_obj_t *home = lv_button_create(screen);
    lv_obj_set_size(home, 220, 58);
    lv_obj_add_event_cb(home, done_home_cb, LV_EVENT_CLICKED, ui);
    lv_obj_t *label = lv_label_create(home);
    lv_label_set_text(label, "Home");
    lv_obj_center(label);

    lv_screen_load(screen);
}
