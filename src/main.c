#define SDL_MAIN_HANDLED

#include "app/app_controller.h"
#include "app_config.h"
#include "platform/platform_log.h"
#include "service/sim_dispenser_service.h"
#include "ui/ui_manager.h"

#include "drivers/sdl/lv_sdl_keyboard.h"
#include "drivers/sdl/lv_sdl_mouse.h"
#include "drivers/sdl/lv_sdl_mousewheel.h"
#include "drivers/sdl/lv_sdl_window.h"
#include "lvgl.h"

#include <SDL2/SDL.h>
#include <stdlib.h>

int main(void)
{
    setenv("DBUS_FATAL_WARNINGS", "0", 1);
    COFFEE_LOGI("starting LVGL Coffee Dispenser HMI %s", COFFEE_APP_VERSION);
    const char *exit_after_startup_ms_env = getenv("COFFEE_EXIT_AFTER_STARTUP_MS");
    const uint32_t exit_after_startup_ms =
        exit_after_startup_ms_env != NULL ? (uint32_t)strtoul(exit_after_startup_ms_env, NULL, 10)
                                          : 0U;

    lv_init();

    lv_display_t *display = lv_sdl_window_create(COFFEE_DEFAULT_WIDTH, COFFEE_DEFAULT_HEIGHT);
    lv_sdl_window_set_title(display, "LVGL Coffee Dispenser");
    lv_sdl_window_set_resizeable(display, true);
    lv_sdl_mouse_create();
    lv_sdl_mousewheel_create();
    lv_sdl_keyboard_create();

    coffee_sim_dispenser_t sim;
    coffee_dispenser_service_t service;
    coffee_sim_dispenser_create(&sim, &service);

    coffee_app_controller_t app;
    coffee_app_controller_init(&app, &service);

    coffee_ui_manager_t ui;
    coffee_ui_manager_init(&ui, &app);

    uint32_t last_tick = SDL_GetTicks();
    uint32_t runtime_ms = 0;
    while (!coffee_ui_manager_wants_quit(&ui)) {
        SDL_Delay(COFFEE_TICK_MS);
        uint32_t now = SDL_GetTicks();
        uint32_t elapsed = now - last_tick;
        last_tick = now;
        runtime_ms += elapsed;

        lv_tick_inc(elapsed);
        coffee_app_controller_tick(&app, elapsed);
        coffee_ui_manager_tick(&ui, elapsed);
        lv_timer_handler();

        if (exit_after_startup_ms > 0U && runtime_ms >= exit_after_startup_ms) {
            COFFEE_LOGI("exiting after startup smoke timeout: %u ms", exit_after_startup_ms);
            break;
        }
    }

    COFFEE_LOGI("shutdown");
    lv_sdl_quit();
    return 0;
}
