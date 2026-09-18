#include "ui/demo_tour.h"

#include "platform/platform_log.h"

#include <stdlib.h>
#include <string.h>

typedef struct {
    uint32_t at_ms;
    const char *caption;
} coffee_demo_step_t;

/* One pass through the product: pick a drink, start it, stop it again, then
 * visit the auxiliary screens. Timed for a recording of about ten seconds. */
static const coffee_demo_step_t steps[] = {
    {1200U, "Espresso"}, {2600U, "Start"},       {4600U, "Stop"}, {6200U, "Settings"},
    {7400U, "Home"},     {8000U, "UI Showcase"}, {9800U, "Back"},
};

static const size_t step_count = sizeof(steps) / sizeof(steps[0]);

static bool label_matches(lv_obj_t *obj, const char *caption)
{
    if (!lv_obj_check_type(obj, &lv_label_class)) {
        return false;
    }
    const char *text = lv_label_get_text(obj);
    return text != NULL && strcmp(text, caption) == 0;
}

static lv_obj_t *clickable_ancestor(lv_obj_t *obj)
{
    /* The caption may sit several levels below the control it belongs to, so
     * the search walks up until it finds something that takes clicks. */
    for (lv_obj_t *candidate = obj; candidate != NULL; candidate = lv_obj_get_parent(candidate)) {
        if (lv_obj_is_clickable(candidate)) {
            return candidate;
        }
    }
    return NULL;
}

static lv_obj_t *find_clickable(lv_obj_t *parent, const char *caption)
{
    const uint32_t child_count = lv_obj_get_child_count(parent);
    for (uint32_t i = 0U; i < child_count; ++i) {
        lv_obj_t *child = lv_obj_get_child(parent, i);
        if (label_matches(child, caption)) {
            lv_obj_t *target = clickable_ancestor(child);
            if (target != NULL) {
                return target;
            }
        }

        lv_obj_t *found = find_clickable(child, caption);
        if (found != NULL) {
            return found;
        }
    }
    return NULL;
}

void coffee_demo_tour_init(coffee_demo_tour_t *tour)
{
    if (tour == NULL) {
        return;
    }

    memset(tour, 0, sizeof(*tour));
    const char *value = getenv("COFFEE_DEMO_TOUR");
    tour->enabled = value != NULL && value[0] != '\0' && strcmp(value, "0") != 0;
    if (tour->enabled) {
        COFFEE_LOGI("demo tour enabled: %zu steps over %u ms", step_count,
                    coffee_demo_tour_duration_ms());
    }
}

void coffee_demo_tour_tick(coffee_demo_tour_t *tour, uint32_t elapsed_ms)
{
    if (tour == NULL || !tour->enabled || tour->next_step >= step_count) {
        return;
    }

    tour->elapsed_ms += elapsed_ms;
    while (tour->next_step < step_count && tour->elapsed_ms >= steps[tour->next_step].at_ms) {
        const char *caption = steps[tour->next_step].caption;
        lv_obj_t *target = find_clickable(lv_screen_active(), caption);
        if (target != NULL) {
            lv_obj_send_event(target, LV_EVENT_CLICKED, NULL);
            COFFEE_LOGI("demo tour: clicked '%s'", caption);
        } else {
            COFFEE_LOGW("demo tour: '%s' is not on the active screen, skipped", caption);
        }
        tour->next_step += 1U;
    }
}

bool coffee_demo_tour_enabled(const coffee_demo_tour_t *tour)
{
    return tour != NULL && tour->enabled;
}

uint32_t coffee_demo_tour_duration_ms(void)
{
    return steps[step_count - 1U].at_ms + 1000U;
}
