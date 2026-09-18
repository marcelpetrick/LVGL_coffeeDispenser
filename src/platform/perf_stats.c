#include "platform/perf_stats.h"

#include <string.h>

static int compare_samples(const void *lhs, const void *rhs)
{
    const uint32_t left = *(const uint32_t *)lhs;
    const uint32_t right = *(const uint32_t *)rhs;
    if (left < right) {
        return -1;
    }
    if (left > right) {
        return 1;
    }
    return 0;
}

static void sort_samples(uint32_t *samples, uint32_t count)
{
    /* Insertion sort keeps this dependency-free and is fast enough: it runs
     * once per report, on data that is already almost sorted in practice. */
    for (uint32_t i = 1U; i < count; ++i) {
        const uint32_t value = samples[i];
        uint32_t j = i;
        while (j > 0U && compare_samples(&samples[j - 1U], &value) > 0) {
            samples[j] = samples[j - 1U];
            --j;
        }
        samples[j] = value;
    }
}

void coffee_perf_stats_reset(coffee_perf_stats_t *stats)
{
    if (stats == NULL) {
        return;
    }
    memset(stats, 0, sizeof(*stats));
    stats->min_us = UINT32_MAX;
}

void coffee_perf_stats_add(coffee_perf_stats_t *stats, uint32_t sample_us)
{
    if (stats == NULL) {
        return;
    }

    if (stats->count == 0U) {
        stats->min_us = sample_us;
        stats->max_us = sample_us;
    } else {
        if (sample_us < stats->min_us) {
            stats->min_us = sample_us;
        }
        if (sample_us > stats->max_us) {
            stats->max_us = sample_us;
        }
    }

    stats->count += 1U;
    stats->total_us += sample_us;

    if (stats->stored < COFFEE_PERF_MAX_SAMPLES) {
        stats->samples[stats->stored] = sample_us;
        stats->stored += 1U;
    } else {
        stats->dropped += 1U;
    }
}

coffee_perf_summary_t coffee_perf_stats_summary(coffee_perf_stats_t *stats)
{
    coffee_perf_summary_t summary;
    memset(&summary, 0, sizeof(summary));

    if (stats == NULL || stats->count == 0U) {
        return summary;
    }

    summary.count = stats->count;
    summary.stored = stats->stored;
    summary.dropped = stats->dropped;
    summary.min_us = stats->min_us;
    summary.max_us = stats->max_us;
    summary.mean_us = (uint32_t)(stats->total_us / stats->count);

    sort_samples(stats->samples, stats->stored);

    if (stats->stored > 0U) {
        const uint32_t middle = stats->stored / 2U;
        if ((stats->stored % 2U) == 0U) {
            summary.median_us =
                (uint32_t)(((uint64_t)stats->samples[middle - 1U] + stats->samples[middle]) / 2U);
        } else {
            summary.median_us = stats->samples[middle];
        }

        uint32_t index = (uint32_t)(((uint64_t)stats->stored * 95U) / 100U);
        if (index >= stats->stored) {
            index = stats->stored - 1U;
        }
        summary.p95_us = stats->samples[index];
    }

    return summary;
}

uint32_t coffee_perf_fps_centi(uint32_t frames, uint32_t runtime_ms)
{
    if (runtime_ms == 0U) {
        return 0U;
    }
    return (uint32_t)(((uint64_t)frames * 100000ULL) / runtime_ms);
}
