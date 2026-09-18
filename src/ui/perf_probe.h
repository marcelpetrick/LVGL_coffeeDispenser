#ifndef COFFEE_UI_PERF_PROBE_H
#define COFFEE_UI_PERF_PROBE_H

#include "platform/perf_stats.h"

#include "lvgl.h"

#include <stdbool.h>

/**
 * Rendering profiler for the LVGL display.
 *
 * It hooks the display render and flush events, so it measures what LVGL
 * actually spends per refresh instead of what the main loop sleeps. The probe
 * is switched on by the environment, which keeps the normal run untouched:
 *
 *   COFFEE_PERF_PROFILE=1       collect and report timings
 *   COFFEE_PERF_FORCE_REDRAW=1  invalidate the active screen every iteration,
 *                               which turns an idle UI into a full-screen
 *                               rendering load and makes runs comparable
 */
typedef struct {
    bool enabled;
    bool force_redraw;
    uint32_t render_start_us;
    uint32_t flush_start_us;
    coffee_perf_stats_t render;
    coffee_perf_stats_t flush;
} coffee_perf_probe_t;

/** Read the environment and, when enabled, attach to the display. */
void coffee_perf_probe_init(coffee_perf_probe_t *probe, lv_display_t *display);

/** Call once per main-loop iteration; forces a redraw when asked to. */
void coffee_perf_probe_tick(coffee_perf_probe_t *probe);

/** Log the collected timings as machine-readable `[PERF] key=value` lines. */
void coffee_perf_probe_report(coffee_perf_probe_t *probe, uint32_t runtime_ms);

/** True when profiling was requested through the environment. */
bool coffee_perf_probe_enabled(const coffee_perf_probe_t *probe);

#endif
