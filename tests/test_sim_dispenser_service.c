#include "app/beverage_model.h"
#include "service/sim_dispenser_service.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static void create_ready_sim(coffee_sim_dispenser_t *sim, coffee_dispenser_service_t *service)
{
    coffee_sim_dispenser_create(sim, service);
    service->init(service);
}

static void test_unknown_beverage_is_rejected(void)
{
    coffee_sim_dispenser_t sim;
    coffee_dispenser_service_t service;
    create_ready_sim(&sim, &service);

    const char *reason = NULL;
    assert(!service.can_dispense(&service, NULL, &reason));
    assert(reason != NULL);
    assert(!service.can_dispense(&service, NULL, NULL));
}

static void test_every_missing_resource_is_reported(void)
{
    /* One flag per required resource, so each guard in resource_available()
     * decides on its own instead of being shadowed by an earlier one. */
    const struct {
        coffee_beverage_id_t beverage;
        size_t offset;
    } cases[] = {
        {COFFEE_BEV_COFFEE, offsetof(coffee_machine_snapshot_t, water_available)},
        {COFFEE_BEV_COFFEE, offsetof(coffee_machine_snapshot_t, beans_available)},
        {COFFEE_BEV_LATTE_MACCHIATO, offsetof(coffee_machine_snapshot_t, milk_available)},
        {COFFEE_BEV_COFFEE, offsetof(coffee_machine_snapshot_t, heater_ready)},
        {COFFEE_BEV_COFFEE, offsetof(coffee_machine_snapshot_t, grinder_available)},
    };

    for (size_t i = 0; i < sizeof(cases) / sizeof(cases[0]); ++i) {
        coffee_sim_dispenser_t sim;
        coffee_dispenser_service_t service;
        create_ready_sim(&sim, &service);

        *((bool *)((char *)&sim.machine + cases[i].offset)) = false;

        const char *reason = NULL;
        const coffee_beverage_t *beverage = coffee_beverage_get(cases[i].beverage);
        assert(!service.can_dispense(&service, beverage, &reason));
        assert(reason != NULL);
    }
}

static void test_start_is_refused_while_not_ready(void)
{
    coffee_sim_dispenser_t sim;
    coffee_dispenser_service_t service;
    create_ready_sim(&sim, &service);

    coffee_sim_dispenser_set_status(&sim, COFFEE_MACHINE_DOOR_OPEN);

    coffee_beverage_request_t request;
    assert(coffee_beverage_make_request(COFFEE_BEV_COFFEE, COFFEE_OPTION_SIZE_MEDIUM, &request));

    const char *error = NULL;
    assert(!service.start(&service, &request, &error));
    assert(error != NULL);
    assert(!service.start(&service, &request, NULL));
}

static void test_cancel_needs_an_active_dispense(void)
{
    coffee_sim_dispenser_t sim;
    coffee_dispenser_service_t service;
    create_ready_sim(&sim, &service);

    assert(!service.cancel(&service));

    coffee_beverage_request_t request;
    assert(coffee_beverage_make_request(COFFEE_BEV_COFFEE, COFFEE_OPTION_SIZE_MEDIUM, &request));
    assert(service.start(&service, &request, NULL));

    sim.machine.safe_to_cancel = false;
    assert(!service.cancel(&service));

    sim.machine.safe_to_cancel = true;
    assert(service.cancel(&service));
    assert(service.dispense_snapshot(&service).cancelled);
}

static void test_progress_is_clamped_and_steps_are_walked(void)
{
    coffee_sim_dispenser_t sim;
    coffee_dispenser_service_t service;
    create_ready_sim(&sim, &service);

    coffee_beverage_request_t request;
    assert(coffee_beverage_make_request(COFFEE_BEV_COFFEE, COFFEE_OPTION_SIZE_MEDIUM, &request));
    assert(service.start(&service, &request, NULL));

    const char *steps[4] = {NULL, NULL, NULL, NULL};
    const uint32_t step_ms = (request.estimated_time_s * 1000U) / 4U;
    for (size_t i = 0; i < 4; ++i) {
        service.tick(&service, step_ms / 2U);
        steps[i] = service.dispense_snapshot(&service).current_step;
        assert(steps[i] != NULL);
        service.tick(&service, step_ms / 2U);
    }

    /* Far beyond the end: the progress has to stop at 100%. */
    service.tick(&service, 10U * 60U * 1000U);
    const coffee_dispense_snapshot_t snapshot = service.dispense_snapshot(&service);
    assert(snapshot.progress_pct == 100U);
    assert(snapshot.completed);
    assert(snapshot.remaining_s == 0U);

    /* A tick without an active dispense must not change anything. */
    service.tick(&service, 1000U);
    assert(service.dispense_snapshot(&service).progress_pct == 100U);
}

static void test_a_single_long_tick_completes_the_dispense(void)
{
    coffee_sim_dispenser_t sim;
    coffee_dispenser_service_t service;
    create_ready_sim(&sim, &service);

    coffee_beverage_request_t request;
    assert(coffee_beverage_make_request(COFFEE_BEV_COFFEE, COFFEE_OPTION_SIZE_MEDIUM, &request));
    assert(service.start(&service, &request, NULL));

    /* One tick far longer than the dispense: the progress has to saturate at
     * 100% instead of wrapping around. */
    service.tick(&service, 10U * 60U * 1000U);
    const coffee_dispense_snapshot_t snapshot = service.dispense_snapshot(&service);
    assert(snapshot.progress_pct == 100U);
    assert(snapshot.completed);
    assert(!snapshot.active);
}

static void test_machine_snapshot_reports_the_status(void)
{
    coffee_sim_dispenser_t sim;
    coffee_dispenser_service_t service;
    create_ready_sim(&sim, &service);

    assert(service.machine_snapshot(&service).status == COFFEE_MACHINE_READY);
    coffee_sim_dispenser_set_status(&sim, COFFEE_MACHINE_HEATING);
    assert(service.machine_snapshot(&service).status == COFFEE_MACHINE_HEATING);
    assert(coffee_machine_status_label(COFFEE_MACHINE_DISPENSING) != NULL);
}

int main(void)
{
    test_unknown_beverage_is_rejected();
    test_every_missing_resource_is_reported();
    test_start_is_refused_while_not_ready();
    test_cancel_needs_an_active_dispense();
    test_progress_is_clamped_and_steps_are_walked();
    test_a_single_long_tick_completes_the_dispense();
    test_machine_snapshot_reports_the_status();

    puts("simulated dispenser service tests passed");
    return 0;
}
