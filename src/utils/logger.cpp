#include "logger.h"

#include <cstdarg>
#include <cstdint>
#include <iostream>
#include <memory>
#include <string>

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>

#include "internals.h"

#ifdef __cplusplus
extern "C" {
#endif

void InitLogger() {
    const auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    consoleSink->set_level(spdlog::level::trace);
    consoleSink->set_pattern("[%Y-%m-%d %I:%M:%S.%e] - %^[%l]%$: %v");
    spdlog::set_default_logger(std::make_shared<spdlog::logger>("default_logger", consoleSink));
    spdlog::flush_on(spdlog::level::trace);
    LogInfo("Logger init succesfully.");
}

void LogTrace(const char *format, ...) {
    va_list args;
    va_start(args, format);
    const auto buffer = FormatString(format, args);
    va_end(args);
    spdlog::trace(buffer);
}

void LogDebug(const char *format, ...) {
    va_list args;
    va_start(args, format);
    const auto buffer = FormatString(format, args);
    va_end(args);
    spdlog::debug(buffer);
}

void LogInfo(const char *format, ...) {
    va_list args;
    va_start(args, format);
    const auto buffer = FormatString(format, args);
    va_end(args);
    spdlog::info(buffer);
}

void LogWarn(const char *format, ...) {
    va_list args;
    va_start(args, format);
    const auto buffer = FormatString(format, args);
    va_end(args);
    spdlog::warn(buffer);
}

void LogError(const char *format, ...) {
    va_list args;
    va_start(args, format);
    const auto buffer = FormatString(format, args);
    va_end(args);
    spdlog::error(buffer);
}

void LogCritical(const char *format, ...) {
    va_list args;
    va_start(args, format);
    const auto buffer = FormatString(format, args);
    va_end(args);
    spdlog::critical(buffer);
}

void ShutdownLogger() {
    spdlog::shutdown();
}

#ifdef __cplusplus
}
#endif
