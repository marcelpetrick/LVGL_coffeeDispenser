#include "platform/platform_log.h"

#include <stdarg.h>
#include <stdio.h>
#include <time.h>

void coffee_log(coffee_log_level_t level, const char *fmt, ...)
{
    static const char *names[] = {"DEBUG", "INFO", "WARN", "ERROR"};
    time_t now = time(NULL);
    struct tm tm_now;
    localtime_r(&now, &tm_now);

    char stamp[24];
    strftime(stamp, sizeof(stamp), "%Y-%m-%d %H:%M:%S", &tm_now);

    fprintf(stdout, "[%s] %-5s ", stamp, names[level]);

    va_list args;
    va_start(args, fmt);
    vfprintf(stdout, fmt, args);
    va_end(args);

    fputc('\n', stdout);
    fflush(stdout);
}
