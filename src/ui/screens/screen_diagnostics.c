#include "ui/screens/screens.h"

#include "ui/ui_manager.h"
#include "ui/ui_theme.h"

static void home_cb(lv_event_t *e)
{
    coffee_screen_show_home(lv_event_get_user_data(e));
}

static void fail_cb(lv_event_t *e)
{
    LV_UNUSED(e);
}

void coffee_screen_show_diagnostics(coffee_ui_manager_t *ui)
{
    lv_obj_t *screen = lv_obj_create(NULL);
    coffee_ui_apply_screen_background(screen);
    lv_obj_set_style_pad_all(screen, 24, 0);
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);

    coffee_machine_snapshot_t machine = coffee_app_controller_machine(ui->app);

    lv_obj_t *title = lv_label_create(screen);
    lv_label_set_text(title, "Diagnostics");
    lv_obj_set_style_text_font(title, &lv_font_montserrat_28, 0);
    lv_obj_set_style_text_color(title, coffee_ui_color_text(), 0);

    lv_obj_t *info = lv_label_create(screen);
    lv_label_set_text_fmt(
        info,
        "App %s\nLVGL %d.%d.%d\nBackend SDL\nMachine: "
        "%s\nWater %s | Beans %s | Milk %s | Heater %s",
        COFFEE_APP_VERSION, LVGL_VERSION_MAJOR, LVGL_VERSION_MINOR, LVGL_VERSION_PATCH,
        coffee_machine_status_label(machine.status), machine.water_available ? "ok" : "empty",
        machine.beans_available ? "ok" : "empty", machine.milk_available ? "ok" : "unavailable",
        machine.heater_ready ? "ready" : "heating");
    lv_obj_set_style_text_color(info, lv_color_hex(0xb6c0ca), 0);

    lv_obj_t *test = lv_button_create(screen);
    lv_obj_set_size(test, 230, 54);
    lv_obj_add_event_cb(test, fail_cb, LV_EVENT_CLICKED, ui);
    lv_obj_t *test_label = lv_label_create(test);
    lv_label_set_text(test_label, "Pump test placeholder");
    lv_obj_center(test_label);

    lv_obj_t *home = lv_button_create(screen);
    lv_obj_set_size(home, 180, 54);
    lv_obj_add_event_cb(home, home_cb, LV_EVENT_CLICKED, ui);
    lv_obj_t *home_label = lv_label_create(home);
    lv_label_set_text(home_label, "Home");
    lv_obj_center(home_label);

    lv_screen_load(screen);
}
