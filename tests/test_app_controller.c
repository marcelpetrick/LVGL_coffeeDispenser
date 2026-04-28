#include "app/app_controller.h"
#include "service/sim_dispenser_service.h"

#include <assert.h>
#include <stdio.h>

int main(void)
{
    coffee_sim_dispenser_t sim;
    coffee_dispenser_service_t service;
    coffee_sim_dispenser_create(&sim, &service);

    coffee_app_controller_t app;
    coffee_app_controller_init(&app, &service);
    assert(coffee_app_controller_state(&app) == COFFEE_APP_READY);

    assert(coffee_app_controller_select(&app, COFFEE_BEV_COFFEE, COFFEE_OPTION_SIZE_MEDIUM));
    assert(coffee_app_controller_state(&app) == COFFEE_APP_BEVERAGE_SELECTED);

    assert(coffee_app_controller_confirm(&app));
    assert(coffee_app_controller_state(&app) == COFFEE_APP_DISPENSING);

    for (int i = 0; i < 40; ++i) {
        coffee_app_controller_tick(&app, 1000);
    }
    assert(coffee_app_controller_state(&app) == COFFEE_APP_COMPLETED);

    coffee_app_controller_home(&app);
    assert(coffee_app_controller_select(&app, COFFEE_BEV_HOT_WATER, COFFEE_OPTION_WATER_200));
    assert(coffee_app_controller_confirm(&app));
    assert(coffee_app_controller_cancel(&app));
    assert(coffee_app_controller_state(&app) == COFFEE_APP_CANCELLED);

    coffee_app_controller_home(&app);
    coffee_sim_dispenser_set_status(&sim, COFFEE_MACHINE_WATER_EMPTY);
    assert(!coffee_app_controller_select(&app, COFFEE_BEV_COFFEE, COFFEE_OPTION_SIZE_MEDIUM));
    assert(coffee_app_controller_state(&app) == COFFEE_APP_ERROR);

    puts("app controller tests passed");
    return 0;
}
