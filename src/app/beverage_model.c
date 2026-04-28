#include "app/beverage_model.h"

#include <string.h>

static const coffee_beverage_option_t size_options[] = {
    COFFEE_OPTION_SIZE_SMALL,
    COFFEE_OPTION_SIZE_MEDIUM,
    COFFEE_OPTION_SIZE_LARGE,
};

static const coffee_beverage_option_t espresso_options[] = {
    COFFEE_OPTION_SHOT_SINGLE,
    COFFEE_OPTION_SHOT_DOUBLE,
};

static const coffee_beverage_option_t milk_options[] = {
    COFFEE_OPTION_MILK_LIGHT,
    COFFEE_OPTION_MILK_REGULAR,
    COFFEE_OPTION_MILK_EXTRA,
};

static const coffee_beverage_option_t water_options[] = {
    COFFEE_OPTION_WATER_100,
    COFFEE_OPTION_WATER_200,
    COFFEE_OPTION_WATER_300,
};

static const coffee_beverage_t beverages[] = {
    {COFFEE_BEV_COFFEE, "coffee", "Coffee", "C", COFFEE_CATEGORY_COFFEE, 180, 120, 240, 28,
     COFFEE_RESOURCE_WATER | COFFEE_RESOURCE_BEANS | COFFEE_RESOURCE_HEATER |
         COFFEE_RESOURCE_GRINDER,
     size_options, 3},
    {COFFEE_BEV_ESPRESSO, "espresso", "Espresso", "E", COFFEE_CATEGORY_COFFEE, 40, 30, 80, 22,
     COFFEE_RESOURCE_WATER | COFFEE_RESOURCE_BEANS | COFFEE_RESOURCE_HEATER |
         COFFEE_RESOURCE_GRINDER,
     espresso_options, 2},
    {COFFEE_BEV_LATTE_MACCHIATO, "latte_macchiato", "Latte Macchiato", "L", COFFEE_CATEGORY_MILK,
     250, 220, 300, 42,
     COFFEE_RESOURCE_WATER | COFFEE_RESOURCE_BEANS | COFFEE_RESOURCE_MILK | COFFEE_RESOURCE_HEATER |
         COFFEE_RESOURCE_GRINDER,
     milk_options, 3},
    {COFFEE_BEV_CAPPUCCINO, "cappuccino", "Cappuccino", "M", COFFEE_CATEGORY_MILK, 180, 160, 240,
     34,
     COFFEE_RESOURCE_WATER | COFFEE_RESOURCE_BEANS | COFFEE_RESOURCE_MILK | COFFEE_RESOURCE_HEATER |
         COFFEE_RESOURCE_GRINDER,
     milk_options, 3},
    {COFFEE_BEV_AMERICANO, "americano", "Americano", "A", COFFEE_CATEGORY_COFFEE, 200, 140, 300, 30,
     COFFEE_RESOURCE_WATER | COFFEE_RESOURCE_BEANS | COFFEE_RESOURCE_HEATER |
         COFFEE_RESOURCE_GRINDER,
     size_options, 3},
    {COFFEE_BEV_HOT_WATER, "hot_water", "Hot Water", "W", COFFEE_CATEGORY_WATER, 200, 100, 300, 18,
     COFFEE_RESOURCE_WATER | COFFEE_RESOURCE_HEATER, water_options, 3},
};

const coffee_beverage_t *coffee_beverage_all(size_t *count)
{
    if (count != NULL)
        *count = sizeof(beverages) / sizeof(beverages[0]);
    return beverages;
}

const coffee_beverage_t *coffee_beverage_get(coffee_beverage_id_t id)
{
    if (id >= COFFEE_BEV_COUNT)
        return NULL;
    return &beverages[id];
}

const char *coffee_beverage_option_label(coffee_beverage_option_t option)
{
    switch (option) {
    case COFFEE_OPTION_SIZE_SMALL:
        return "Small";
    case COFFEE_OPTION_SIZE_MEDIUM:
        return "Medium";
    case COFFEE_OPTION_SIZE_LARGE:
        return "Large";
    case COFFEE_OPTION_SHOT_SINGLE:
        return "Single";
    case COFFEE_OPTION_SHOT_DOUBLE:
        return "Double";
    case COFFEE_OPTION_MILK_LIGHT:
        return "Light milk";
    case COFFEE_OPTION_MILK_REGULAR:
        return "Regular milk";
    case COFFEE_OPTION_MILK_EXTRA:
        return "Extra milk";
    case COFFEE_OPTION_WATER_100:
        return "100 ml";
    case COFFEE_OPTION_WATER_200:
        return "200 ml";
    case COFFEE_OPTION_WATER_300:
        return "300 ml";
    default:
        return "Default";
    }
}

bool coffee_beverage_supports_option(const coffee_beverage_t *beverage,
                                     coffee_beverage_option_t option)
{
    if (beverage == NULL)
        return false;
    for (size_t i = 0; i < beverage->option_count; ++i) {
        if (beverage->options[i] == option)
            return true;
    }
    return false;
}

static uint16_t resolve_volume(const coffee_beverage_t *beverage, coffee_beverage_option_t option)
{
    switch (option) {
    case COFFEE_OPTION_SIZE_SMALL:
        return beverage->min_volume_ml;
    case COFFEE_OPTION_SIZE_LARGE:
        return beverage->max_volume_ml;
    case COFFEE_OPTION_SHOT_DOUBLE:
        return 80;
    case COFFEE_OPTION_MILK_LIGHT:
        return (uint16_t)(beverage->default_volume_ml - 20);
    case COFFEE_OPTION_MILK_EXTRA:
        return (uint16_t)(beverage->default_volume_ml + 30);
    case COFFEE_OPTION_WATER_100:
        return 100;
    case COFFEE_OPTION_WATER_300:
        return 300;
    case COFFEE_OPTION_WATER_200:
    case COFFEE_OPTION_SIZE_MEDIUM:
    case COFFEE_OPTION_SHOT_SINGLE:
    case COFFEE_OPTION_MILK_REGULAR:
    default:
        return beverage->default_volume_ml;
    }
}

bool coffee_beverage_make_request(coffee_beverage_id_t id, coffee_beverage_option_t option,
                                  coffee_beverage_request_t *out)
{
    const coffee_beverage_t *beverage = coffee_beverage_get(id);
    if (beverage == NULL || out == NULL)
        return false;
    if (!coffee_beverage_supports_option(beverage, option))
        return false;

    uint16_t volume = resolve_volume(beverage, option);
    uint16_t time =
        (uint16_t)(beverage->default_time_s + ((volume > beverage->default_volume_ml) ? 4 : 0));
    out->beverage_id = id;
    out->option = option;
    out->volume_ml = volume;
    out->estimated_time_s = time;
    return true;
}
