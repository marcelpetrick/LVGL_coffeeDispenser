#ifndef COFFEE_UI_DEMO_TOUR_H
#define COFFEE_UI_DEMO_TOUR_H

#include "lvgl.h"

#include <stdbool.h>
#include <stdint.h>

/**
 * Scripted click tour through the UI, used to record a reproducible demo.
 *
 * Each step names the caption of the control it activates, so the tour follows
 * the widgets instead of pixel coordinates and keeps working when the layout
 * changes. Enabled with COFFEE_DEMO_TOUR=1; a step whose control is not on the
 * active screen is skipped with a log line instead of aborting the run.
 */
typedef struct {
    bool enabled;
    uint32_t elapsed_ms;
    size_t next_step;
} coffee_demo_tour_t;

/** Read the environment; the tour stays inert unless it is switched on. */
void coffee_demo_tour_init(coffee_demo_tour_t *tour);

/** Advance the script; call once per main-loop iteration. */
void coffee_demo_tour_tick(coffee_demo_tour_t *tour, uint32_t elapsed_ms);

/** True when the tour was requested through the environment. */
bool coffee_demo_tour_enabled(const coffee_demo_tour_t *tour);

/** Milliseconds the full script needs, so a recording can be timed to it. */
uint32_t coffee_demo_tour_duration_ms(void);

#endif
