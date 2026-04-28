#ifndef COFFEE_SIM_DISPENSER_SERVICE_H
#define COFFEE_SIM_DISPENSER_SERVICE_H

#include "service/dispenser_service.h"

typedef struct {
  coffee_machine_snapshot_t machine;
  coffee_dispense_snapshot_t dispense;
  coffee_beverage_request_t current_request;
  uint32_t elapsed_ms;
  uint32_t duration_ms;
  bool force_next_failure;
} coffee_sim_dispenser_t;

void coffee_sim_dispenser_create(coffee_sim_dispenser_t *sim,
                                 coffee_dispenser_service_t *out_service);
void coffee_sim_dispenser_set_status(coffee_sim_dispenser_t *sim,
                                     coffee_machine_status_t status);
void coffee_sim_dispenser_fail_next(coffee_sim_dispenser_t *sim);

#endif
