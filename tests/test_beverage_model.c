#include "app/beverage_model.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static void assert_default_option_valid(const coffee_beverage_t *beverage)
{
    assert(beverage != NULL);
    assert(beverage->option_count > 0);

    coffee_beverage_request_t request;
    assert(coffee_beverage_make_request(beverage->id, beverage->options[beverage->option_count / 2],
                                        &request));
    assert(request.beverage_id == beverage->id);
    assert(request.volume_ml >= beverage->min_volume_ml);
    assert(request.volume_ml <= beverage->max_volume_ml);
    assert(request.estimated_time_s >= beverage->default_time_s);
}

int main(void)
{
    size_t count = 0;
    const coffee_beverage_t *beverages = coffee_beverage_all(&count);
    assert(beverages != NULL);
    assert(count == COFFEE_BEV_COUNT);
    for (size_t i = 0; i < count; ++i) {
        assert_default_option_valid(&beverages[i]);
    }

    coffee_beverage_request_t req;
    assert(coffee_beverage_make_request(COFFEE_BEV_COFFEE, COFFEE_OPTION_SIZE_LARGE, &req));
    assert(req.volume_ml == coffee_beverage_get(COFFEE_BEV_COFFEE)->max_volume_ml);

    assert(coffee_beverage_make_request(COFFEE_BEV_ESPRESSO, COFFEE_OPTION_SHOT_DOUBLE, &req));
    assert(req.volume_ml == 80);

    assert(coffee_beverage_make_request(COFFEE_BEV_HOT_WATER, COFFEE_OPTION_WATER_300, &req));
    assert(req.volume_ml == 300);

    assert(!coffee_beverage_make_request(COFFEE_BEV_HOT_WATER, COFFEE_OPTION_SHOT_SINGLE, &req));
    assert(!coffee_beverage_make_request(COFFEE_BEV_COUNT, COFFEE_OPTION_SIZE_MEDIUM, &req));
    assert(!coffee_beverage_make_request(COFFEE_BEV_COFFEE, COFFEE_OPTION_SIZE_MEDIUM, NULL));
    assert(coffee_beverage_get(COFFEE_BEV_COUNT) == NULL);
    assert(!coffee_beverage_supports_option(NULL, COFFEE_OPTION_SIZE_MEDIUM));

    /* Every option has to carry its own label; a missing case would silently
     * fall through to the default one. */
    static const coffee_beverage_option_t all_options[] = {
        COFFEE_OPTION_SIZE_SMALL,   COFFEE_OPTION_SIZE_MEDIUM, COFFEE_OPTION_SIZE_LARGE,
        COFFEE_OPTION_SHOT_SINGLE,  COFFEE_OPTION_SHOT_DOUBLE, COFFEE_OPTION_MILK_LIGHT,
        COFFEE_OPTION_MILK_REGULAR, COFFEE_OPTION_MILK_EXTRA,  COFFEE_OPTION_WATER_100,
        COFFEE_OPTION_WATER_200,    COFFEE_OPTION_WATER_300,
    };
    for (size_t i = 0; i < sizeof(all_options) / sizeof(all_options[0]); ++i) {
        const char *label = coffee_beverage_option_label(all_options[i]);
        assert(label != NULL);
        assert(strcmp(label, "Default") != 0);
        for (size_t j = 0; j < i; ++j) {
            assert(strcmp(label, coffee_beverage_option_label(all_options[j])) != 0);
        }
    }
    assert(strcmp(coffee_beverage_option_label((coffee_beverage_option_t)999), "Default") == 0);

    /* One request per volume rule in resolve_volume(). */
    const coffee_beverage_t *coffee = coffee_beverage_get(COFFEE_BEV_COFFEE);
    assert(coffee_beverage_make_request(COFFEE_BEV_COFFEE, COFFEE_OPTION_SIZE_SMALL, &req));
    assert(req.volume_ml == coffee->min_volume_ml);
    assert(coffee_beverage_make_request(COFFEE_BEV_COFFEE, COFFEE_OPTION_SIZE_MEDIUM, &req));
    assert(req.volume_ml == coffee->default_volume_ml);

    const coffee_beverage_t *latte = coffee_beverage_get(COFFEE_BEV_LATTE_MACCHIATO);
    assert(
        coffee_beverage_make_request(COFFEE_BEV_LATTE_MACCHIATO, COFFEE_OPTION_MILK_LIGHT, &req));
    assert(req.volume_ml == (uint16_t)(latte->default_volume_ml - 20));
    assert(
        coffee_beverage_make_request(COFFEE_BEV_LATTE_MACCHIATO, COFFEE_OPTION_MILK_EXTRA, &req));
    assert(req.volume_ml == (uint16_t)(latte->default_volume_ml + 30));
    assert(
        coffee_beverage_make_request(COFFEE_BEV_LATTE_MACCHIATO, COFFEE_OPTION_MILK_REGULAR, &req));
    assert(req.volume_ml == latte->default_volume_ml);

    assert(coffee_beverage_make_request(COFFEE_BEV_HOT_WATER, COFFEE_OPTION_WATER_100, &req));
    assert(req.volume_ml == 100);

    assert(coffee_beverage_supports_option(coffee, COFFEE_OPTION_SIZE_LARGE));
    assert(!coffee_beverage_supports_option(coffee, COFFEE_OPTION_MILK_EXTRA));

    puts("beverage model tests passed");
    return 0;
}
