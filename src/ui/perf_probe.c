#include "ui/perf_probe.h"

#include "platform/platform_log.h"
#include "platform/platform_time.h"

#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>

static bool env_flag_set(const char *name)
{
    const char *value = getenv(name);
    return value != NULL && value[0] != '\0' && strcmp(value, "0") != 0;
}

static void refr_ready_cb(lv_event_t *event)
{
    /* Re-dirty the screen as soon as the refresh is done: that is exactly one
     * invalidation per rendered frame, and it keeps LVGL's refresh timer from
     * pausing. Invalidating from the main loop instead would repeat the same
     * call several times per refresh period for nothing. */
    lv_obj_t *screen = lv_screen_active();
    if (screen != NULL) {
        lv_obj_invalidate(screen);
    }
    (void)event;
}

static void render_start_cb(lv_event_t *event)
{
    coffee_perf_probe_t *probe = lv_event_get_user_data(event);
    probe->render_start_us = coffee_time_us();
}

static void render_ready_cb(lv_event_t *event)
{
    coffee_perf_probe_t *probe = lv_event_get_user_data(event);
    coffee_perf_stats_add(&probe->render, coffee_time_us() - probe->render_start_us);
}

static void flush_start_cb(lv_event_t *event)
{
    coffee_perf_probe_t *probe = lv_event_get_user_data(event);
    probe->flush_start_us = coffee_time_us();
}

static void flush_finish_cb(lv_event_t *event)
{
    coffee_perf_probe_t *probe = lv_event_get_user_data(event);
    coffee_perf_stats_add(&probe->flush, coffee_time_us() - probe->flush_start_us);
}

void coffee_perf_probe_init(coffee_perf_probe_t *probe, lv_display_t *display)
{
    if (probe == NULL) {
        return;
    }

    memset(probe, 0, sizeof(*probe));
    coffee_perf_stats_reset(&probe->render);
    coffee_perf_stats_reset(&probe->flush);

    probe->enabled = env_flag_set("COFFEE_PERF_PROFILE");
    probe->force_redraw = env_flag_set("COFFEE_PERF_FORCE_REDRAW");

    if (!probe->enabled || display == NULL) {
        return;
    }

    probe->display = display;

    if (probe->force_redraw) {
        lv_display_add_event_cb(display, refr_ready_cb, LV_EVENT_REFR_READY, probe);
    }
    lv_display_add_event_cb(display, render_start_cb, LV_EVENT_RENDER_START, probe);
    lv_display_add_event_cb(display, render_ready_cb, LV_EVENT_RENDER_READY, probe);
    lv_display_add_event_cb(display, flush_start_cb, LV_EVENT_FLUSH_START, probe);
    lv_display_add_event_cb(display, flush_finish_cb, LV_EVENT_FLUSH_FINISH, probe);

    COFFEE_LOGI("render profiling enabled (force_redraw=%d)", probe->force_redraw ? 1 : 0);
}

static void report_stats(const char *name, coffee_perf_stats_t *stats)
{
    const coffee_perf_summary_t summary = coffee_perf_stats_summary(stats);
    COFFEE_LOGI("[PERF] stage=%s count=%u min_us=%u mean_us=%u median_us=%u p95_us=%u max_us=%u "
                "dropped=%u",
                name, summary.count, summary.min_us, summary.mean_us, summary.median_us,
                summary.p95_us, summary.max_us, summary.dropped);
}

static void report_memory(void)
{
    /* LVGL's own heap first: on a target this is the pool that has to be sized,
     * and unlike the process footprint it is unaffected by the host allocator. */
    lv_mem_monitor_t heap;
    lv_mem_monitor(&heap);

    struct rusage usage;
    const long peak_rss_kb = (getrusage(RUSAGE_SELF, &usage) == 0) ? usage.ru_maxrss : 0;

    COFFEE_LOGI("[PERF] stage=memory lvgl_heap_bytes=%u lvgl_max_used_bytes=%u lvgl_used_pct=%u "
                "lvgl_frag_pct=%u peak_rss_kb=%ld",
                (unsigned)heap.total_size, (unsigned)heap.max_used, (unsigned)heap.used_pct,
                (unsigned)heap.frag_pct, peak_rss_kb);
}

void coffee_perf_probe_report(coffee_perf_probe_t *probe, uint32_t runtime_ms)
{
    if (probe == NULL || !probe->enabled) {
        return;
    }
    if (probe->display == NULL) {
        /* Without a display the summary could only report LVGL's implicit
         * default one, which is not what was measured. */
        COFFEE_LOGW("[PERF] no display attached, summary skipped");
        return;
    }

    report_stats("render", &probe->render);
    report_stats("flush", &probe->flush);
    report_memory();

    const uint32_t frames = probe->render.count;
    const uint32_t fps_centi = coffee_perf_fps_centi(frames, runtime_ms);
    /* The SDL window is resizeable, so the measured area is the one the display
     * reports and not the configured default. */
    const lv_color_format_t color_format = lv_display_get_color_format(probe->display);
    COFFEE_LOGI("[PERF] stage=summary runtime_ms=%u frames=%u fps=%u.%02u width=%d height=%d "
                "color_depth=%d force_redraw=%d",
                runtime_ms, frames, fps_centi / 100U, fps_centi % 100U,
                (int)lv_display_get_horizontal_resolution(probe->display),
                (int)lv_display_get_vertical_resolution(probe->display),
                (int)lv_color_format_get_bpp(color_format), probe->force_redraw ? 1 : 0);
}

bool coffee_perf_probe_enabled(const coffee_perf_probe_t *probe)
{
    return probe != NULL && probe->enabled;
}
