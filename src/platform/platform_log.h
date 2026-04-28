#ifndef COFFEE_PLATFORM_LOG_H
#define COFFEE_PLATFORM_LOG_H

typedef enum {
    COFFEE_LOG_DEBUG,
    COFFEE_LOG_INFO,
    COFFEE_LOG_WARN,
    COFFEE_LOG_ERROR
} coffee_log_level_t;

void coffee_log(coffee_log_level_t level, const char *fmt, ...);

#define COFFEE_LOGI(...) coffee_log(COFFEE_LOG_INFO, __VA_ARGS__)
#define COFFEE_LOGW(...) coffee_log(COFFEE_LOG_WARN, __VA_ARGS__)
#define COFFEE_LOGE(...) coffee_log(COFFEE_LOG_ERROR, __VA_ARGS__)

#endif
