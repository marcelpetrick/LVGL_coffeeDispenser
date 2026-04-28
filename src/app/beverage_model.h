#ifndef COFFEE_BEVERAGE_MODEL_H
#define COFFEE_BEVERAGE_MODEL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

typedef enum {
    COFFEE_BEV_COFFEE,
    COFFEE_BEV_ESPRESSO,
    COFFEE_BEV_LATTE_MACCHIATO,
    COFFEE_BEV_CAPPUCCINO,
    COFFEE_BEV_AMERICANO,
    COFFEE_BEV_HOT_WATER,
    COFFEE_BEV_COUNT
} coffee_beverage_id_t;

typedef enum {
    COFFEE_CATEGORY_COFFEE,
    COFFEE_CATEGORY_MILK,
    COFFEE_CATEGORY_WATER
} coffee_beverage_category_t;

typedef enum {
    COFFEE_OPTION_SIZE_SMALL,
    COFFEE_OPTION_SIZE_MEDIUM,
    COFFEE_OPTION_SIZE_LARGE,
    COFFEE_OPTION_SHOT_SINGLE,
    COFFEE_OPTION_SHOT_DOUBLE,
    COFFEE_OPTION_MILK_LIGHT,
    COFFEE_OPTION_MILK_REGULAR,
    COFFEE_OPTION_MILK_EXTRA,
    COFFEE_OPTION_WATER_100,
    COFFEE_OPTION_WATER_200,
    COFFEE_OPTION_WATER_300
} coffee_beverage_option_t;

typedef enum {
    COFFEE_RESOURCE_WATER = 1 << 0,
    COFFEE_RESOURCE_BEANS = 1 << 1,
    COFFEE_RESOURCE_MILK = 1 << 2,
    COFFEE_RESOURCE_HEATER = 1 << 3,
    COFFEE_RESOURCE_GRINDER = 1 << 4
} coffee_resource_t;

typedef struct {
    coffee_beverage_id_t id;
    const char *stable_id;
    const char *display_name;
    const char *symbol;
    coffee_beverage_category_t category;
    uint16_t default_volume_ml;
    uint16_t min_volume_ml;
    uint16_t max_volume_ml;
    uint16_t default_time_s;
    uint32_t required_resources;
    const coffee_beverage_option_t *options;
    size_t option_count;
} coffee_beverage_t;

typedef struct {
    coffee_beverage_id_t beverage_id;
    coffee_beverage_option_t option;
    uint16_t volume_ml;
    uint16_t estimated_time_s;
} coffee_beverage_request_t;

const coffee_beverage_t *coffee_beverage_all(size_t *count);
const coffee_beverage_t *coffee_beverage_get(coffee_beverage_id_t id);
const char *coffee_beverage_option_label(coffee_beverage_option_t option);
bool coffee_beverage_supports_option(const coffee_beverage_t *beverage,
                                     coffee_beverage_option_t option);
bool coffee_beverage_make_request(coffee_beverage_id_t id, coffee_beverage_option_t option,
                                  coffee_beverage_request_t *out);

#endif
