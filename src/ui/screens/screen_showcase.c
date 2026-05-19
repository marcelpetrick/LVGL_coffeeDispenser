#include "ui/screens/screens.h"

#include "ui/assets/beverage_icons.h"
#include "ui/ui_manager.h"
#include "ui/ui_theme.h"

#include <stdint.h>

#define SHOWCASE_SECTION_WIDTH LV_PCT(100)
#define SHOWCASE_CARD_WIDTH 224
#define SHOWCASE_CARD_HEIGHT 138
#define SHOWCASE_ROW_GAP 14
#define SHOWCASE_CARD_GAP 12

static void home_cb(lv_event_t *e)
{
    coffee_screen_show_home(lv_event_get_user_data(e));
}

static void slider_label_cb(lv_event_t *e)
{
    lv_obj_t *slider = lv_event_get_target_obj(e);
    lv_obj_t *label = lv_event_get_user_data(e);
    lv_label_set_text_fmt(label, "%ld", (long)lv_slider_get_value(slider));
}

static void arc_label_cb(lv_event_t *e)
{
    lv_obj_t *arc = lv_event_get_target_obj(e);
    lv_obj_t *label = lv_event_get_user_data(e);
    lv_label_set_text_fmt(label, "%ld%%", (long)lv_arc_get_value(arc));
}

static void style_slider_cb(lv_event_t *e)
{
    lv_obj_t *slider = lv_event_get_target_obj(e);
    int32_t value = lv_slider_get_value(slider);
    lv_obj_t *sample = lv_event_get_user_data(e);
    lv_obj_set_style_bg_color(sample, lv_color_make((uint8_t)value, 142, 74), 0);
}

static void color_toggle_cb(lv_event_t *e)
{
    lv_obj_t *btn = lv_event_get_target_obj(e);
    if (lv_obj_has_state(btn, LV_STATE_CHECKED)) {
        lv_obj_set_style_bg_color(btn, lv_color_hex(0x2b8da3), 0);
    } else {
        lv_obj_set_style_bg_color(btn, coffee_ui_color_primary(), 0);
    }
}

static void draggable_cb(lv_event_t *e)
{
    lv_obj_t *obj = lv_event_get_target_obj(e);
    lv_indev_t *indev = lv_indev_active();
    if (indev == NULL) {
        return;
    }

    lv_point_t vect;
    lv_indev_get_vect(indev, &vect);
    lv_obj_set_pos(obj, lv_obj_get_x(obj) + vect.x, lv_obj_get_y(obj) + vect.y);
}

#if LV_USE_MSGBOX
static void msgbox_close_cb(lv_event_t *e)
{
    lv_obj_t *footer = lv_obj_get_parent(lv_event_get_target_obj(e));
    lv_msgbox_close(lv_obj_get_parent(footer));
}

static void msgbox_open_cb(lv_event_t *e)
{
    LV_UNUSED(e);
    lv_obj_t *box = lv_msgbox_create(NULL);
    lv_msgbox_add_title(box, "lv_msgbox");
    lv_msgbox_add_text(box, "Modal message box with header, content, footer and close action.");
    lv_obj_t *close = lv_msgbox_add_footer_button(box, "Close");
    lv_obj_add_event_cb(close, msgbox_close_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_center(box);
}
#endif

static lv_obj_t *create_section(lv_obj_t *parent, const char *title)
{
    lv_obj_t *section = lv_obj_create(parent);
    lv_obj_set_width(section, SHOWCASE_SECTION_WIDTH);
    lv_obj_set_height(section, LV_SIZE_CONTENT);
    coffee_ui_apply_glass_panel(section, LV_OPA_70);
    lv_obj_set_style_radius(section, 8, 0);
    lv_obj_set_style_pad_all(section, 14, 0);
    lv_obj_set_style_pad_row(section, SHOWCASE_ROW_GAP, 0);
    lv_obj_set_flex_flow(section, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(section, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);

    lv_obj_t *label = lv_label_create(section);
    lv_label_set_text(label, title);
    lv_obj_set_style_text_font(label, &lv_font_montserrat_22, 0);
    lv_obj_set_style_text_color(label, coffee_ui_color_text(), 0);

    return section;
}

static lv_obj_t *create_card_row(lv_obj_t *parent)
{
    lv_obj_t *row = lv_obj_create(parent);
    lv_obj_remove_style_all(row);
    lv_obj_set_width(row, LV_PCT(100));
    lv_obj_set_height(row, LV_SIZE_CONTENT);
    lv_obj_set_flex_flow(row, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_flex_align(row, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_pad_row(row, SHOWCASE_CARD_GAP, 0);
    lv_obj_set_style_pad_column(row, SHOWCASE_CARD_GAP, 0);
    return row;
}

static lv_obj_t *create_card(lv_obj_t *parent, const char *title)
{
    lv_obj_t *card = lv_obj_create(parent);
    lv_obj_set_size(card, SHOWCASE_CARD_WIDTH, SHOWCASE_CARD_HEIGHT);
    lv_obj_set_style_min_width(card, SHOWCASE_CARD_WIDTH, 0);
    lv_obj_set_style_min_height(card, SHOWCASE_CARD_HEIGHT, 0);
    lv_obj_set_style_bg_color(card, lv_color_hex(0x202936), 0);
    lv_obj_set_style_bg_opa(card, LV_OPA_80, 0);
    lv_obj_set_style_border_color(card, lv_color_hex(0x6f7d8a), 0);
    lv_obj_set_style_border_opa(card, LV_OPA_30, 0);
    lv_obj_set_style_border_width(card, 1, 0);
    lv_obj_set_style_radius(card, 8, 0);
    lv_obj_set_style_pad_all(card, 10, 0);
    lv_obj_set_style_pad_row(card, 8, 0);
    lv_obj_set_flex_flow(card, LV_FLEX_FLOW_COLUMN);

    lv_obj_t *label = lv_label_create(card);
    lv_label_set_text(label, title);
    lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(label, LV_PCT(100));
    lv_obj_set_style_text_color(label, coffee_ui_color_primary(), 0);

    return card;
}

static lv_obj_t *create_button_with_label(lv_obj_t *parent, const char *text)
{
    lv_obj_t *btn = lv_button_create(parent);
    lv_obj_set_size(btn, 150, 42);
    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, text);
    lv_obj_center(label);
    return btn;
}

static void add_basic_widgets(lv_obj_t *parent)
{
    lv_obj_t *section = create_section(parent, "Basic Widgets");
    lv_obj_t *row = create_card_row(section);

#if LV_USE_BUTTON
    lv_obj_t *button_card = create_card(row, "lv_button");
    create_button_with_label(button_card, "Push");

    lv_obj_t *toggle_card = create_card(row, "lv_button checked state");
    lv_obj_t *toggle = create_button_with_label(toggle_card, "Toggle");
    lv_obj_add_flag(toggle, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_style_bg_color(toggle, lv_color_hex(0x46515f), 0);
    lv_obj_set_style_bg_color(toggle, coffee_ui_color_primary(), LV_STATE_CHECKED);
#endif

#if LV_USE_LABEL
    lv_obj_t *label_card = create_card(row, "lv_label");
    lv_obj_t *label = lv_label_create(label_card);
    lv_label_set_text(label, "Wrapped label text for embedded HMIs.");
    lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(label, LV_PCT(100));
    lv_obj_set_style_text_color(label, coffee_ui_color_text(), 0);
#endif

#if LV_USE_IMAGE
    lv_obj_t *image_card = create_card(row, "lv_image");
    lv_obj_t *image = lv_image_create(image_card);
    lv_image_set_src(image, &coffee_icon_coffee);
    lv_image_set_scale(image, 116);
    lv_obj_center(image);
#endif
}

static void add_input_widgets(lv_obj_t *parent)
{
    lv_obj_t *section = create_section(parent, "Input Widgets");
    lv_obj_t *row = create_card_row(section);

#if LV_USE_SLIDER
    lv_obj_t *slider_card = create_card(row, "lv_slider");
    lv_obj_t *value = lv_label_create(slider_card);
    lv_label_set_text(value, "45");
    lv_obj_set_style_text_color(value, coffee_ui_color_text(), 0);
    lv_obj_t *slider = lv_slider_create(slider_card);
    lv_obj_set_width(slider, LV_PCT(92));
    lv_slider_set_range(slider, 0, 100);
    lv_slider_set_value(slider, 45, LV_ANIM_OFF);
    lv_obj_add_event_cb(slider, slider_label_cb, LV_EVENT_VALUE_CHANGED, value);
#endif

#if LV_USE_SWITCH
    lv_obj_t *switch_card = create_card(row, "lv_switch");
    lv_obj_t *sw = lv_switch_create(switch_card);
    lv_obj_add_state(sw, LV_STATE_CHECKED);
#endif

#if LV_USE_CHECKBOX
    lv_obj_t *checkbox_card = create_card(row, "lv_checkbox");
    lv_obj_t *checkbox = lv_checkbox_create(checkbox_card);
    lv_checkbox_set_text(checkbox, "Milk foam");
    lv_obj_set_style_text_color(checkbox, coffee_ui_color_text(), 0);
#endif

#if LV_USE_DROPDOWN
    lv_obj_t *dropdown_card = create_card(row, "lv_dropdown");
    lv_obj_t *dropdown = lv_dropdown_create(dropdown_card);
    lv_dropdown_set_options_static(dropdown, "Small\nMedium\nLarge");
    lv_obj_set_width(dropdown, LV_PCT(92));
#endif

#if LV_USE_ROLLER
    lv_obj_t *roller_card = create_card(row, "lv_roller");
    lv_obj_set_height(roller_card, 174);
    lv_obj_t *roller = lv_roller_create(roller_card);
    lv_roller_set_options(roller, "Mild\nClassic\nStrong\nExtra", LV_ROLLER_MODE_NORMAL);
    lv_roller_set_visible_row_count(roller, 3);
    lv_obj_set_width(roller, LV_PCT(92));
#endif

#if LV_USE_TEXTAREA
    lv_obj_t *text_card = create_card(row, "lv_textarea + lv_keyboard");
    lv_obj_set_size(text_card, 456, 250);
    lv_obj_t *textarea = lv_textarea_create(text_card);
    lv_obj_set_width(textarea, LV_PCT(96));
    lv_textarea_set_one_line(textarea, true);
    lv_textarea_set_placeholder_text(textarea, "Enter label text");
#if LV_USE_KEYBOARD
    lv_obj_t *keyboard = lv_keyboard_create(text_card);
    lv_obj_set_size(keyboard, LV_PCT(96), 154);
    lv_keyboard_set_textarea(keyboard, textarea);
#endif
#endif

#if LV_USE_SPINBOX
    lv_obj_t *spinbox_card = create_card(row, "lv_spinbox");
    lv_obj_t *spinbox = lv_spinbox_create(spinbox_card);
    lv_spinbox_set_range(spinbox, 0, 250);
    lv_spinbox_set_digit_format(spinbox, 3, 0);
    lv_obj_set_width(spinbox, 110);
#endif
}

static void add_indicator_widgets(lv_obj_t *parent)
{
    lv_obj_t *section = create_section(parent, "Indicators");
    lv_obj_t *row = create_card_row(section);

#if LV_USE_ARC
    lv_obj_t *arc_card = create_card(row, "lv_arc");
    lv_obj_t *value = lv_label_create(arc_card);
    lv_label_set_text(value, "62%");
    lv_obj_set_style_text_color(value, coffee_ui_color_text(), 0);
    lv_obj_t *arc = lv_arc_create(arc_card);
    lv_obj_set_size(arc, 88, 88);
    lv_arc_set_range(arc, 0, 100);
    lv_arc_set_value(arc, 62);
    lv_obj_add_event_cb(arc, arc_label_cb, LV_EVENT_VALUE_CHANGED, value);
#endif

#if LV_USE_BAR
    lv_obj_t *bar_card = create_card(row, "lv_bar");
    lv_obj_t *bar = lv_bar_create(bar_card);
    lv_obj_set_width(bar, LV_PCT(92));
    lv_bar_set_range(bar, 0, 100);
    lv_bar_set_value(bar, 72, LV_ANIM_OFF);
#endif

#if LV_USE_CHART
    lv_obj_t *chart_card = create_card(row, "lv_chart");
    lv_obj_set_height(chart_card, 182);
    lv_obj_t *chart = lv_chart_create(chart_card);
    lv_obj_set_size(chart, LV_PCT(96), 112);
    lv_chart_set_type(chart, LV_CHART_TYPE_LINE);
    lv_chart_set_point_count(chart, 6);
    lv_chart_set_axis_range(chart, LV_CHART_AXIS_PRIMARY_Y, 0, 100);
    lv_chart_series_t *series =
        lv_chart_add_series(chart, coffee_ui_color_primary(), LV_CHART_AXIS_PRIMARY_Y);
    if (series != NULL) {
        lv_chart_set_next_value(chart, series, 20);
        lv_chart_set_next_value(chart, series, 38);
        lv_chart_set_next_value(chart, series, 62);
        lv_chart_set_next_value(chart, series, 48);
        lv_chart_set_next_value(chart, series, 74);
        lv_chart_set_next_value(chart, series, 86);
    }
#endif

#if LV_USE_SCALE
    lv_obj_t *scale_card = create_card(row, "lv_scale");
    lv_obj_t *scale = lv_scale_create(scale_card);
    lv_obj_set_size(scale, 174, 56);
    lv_scale_set_mode(scale, LV_SCALE_MODE_HORIZONTAL_BOTTOM);
    lv_scale_set_total_tick_count(scale, 6);
    lv_scale_set_major_tick_every(scale, 1);
#endif
}

static void add_layout_examples(lv_obj_t *parent)
{
    lv_obj_t *section = create_section(parent, "Layouts and Containers");
    lv_obj_t *row = create_card_row(section);

#if LV_USE_FLEX
    lv_obj_t *flex_card = create_card(row, "LV_LAYOUT_FLEX");
    lv_obj_t *flex = lv_obj_create(flex_card);
    lv_obj_set_size(flex, LV_PCT(92), 78);
    lv_obj_set_flex_flow(flex, LV_FLEX_FLOW_ROW_WRAP);
    lv_obj_set_style_pad_all(flex, 6, 0);
    lv_obj_set_style_pad_gap(flex, 6, 0);
    for (int32_t i = 0; i < 5; ++i) {
        lv_obj_t *box = lv_obj_create(flex);
        lv_obj_set_size(box, 42, 24);
        lv_obj_set_style_bg_color(box, lv_palette_main((lv_palette_t)(LV_PALETTE_RED + i)), 0);
        lv_obj_set_style_radius(box, 6, 0);
    }
#endif

#if LV_USE_GRID
    lv_obj_t *grid_card = create_card(row, "LV_LAYOUT_GRID");
    lv_obj_t *grid = lv_obj_create(grid_card);
    lv_obj_set_size(grid, LV_PCT(92), 78);
    static int32_t cols[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static int32_t rows[] = {LV_GRID_FR(1), LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    lv_obj_set_grid_dsc_array(grid, cols, rows);
    for (int32_t i = 0; i < 4; ++i) {
        lv_obj_t *box = lv_obj_create(grid);
        lv_obj_set_grid_cell(box, LV_GRID_ALIGN_STRETCH, i % 2, 1, LV_GRID_ALIGN_STRETCH, i / 2, 1);
        lv_obj_set_style_bg_color(box, lv_color_hex(0x2b8da3 + (uint32_t)i * 0x101010U), 0);
    }
#endif

    lv_obj_t *align_card = create_card(row, "lv_obj_align");
    lv_obj_t *align_area = lv_obj_create(align_card);
    lv_obj_set_size(align_area, LV_PCT(92), 78);
    lv_obj_t *dot = lv_obj_create(align_area);
    lv_obj_set_size(dot, 28, 28);
    lv_obj_set_style_radius(dot, LV_RADIUS_CIRCLE, 0);
    lv_obj_set_style_bg_color(dot, coffee_ui_color_primary(), 0);
    lv_obj_align(dot, LV_ALIGN_BOTTOM_RIGHT, -8, -8);

    lv_obj_t *scroll_card = create_card(row, "LV_OBJ_FLAG_SCROLLABLE");
    lv_obj_t *scroll = lv_obj_create(scroll_card);
    lv_obj_set_size(scroll, LV_PCT(92), 78);
    lv_obj_set_scroll_dir(scroll, LV_DIR_VER);
    lv_obj_set_flex_flow(scroll, LV_FLEX_FLOW_COLUMN);
    for (int32_t i = 0; i < 5; ++i) {
        lv_obj_t *item = lv_label_create(scroll);
        lv_label_set_text_fmt(item, "Scrollable item %ld", (long)i + 1);
    }

    lv_obj_t *drag_card = create_card(row, "Draggable lv_obj");
    lv_obj_t *drag_area = lv_obj_create(drag_card);
    lv_obj_set_size(drag_area, LV_PCT(92), 78);
    lv_obj_t *drag = lv_obj_create(drag_area);
    lv_obj_set_size(drag, 54, 34);
    lv_obj_set_style_radius(drag, 8, 0);
    lv_obj_set_style_bg_color(drag, coffee_ui_color_primary(), 0);
    lv_obj_add_flag(drag, LV_OBJ_FLAG_CLICKABLE);
    lv_obj_add_event_cb(drag, draggable_cb, LV_EVENT_PRESSING, NULL);
}

static void add_styling_examples(lv_obj_t *parent)
{
    lv_obj_t *section = create_section(parent, "Styles and Colors");
    lv_obj_t *row = create_card_row(section);

    lv_obj_t *state_card = create_card(row, "Styles: checked/pressed");
    lv_obj_t *toggle = create_button_with_label(state_card, "Color");
    lv_obj_add_flag(toggle, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_style_bg_color(toggle, coffee_ui_color_primary(), 0);
    lv_obj_set_style_bg_color(toggle, lv_color_hex(0x2b8da3), LV_STATE_PRESSED);
    lv_obj_add_event_cb(toggle, color_toggle_cb, LV_EVENT_VALUE_CHANGED, NULL);

    lv_obj_t *border_card = create_card(row, "Borders, radius, padding");
    lv_obj_t *sample = lv_obj_create(border_card);
    lv_obj_set_size(sample, LV_PCT(88), 56);
    lv_obj_set_style_bg_color(sample, lv_color_hex(0x2b8da3), 0);
    lv_obj_set_style_bg_opa(sample, LV_OPA_70, 0);
    lv_obj_set_style_border_width(sample, 3, 0);
    lv_obj_set_style_border_color(sample, coffee_ui_color_primary(), 0);
    lv_obj_set_style_radius(sample, 14, 0);
    lv_obj_set_style_pad_all(sample, 8, 0);

#if LV_USE_SLIDER
    lv_obj_t *dynamic_card = create_card(row, "Dynamic style update");
    lv_obj_t *style_sample_box = lv_obj_create(dynamic_card);
    lv_obj_set_size(style_sample_box, LV_PCT(88), 42);
    lv_obj_set_style_radius(style_sample_box, 8, 0);
    lv_obj_set_style_bg_color(style_sample_box, lv_color_make(180, 142, 74), 0);
    lv_obj_t *slider = lv_slider_create(dynamic_card);
    lv_obj_set_width(slider, LV_PCT(88));
    lv_slider_set_range(slider, 70, 240);
    lv_slider_set_value(slider, 180, LV_ANIM_OFF);
    lv_obj_add_event_cb(slider, style_slider_cb, LV_EVENT_VALUE_CHANGED, style_sample_box);
#endif

    lv_obj_t *text_card = create_card(row, "Text color");
    lv_obj_t *label = lv_label_create(text_card);
    lv_label_set_text(label, "Primary, warning, and neutral text styles");
    lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(label, LV_PCT(100));
    lv_obj_set_style_text_color(label, coffee_ui_color_warning(), 0);
}

static void add_advanced_widgets(lv_obj_t *parent)
{
    lv_obj_t *section = create_section(parent, "Optional Widgets");
    lv_obj_t *row = create_card_row(section);

#if LV_USE_TABVIEW
    lv_obj_t *tab_card = create_card(row, "lv_tabview");
    lv_obj_set_size(tab_card, 456, 220);
    lv_obj_t *tabs = lv_tabview_create(tab_card);
    lv_obj_set_size(tabs, LV_PCT(96), 156);
    lv_obj_t *one = lv_tabview_add_tab(tabs, "One");
    lv_obj_t *two = lv_tabview_add_tab(tabs, "Two");
    lv_obj_t *label_one = lv_label_create(one);
    lv_label_set_text(label_one, "Tab content");
    lv_obj_t *label_two = lv_label_create(two);
    lv_label_set_text(label_two, "Second tab");
#endif

#if LV_USE_LIST
    lv_obj_t *list_card = create_card(row, "lv_list");
    lv_obj_set_height(list_card, 190);
    lv_obj_t *list = lv_list_create(list_card);
    lv_obj_set_size(list, LV_PCT(92), 122);
    lv_list_add_text(list, "Recipes");
    lv_list_add_button(list, NULL, "Espresso");
    lv_list_add_button(list, NULL, "Cappuccino");
    lv_list_add_button(list, NULL, "Hot water");
#endif

#if LV_USE_TABLE
    lv_obj_t *table_card = create_card(row, "lv_table");
    lv_obj_set_size(table_card, 456, 206);
    lv_obj_t *table = lv_table_create(table_card);
    lv_obj_set_size(table, LV_PCT(96), 138);
    lv_table_set_cell_value(table, 0, 0, "Widget");
    lv_table_set_cell_value(table, 0, 1, "Status");
    lv_table_set_cell_value(table, 1, 0, "LVGL 9");
    lv_table_set_cell_value(table, 1, 1, "enabled");
    lv_table_set_cell_value(table, 2, 0, "Layouts");
    lv_table_set_cell_value(table, 2, 1, "flex/grid");
#endif

#if LV_USE_MSGBOX
    lv_obj_t *msgbox_card = create_card(row, "lv_msgbox");
    lv_obj_t *open = create_button_with_label(msgbox_card, "Open modal");
    lv_obj_add_event_cb(open, msgbox_open_cb, LV_EVENT_CLICKED, NULL);
#endif

#if LV_USE_CALENDAR
    lv_obj_t *calendar_card = create_card(row, "lv_calendar");
    lv_obj_set_size(calendar_card, 456, 260);
    lv_obj_t *calendar = lv_calendar_create(calendar_card);
    lv_obj_set_size(calendar, LV_PCT(96), 194);
    lv_calendar_set_today_date(calendar, 2026, 5, 19);
    lv_calendar_set_month_shown(calendar, 2026, 5);
#endif
}

void coffee_screen_show_showcase(coffee_ui_manager_t *ui)
{
    lv_obj_t *screen = lv_obj_create(NULL);
    coffee_ui_apply_screen_background(screen);
    lv_obj_set_style_pad_all(screen, 18, 0);
    lv_obj_set_flex_flow(screen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_style_pad_row(screen, 14, 0);

    lv_obj_t *header = lv_obj_create(screen);
    lv_obj_set_width(header, LV_PCT(100));
    lv_obj_set_height(header, 70);
    coffee_ui_apply_glass_panel(header, LV_OPA_70);
    lv_obj_set_style_radius(header, 8, 0);
    lv_obj_set_flex_flow(header, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(header, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER,
                          LV_FLEX_ALIGN_CENTER);

    lv_obj_t *title = lv_label_create(header);
    lv_label_set_text_fmt(title, "LVGL Showcase %d.%d.%d", LVGL_VERSION_MAJOR, LVGL_VERSION_MINOR,
                          LVGL_VERSION_PATCH);
    lv_obj_set_style_text_font(title, &lv_font_montserrat_28, 0);
    lv_obj_set_style_text_color(title, coffee_ui_color_text(), 0);

    lv_obj_t *back = create_button_with_label(header, "Back");
    lv_obj_add_event_cb(back, home_cb, LV_EVENT_CLICKED, ui);

    lv_obj_t *content = lv_obj_create(screen);
    lv_obj_set_width(content, LV_PCT(100));
    lv_obj_set_flex_grow(content, 1);
    lv_obj_set_style_bg_opa(content, LV_OPA_TRANSP, 0);
    lv_obj_set_style_border_width(content, 0, 0);
    lv_obj_set_style_pad_all(content, 0, 0);
    lv_obj_set_style_pad_row(content, 14, 0);
    lv_obj_set_flex_flow(content, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_scroll_dir(content, LV_DIR_VER);
    lv_obj_set_scrollbar_mode(content, LV_SCROLLBAR_MODE_AUTO);

    add_basic_widgets(content);
    add_input_widgets(content);
    add_indicator_widgets(content);
    add_layout_examples(content);
    add_styling_examples(content);
    add_advanced_widgets(content);

    lv_screen_load(screen);
}
