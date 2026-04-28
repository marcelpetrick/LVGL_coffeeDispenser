#ifndef COFFEE_APP_STATE_H
#define COFFEE_APP_STATE_H

typedef enum {
    COFFEE_APP_BOOTING,
    COFFEE_APP_READY,
    COFFEE_APP_BEVERAGE_SELECTED,
    COFFEE_APP_CONFIRMING,
    COFFEE_APP_DISPENSING,
    COFFEE_APP_COMPLETED,
    COFFEE_APP_CANCELLED,
    COFFEE_APP_ERROR,
    COFFEE_APP_MAINTENANCE,
    COFFEE_APP_SHUTDOWN
} coffee_app_state_t;

const char *coffee_app_state_name(coffee_app_state_t state);

#endif
