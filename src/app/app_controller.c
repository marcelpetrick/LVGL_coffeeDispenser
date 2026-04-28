#include "app/app_controller.h"

#include "platform/platform_log.h"

#include <string.h>

const char *coffee_app_state_name(coffee_app_state_t state) {
  switch (state) {
  case COFFEE_APP_BOOTING:
    return "Booting";
  case COFFEE_APP_READY:
    return "Ready";
  case COFFEE_APP_BEVERAGE_SELECTED:
    return "BeverageSelected";
  case COFFEE_APP_CONFIRMING:
    return "Confirming";
  case COFFEE_APP_DISPENSING:
    return "Dispensing";
  case COFFEE_APP_COMPLETED:
    return "Completed";
  case COFFEE_APP_CANCELLED:
    return "Cancelled";
  case COFFEE_APP_ERROR:
    return "Error";
  case COFFEE_APP_MAINTENANCE:
    return "Maintenance";
  case COFFEE_APP_SHUTDOWN:
    return "Shutdown";
  default:
    return "Unknown";
  }
}

static void transition(coffee_app_controller_t *app, coffee_app_state_t next,
                       const char *message) {
  COFFEE_LOGI("state transition: %s -> %s", coffee_app_state_name(app->state),
              coffee_app_state_name(next));
  app->state = next;
  app->status_message = message;
  app->state_elapsed_ms = 0;
}

void coffee_app_controller_init(coffee_app_controller_t *app,
                                coffee_dispenser_service_t *service) {
  memset(app, 0, sizeof(*app));
  app->state = COFFEE_APP_BOOTING;
  app->service = service;
  app->status_message = "Starting";
  if (service != NULL && service->init != NULL) {
    service->init(service);
    transition(app, COFFEE_APP_READY, "Ready");
  } else {
    transition(app, COFFEE_APP_ERROR, "Dispenser service unavailable");
  }
}

coffee_app_state_t
coffee_app_controller_state(const coffee_app_controller_t *app) {
  return app->state;
}

const coffee_beverage_t *
coffee_app_controller_selected(const coffee_app_controller_t *app) {
  return app->selected;
}

const char *coffee_app_controller_message(const coffee_app_controller_t *app) {
  return app->status_message;
}

coffee_dispense_snapshot_t
coffee_app_controller_dispense(const coffee_app_controller_t *app) {
  return app->dispense;
}

coffee_machine_snapshot_t
coffee_app_controller_machine(const coffee_app_controller_t *app) {
  return app->service->machine_snapshot(app->service);
}

bool coffee_app_controller_select(coffee_app_controller_t *app,
                                  coffee_beverage_id_t beverage_id,
                                  coffee_beverage_option_t option) {
  if (app->state != COFFEE_APP_READY &&
      app->state != COFFEE_APP_BEVERAGE_SELECTED)
    return false;
  if (!coffee_beverage_make_request(beverage_id, option, &app->request)) {
    transition(app, COFFEE_APP_ERROR, "Invalid beverage option");
    return false;
  }

  const coffee_beverage_t *beverage = coffee_beverage_get(beverage_id);
  const char *reason = NULL;
  if (!app->service->can_dispense(app->service, beverage, &reason)) {
    app->selected = beverage;
    transition(app, COFFEE_APP_ERROR, reason);
    return false;
  }

  app->selected = beverage;
  transition(app, COFFEE_APP_BEVERAGE_SELECTED, "Review and confirm");
  return true;
}

bool coffee_app_controller_confirm(coffee_app_controller_t *app) {
  if (app->state != COFFEE_APP_BEVERAGE_SELECTED)
    return false;
  transition(app, COFFEE_APP_CONFIRMING, "Sending request");

  const char *error = NULL;
  if (!app->service->start(app->service, &app->request, &error)) {
    transition(app, COFFEE_APP_ERROR,
               error != NULL ? error : "Backend rejected request");
    return false;
  }

  app->dispense = app->service->dispense_snapshot(app->service);
  transition(app, COFFEE_APP_DISPENSING, "Dispensing");
  return true;
}

bool coffee_app_controller_cancel(coffee_app_controller_t *app) {
  if (app->state == COFFEE_APP_BEVERAGE_SELECTED) {
    transition(app, COFFEE_APP_READY, "Ready");
    app->selected = NULL;
    return true;
  }

  if (app->state == COFFEE_APP_DISPENSING &&
      app->service->cancel(app->service)) {
    app->dispense = app->service->dispense_snapshot(app->service);
    transition(app, COFFEE_APP_CANCELLED, "Cancelled");
    return true;
  }

  return false;
}

void coffee_app_controller_home(coffee_app_controller_t *app) {
  app->selected = NULL;
  transition(app, COFFEE_APP_READY, "Ready");
}

void coffee_app_controller_tick(coffee_app_controller_t *app,
                                uint32_t elapsed_ms) {
  app->state_elapsed_ms += elapsed_ms;
  if (app->service != NULL && app->service->tick != NULL)
    app->service->tick(app->service, elapsed_ms);

  if (app->state == COFFEE_APP_DISPENSING) {
    app->dispense = app->service->dispense_snapshot(app->service);
    if (app->dispense.completed)
      transition(app, COFFEE_APP_COMPLETED, "Enjoy your drink");
    else if (app->dispense.cancelled)
      transition(app, COFFEE_APP_CANCELLED, "Cancelled");
    else if (app->dispense.failed)
      transition(app, COFFEE_APP_ERROR, app->dispense.message);
  }
}
