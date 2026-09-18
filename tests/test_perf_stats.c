#include "platform/perf_stats.h"
#include "platform/platform_time.h"

#include <assert.h>
#include <stdio.h>

static void test_empty_collector(void)
{
    coffee_perf_stats_t stats;
    coffee_perf_stats_reset(&stats);

    const coffee_perf_summary_t summary = coffee_perf_stats_summary(&stats);
    assert(summary.count == 0U);
    assert(summary.mean_us == 0U);
    assert(summary.median_us == 0U);
    assert(summary.p95_us == 0U);
}

static void test_odd_sample_count(void)
{
    coffee_perf_stats_t stats;
    coffee_perf_stats_reset(&stats);

    /* Deliberately unsorted: the summary has to sort before it picks. */
    coffee_perf_stats_add(&stats, 30U);
    coffee_perf_stats_add(&stats, 10U);
    coffee_perf_stats_add(&stats, 20U);

    const coffee_perf_summary_t summary = coffee_perf_stats_summary(&stats);
    assert(summary.count == 3U);
    assert(summary.stored == 3U);
    assert(summary.min_us == 10U);
    assert(summary.max_us == 30U);
    assert(summary.mean_us == 20U);
    assert(summary.median_us == 20U);
    assert(summary.p95_us == 30U);
    assert(summary.dropped == 0U);
}

static void test_even_sample_count(void)
{
    coffee_perf_stats_t stats;
    coffee_perf_stats_reset(&stats);

    coffee_perf_stats_add(&stats, 4U);
    coffee_perf_stats_add(&stats, 2U);
    coffee_perf_stats_add(&stats, 8U);
    coffee_perf_stats_add(&stats, 6U);

    const coffee_perf_summary_t summary = coffee_perf_stats_summary(&stats);
    assert(summary.median_us == 5U);
    assert(summary.mean_us == 5U);
    assert(summary.min_us == 2U);
    assert(summary.max_us == 8U);
}

static void test_percentile_position(void)
{
    coffee_perf_stats_t stats;
    coffee_perf_stats_reset(&stats);

    for (uint32_t value = 1U; value <= 100U; ++value) {
        coffee_perf_stats_add(&stats, value);
    }

    const coffee_perf_summary_t summary = coffee_perf_stats_summary(&stats);
    assert(summary.count == 100U);
    assert(summary.median_us == 50U);
    assert(summary.p95_us == 96U);
    assert(summary.max_us == 100U);
}

static void test_sample_overflow(void)
{
    static coffee_perf_stats_t stats;
    coffee_perf_stats_reset(&stats);

    const uint32_t extra = 25U;
    for (uint32_t i = 0U; i < COFFEE_PERF_MAX_SAMPLES + extra; ++i) {
        coffee_perf_stats_add(&stats, 7U);
    }

    const coffee_perf_summary_t summary = coffee_perf_stats_summary(&stats);
    assert(summary.count == COFFEE_PERF_MAX_SAMPLES + extra);
    assert(summary.stored == COFFEE_PERF_MAX_SAMPLES);
    assert(summary.dropped == extra);
    assert(summary.mean_us == 7U);
    assert(summary.median_us == 7U);
}

static void test_null_tolerance(void)
{
    coffee_perf_stats_reset(NULL);
    coffee_perf_stats_add(NULL, 1U);

    const coffee_perf_summary_t summary = coffee_perf_stats_summary(NULL);
    assert(summary.count == 0U);
}

static void test_fps_helper(void)
{
    assert(coffee_perf_fps_centi(0U, 0U) == 0U);
    assert(coffee_perf_fps_centi(60U, 1000U) == 6000U);
    assert(coffee_perf_fps_centi(1U, 3000U) == 33U);
}

static void test_monotonic_clock(void)
{
    const uint32_t first_us = coffee_time_us();
    const uint32_t first_ms = coffee_time_ms();
    uint32_t spin = 0U;
    for (uint32_t i = 0U; i < 200000U; ++i) {
        spin += i;
    }
    assert(spin != UINT32_MAX);
    assert(coffee_time_us() >= first_us);
    assert(coffee_time_ms() >= first_ms);
}

int main(void)
{
    test_empty_collector();
    test_odd_sample_count();
    test_even_sample_count();
    test_percentile_position();
    test_sample_overflow();
    test_null_tolerance();
    test_fps_helper();
    test_monotonic_clock();

    puts("perf stats tests passed");
    return 0;
}
