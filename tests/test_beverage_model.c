#include "app/beverage_model.h"

#include <assert.h>
#include <stdio.h>

int main(void) {
  size_t count = 0;
  const coffee_beverage_t *beverages = coffee_beverage_all(&count);
  assert(beverages != NULL);
  assert(count == COFFEE_BEV_COUNT);

  coffee_beverage_request_t req;
  assert(coffee_beverage_make_request(COFFEE_BEV_COFFEE,
                                      COFFEE_OPTION_SIZE_LARGE, &req));
  assert(req.volume_ml ==
         coffee_beverage_get(COFFEE_BEV_COFFEE)->max_volume_ml);

  assert(coffee_beverage_make_request(COFFEE_BEV_ESPRESSO,
                                      COFFEE_OPTION_SHOT_DOUBLE, &req));
  assert(req.volume_ml == 80);

  assert(coffee_beverage_make_request(COFFEE_BEV_HOT_WATER,
                                      COFFEE_OPTION_WATER_300, &req));
  assert(req.volume_ml == 300);

  assert(!coffee_beverage_make_request(COFFEE_BEV_HOT_WATER,
                                       COFFEE_OPTION_SHOT_SINGLE, &req));

  puts("beverage model tests passed");
  return 0;
}
