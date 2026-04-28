#include "app/beverage_model.h"

#include <assert.h>
#include <stdio.h>

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

    assert(coffee_beverage_option_label(COFFEE_OPTION_SIZE_SMALL) != NULL);
    assert(coffee_beverage_option_label(COFFEE_OPTION_SIZE_MEDIUM) != NULL);
    assert(coffee_beverage_option_label(COFFEE_OPTION_SHOT_SINGLE) != NULL);
    assert(coffee_beverage_option_label(COFFEE_OPTION_MILK_LIGHT) != NULL);
    assert(coffee_beverage_option_label((coffee_beverage_option_t)999) != NULL);

    puts("beverage model tests passed");
    return 0;
}
