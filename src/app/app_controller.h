#ifndef COFFEE_APP_CONTROLLER_H
#define COFFEE_APP_CONTROLLER_H

#include "app/app_state.h"
#include "app/beverage_model.h"
#include "service/dispenser_service.h"

#include <stdbool.h>
#include <stdint.h>

typedef struct {
    coffee_app_state_t state;
    coffee_dispenser_service_t *service;
    coffee_beverage_request_t request;
    const coffee_beverage_t *selected;
    coffee_dispense_snapshot_t dispense;
    const char *status_message;
    uint32_t state_elapsed_ms;
} coffee_app_controller_t;

void coffee_app_controller_init(coffee_app_controller_t *app, coffee_dispenser_service_t *service);
coffee_app_state_t coffee_app_controller_state(const coffee_app_controller_t *app);
const coffee_beverage_t *coffee_app_controller_selected(const coffee_app_controller_t *app);
const char *coffee_app_controller_message(const coffee_app_controller_t *app);
coffee_dispense_snapshot_t coffee_app_controller_dispense(const coffee_app_controller_t *app);
coffee_machine_snapshot_t coffee_app_controller_machine(const coffee_app_controller_t *app);
bool coffee_app_controller_select(coffee_app_controller_t *app, coffee_beverage_id_t beverage_id,
                                  coffee_beverage_option_t option);
bool coffee_app_controller_confirm(coffee_app_controller_t *app);
bool coffee_app_controller_cancel(coffee_app_controller_t *app);
void coffee_app_controller_home(coffee_app_controller_t *app);
void coffee_app_controller_tick(coffee_app_controller_t *app, uint32_t elapsed_ms);

#endif
