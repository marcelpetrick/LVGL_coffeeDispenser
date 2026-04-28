#include "app/app_controller.h"
#include "service/sim_dispenser_service.h"

#include <assert.h>
#include <stdio.h>

static void complete_active_dispense(coffee_app_controller_t *app)
{
    for (int i = 0; i < 60 && coffee_app_controller_state(app) == COFFEE_APP_DISPENSING; ++i) {
        coffee_app_controller_tick(app, 1000);
    }
}

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

    complete_active_dispense(&app);
    assert(coffee_app_controller_state(&app) == COFFEE_APP_COMPLETED);
    assert(coffee_app_controller_dispense(&app).completed);

    coffee_app_controller_home(&app);
    assert(coffee_app_controller_select(&app, COFFEE_BEV_HOT_WATER, COFFEE_OPTION_WATER_200));
    assert(coffee_app_controller_confirm(&app));
    assert(coffee_app_controller_cancel(&app));
    assert(coffee_app_controller_state(&app) == COFFEE_APP_CANCELLED);

    coffee_app_controller_home(&app);
    coffee_sim_dispenser_set_status(&sim, COFFEE_MACHINE_WATER_EMPTY);
    assert(!coffee_app_controller_select(&app, COFFEE_BEV_COFFEE, COFFEE_OPTION_SIZE_MEDIUM));
    assert(coffee_app_controller_state(&app) == COFFEE_APP_ERROR);

    coffee_app_controller_home(&app);
    coffee_sim_dispenser_set_status(&sim, COFFEE_MACHINE_READY);
    coffee_sim_dispenser_fail_next(&sim);
    assert(coffee_app_controller_select(&app, COFFEE_BEV_ESPRESSO, COFFEE_OPTION_SHOT_SINGLE));
    assert(coffee_app_controller_confirm(&app));
    complete_active_dispense(&app);
    assert(coffee_app_controller_state(&app) == COFFEE_APP_ERROR);
    assert(coffee_app_controller_message(&app) != NULL);

    coffee_app_controller_home(&app);
    assert(!coffee_app_controller_cancel(&app));
    assert(coffee_app_controller_state(&app) == COFFEE_APP_READY);

    assert(coffee_app_state_name(COFFEE_APP_BOOTING) != NULL);
    assert(coffee_app_state_name(COFFEE_APP_MAINTENANCE) != NULL);
    assert(coffee_app_state_name(COFFEE_APP_SHUTDOWN) != NULL);
    assert(coffee_app_state_name((coffee_app_state_t)999) != NULL);
    assert(coffee_machine_status_label(COFFEE_MACHINE_HEATING) != NULL);
    assert(coffee_machine_status_label(COFFEE_MACHINE_BEANS_EMPTY) != NULL);
    assert(coffee_machine_status_label(COFFEE_MACHINE_MILK_UNAVAILABLE) != NULL);
    assert(coffee_machine_status_label(COFFEE_MACHINE_CLEANING_REQUIRED) != NULL);
    assert(coffee_machine_status_label(COFFEE_MACHINE_DRIP_TRAY_FULL) != NULL);
    assert(coffee_machine_status_label(COFFEE_MACHINE_DOOR_OPEN) != NULL);
    assert(coffee_machine_status_label(COFFEE_MACHINE_ERROR) != NULL);
    assert(coffee_machine_status_label((coffee_machine_status_t)999) != NULL);

    puts("app controller tests passed");
    return 0;
}
