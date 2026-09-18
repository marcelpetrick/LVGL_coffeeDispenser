#ifndef COFFEE_PLATFORM_TIME_H
#define COFFEE_PLATFORM_TIME_H

#include <stdint.h>

/** Monotonic milliseconds; wraps every ~49 days. */
uint32_t coffee_time_ms(void);

/** Monotonic microseconds; wraps every ~71 minutes, enough for frame timings. */
uint32_t coffee_time_us(void);

#endif
