#include "service/sim_dispenser_service.h"

#include "platform/platform_log.h"

#include <string.h>

const char *coffee_machine_status_label(coffee_machine_status_t status)
{
    switch (status) {
    case COFFEE_MACHINE_READY:
        return "Ready";
    case COFFEE_MACHINE_HEATING:
        return "Heating";
    case COFFEE_MACHINE_DISPENSING:
        return "Dispensing";
    case COFFEE_MACHINE_WATER_EMPTY:
        return "Water tank empty";
    case COFFEE_MACHINE_BEANS_EMPTY:
        return "Bean hopper empty";
    case COFFEE_MACHINE_MILK_UNAVAILABLE:
        return "Milk unavailable";
    case COFFEE_MACHINE_CLEANING_REQUIRED:
        return "Cleaning required";
    case COFFEE_MACHINE_DRIP_TRAY_FULL:
        return "Drip tray full";
    case COFFEE_MACHINE_DOOR_OPEN:
        return "Door open";
    case COFFEE_MACHINE_ERROR:
        return "General error";
    default:
        return "Unknown";
    }
}

static coffee_sim_dispenser_t *as_sim(coffee_dispenser_service_t *service)
{
    return (coffee_sim_dispenser_t *)service->ctx;
}

static void sim_init(coffee_dispenser_service_t *service)
{
    coffee_sim_dispenser_t *sim = as_sim(service);
    memset(&sim->dispense, 0, sizeof(sim->dispense));
    sim->machine.status = COFFEE_MACHINE_READY;
    sim->machine.water_available = true;
    sim->machine.beans_available = true;
    sim->machine.milk_available = true;
    sim->machine.heater_ready = true;
    sim->machine.grinder_available = true;
    sim->machine.safe_to_cancel = true;
    sim->machine.message = "All systems ready";
    COFFEE_LOGI("simulated dispenser initialized");
}

static coffee_machine_snapshot_t sim_machine_snapshot(coffee_dispenser_service_t *service)
{
    return as_sim(service)->machine;
}

static bool resource_available(const coffee_machine_snapshot_t *machine, uint32_t resource)
{
    if ((resource & COFFEE_RESOURCE_WATER) && !machine->water_available)
        return false;
    if ((resource & COFFEE_RESOURCE_BEANS) && !machine->beans_available)
        return false;
    if ((resource & COFFEE_RESOURCE_MILK) && !machine->milk_available)
        return false;
    if ((resource & COFFEE_RESOURCE_HEATER) && !machine->heater_ready)
        return false;
    if ((resource & COFFEE_RESOURCE_GRINDER) && !machine->grinder_available)
        return false;
    return true;
}

static bool sim_can_dispense(coffee_dispenser_service_t *service, const coffee_beverage_t *beverage,
                             const char **reason)
{
    coffee_sim_dispenser_t *sim = as_sim(service);
    if (beverage == NULL) {
        if (reason != NULL)
            *reason = "Unknown beverage";
        return false;
    }
    if (sim->machine.status != COFFEE_MACHINE_READY) {
        if (reason != NULL)
            *reason = coffee_machine_status_label(sim->machine.status);
        return false;
    }
    if (!resource_available(&sim->machine, beverage->required_resources)) {
        if (reason != NULL)
            *reason = "Required ingredient or heater is unavailable";
        return false;
    }
    if (reason != NULL)
        *reason = "Ready";
    return true;
}

static bool sim_start(coffee_dispenser_service_t *service, const coffee_beverage_request_t *request,
                      const char **error)
{
    coffee_sim_dispenser_t *sim = as_sim(service);
    const coffee_beverage_t *beverage = coffee_beverage_get(request->beverage_id);
    const char *reason = NULL;
    if (!sim_can_dispense(service, beverage, &reason)) {
        if (error != NULL)
            *error = reason;
        return false;
    }

    sim->current_request = *request;
    sim->elapsed_ms = 0;
    sim->duration_ms = request->estimated_time_s * 1000U;
    sim->machine.status = COFFEE_MACHINE_DISPENSING;
    sim->machine.message = "Dispensing in progress";
    sim->dispense.active = true;
    sim->dispense.progress_pct = 0;
    sim->dispense.remaining_s = request->estimated_time_s;
    sim->dispense.current_step = "Grinding";
    sim->dispense.completed = false;
    sim->dispense.failed = false;
    sim->dispense.cancelled = false;
    sim->dispense.message = "Preparing beverage";
    COFFEE_LOGI("dispense accepted: %s %u ml", beverage->stable_id, request->volume_ml);
    return true;
}

static bool sim_cancel(coffee_dispenser_service_t *service)
{
    coffee_sim_dispenser_t *sim = as_sim(service);
    if (!sim->dispense.active || !sim->machine.safe_to_cancel)
        return false;
    sim->dispense.active = false;
    sim->dispense.cancelled = true;
    sim->dispense.current_step = "Cancelled";
    sim->dispense.message = "Dispensing cancelled";
    sim->machine.status = COFFEE_MACHINE_READY;
    sim->machine.message = "Ready after cancellation";
    COFFEE_LOGW("dispense cancelled by user");
    return true;
}

static coffee_dispense_snapshot_t sim_dispense_snapshot(coffee_dispenser_service_t *service)
{
    return as_sim(service)->dispense;
}

static void sim_tick(coffee_dispenser_service_t *service, uint32_t elapsed_ms)
{
    coffee_sim_dispenser_t *sim = as_sim(service);
    if (!sim->dispense.active)
        return;

    sim->elapsed_ms += elapsed_ms;
    uint8_t progress = (uint8_t)((sim->elapsed_ms * 100U) / sim->duration_ms);
    if (progress > 100)
        progress = 100;

    sim->dispense.progress_pct = progress;
    uint32_t remaining_ms =
        (sim->duration_ms > sim->elapsed_ms) ? (sim->duration_ms - sim->elapsed_ms) : 0;
    sim->dispense.remaining_s = (uint16_t)((remaining_ms + 999U) / 1000U);

    if (progress < 25)
        sim->dispense.current_step = "Grinding";
    else if (progress < 55)
        sim->dispense.current_step = "Heating water";
    else if (progress < 85)
        sim->dispense.current_step = "Dispensing";
    else
        sim->dispense.current_step = "Finishing";

    if (progress >= 100) {
        sim->dispense.active = false;
        sim->machine.status = COFFEE_MACHINE_READY;
        sim->machine.message = "All systems ready";
        if (sim->force_next_failure) {
            sim->force_next_failure = false;
            sim->dispense.failed = true;
            sim->dispense.message = "Simulated backend failure";
            COFFEE_LOGE("dispense failed by simulated scenario");
        } else {
            sim->dispense.completed = true;
            sim->dispense.message = "Beverage ready";
            COFFEE_LOGI("dispense completed");
        }
    }
}

void coffee_sim_dispenser_create(coffee_sim_dispenser_t *sim,
                                 coffee_dispenser_service_t *out_service)
{
    memset(sim, 0, sizeof(*sim));
    out_service->ctx = sim;
    out_service->init = sim_init;
    out_service->machine_snapshot = sim_machine_snapshot;
    out_service->can_dispense = sim_can_dispense;
    out_service->start = sim_start;
    out_service->cancel = sim_cancel;
    out_service->dispense_snapshot = sim_dispense_snapshot;
    out_service->tick = sim_tick;
}

void coffee_sim_dispenser_set_status(coffee_sim_dispenser_t *sim, coffee_machine_status_t status)
{
    sim->machine.status = status;
    sim->machine.water_available = status != COFFEE_MACHINE_WATER_EMPTY;
    sim->machine.beans_available = status != COFFEE_MACHINE_BEANS_EMPTY;
    sim->machine.milk_available = status != COFFEE_MACHINE_MILK_UNAVAILABLE;
    sim->machine.heater_ready = status != COFFEE_MACHINE_HEATING;
    sim->machine.message = coffee_machine_status_label(status);
}

void coffee_sim_dispenser_fail_next(coffee_sim_dispenser_t *sim)
{
    sim->force_next_failure = true;
}
