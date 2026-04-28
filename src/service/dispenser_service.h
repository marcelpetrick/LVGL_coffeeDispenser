#ifndef COFFEE_DISPENSER_SERVICE_H
#define COFFEE_DISPENSER_SERVICE_H

#include "app/beverage_model.h"

#include <stdbool.h>
#include <stdint.h>

typedef enum {
    COFFEE_MACHINE_READY,
    COFFEE_MACHINE_HEATING,
    COFFEE_MACHINE_DISPENSING,
    COFFEE_MACHINE_WATER_EMPTY,
    COFFEE_MACHINE_BEANS_EMPTY,
    COFFEE_MACHINE_MILK_UNAVAILABLE,
    COFFEE_MACHINE_CLEANING_REQUIRED,
    COFFEE_MACHINE_DRIP_TRAY_FULL,
    COFFEE_MACHINE_DOOR_OPEN,
    COFFEE_MACHINE_ERROR
} coffee_machine_status_t;

typedef struct {
    coffee_machine_status_t status;
    bool water_available;
    bool beans_available;
    bool milk_available;
    bool heater_ready;
    bool grinder_available;
    bool safe_to_cancel;
    const char *message;
} coffee_machine_snapshot_t;

typedef struct {
    bool active;
    uint8_t progress_pct;
    uint16_t remaining_s;
    const char *current_step;
    bool completed;
    bool failed;
    bool cancelled;
    const char *message;
} coffee_dispense_snapshot_t;

typedef struct coffee_dispenser_service coffee_dispenser_service_t;

struct coffee_dispenser_service {
    void *ctx;
    void (*init)(coffee_dispenser_service_t *service);
    coffee_machine_snapshot_t (*machine_snapshot)(coffee_dispenser_service_t *service);
    bool (*can_dispense)(coffee_dispenser_service_t *service, const coffee_beverage_t *beverage,
                         const char **reason);
    bool (*start)(coffee_dispenser_service_t *service, const coffee_beverage_request_t *request,
                  const char **error);
    bool (*cancel)(coffee_dispenser_service_t *service);
    coffee_dispense_snapshot_t (*dispense_snapshot)(coffee_dispenser_service_t *service);
    void (*tick)(coffee_dispenser_service_t *service, uint32_t elapsed_ms);
};

const char *coffee_machine_status_label(coffee_machine_status_t status);

#endif
