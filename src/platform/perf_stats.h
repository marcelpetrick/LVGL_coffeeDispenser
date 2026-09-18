#ifndef COFFEE_PERF_STATS_H
#define COFFEE_PERF_STATS_H

#include <stdint.h>

/**
 * Number of samples kept for the percentile calculation.
 *
 * The buffer is part of the collector and therefore resident, so the size is a
 * compromise: 2048 samples are 8 KiB per stage and cover more than a minute at
 * the LVGL refresh rate. Everything beyond that still counts towards the mean,
 * the extremes, and the frame count.
 */
#define COFFEE_PERF_MAX_SAMPLES 2048U

/**
 * Collector for microsecond timings.
 *
 * Every sample is counted, but only the first COFFEE_PERF_MAX_SAMPLES ones are
 * stored, because the percentiles need the individual values. min, max, and the
 * mean stay exact for the whole run.
 */
typedef struct {
    uint32_t count;
    uint32_t stored;
    uint32_t dropped;
    uint64_t total_us;
    uint32_t min_us;
    uint32_t max_us;
    uint32_t samples[COFFEE_PERF_MAX_SAMPLES];
} coffee_perf_stats_t;

/** Aggregated view of a coffee_perf_stats_t. All timings are microseconds. */
typedef struct {
    uint32_t count;
    uint32_t stored;
    uint32_t dropped;
    uint32_t min_us;
    uint32_t max_us;
    uint32_t mean_us;
    uint32_t median_us;
    uint32_t p95_us;
} coffee_perf_summary_t;

/** Clear all collected data. */
void coffee_perf_stats_reset(coffee_perf_stats_t *stats);

/** Add one timing sample. */
void coffee_perf_stats_add(coffee_perf_stats_t *stats, uint32_t sample_us);

/**
 * Summarize the collected data.
 *
 * The stored samples are sorted in place, which does not affect further use of
 * the collector: order carries no meaning for the reported values.
 */
coffee_perf_summary_t coffee_perf_stats_summary(coffee_perf_stats_t *stats);

/** Frames per second derived from a frame count and a runtime, scaled by 100. */
uint32_t coffee_perf_fps_centi(uint32_t frames, uint32_t runtime_ms);

#endif
