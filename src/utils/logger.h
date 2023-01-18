#ifndef PID_CONTROLLER_UTILS_LOGGER_H
#define PID_CONTROLLER_UTILS_LOGGER_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __clang__
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wstrict-prototypes"
    #pragma clang diagnostic ignored "-Wunknown-pragmas"
#endif

void InitLogger();

void LogTrace(const char *format, ...);

void LogDebug(const char *format, ...);

void LogInfo(const char *format, ...);

void LogWarn(const char *format, ...);

void LogError(const char *format, ...);

void LogCritical(const char *format, ...);

void ShutdownLogger();

#pragma clang diagnostic pop    // NOLINT

#ifdef __cplusplus
}
#endif

#endif /* PID_CONTROLLER_UTILS_LOGGER_H */
