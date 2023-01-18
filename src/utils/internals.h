#ifndef PID_CONTROLLER_UTILS_INTERNALS_H
#define PID_CONTROLLER_UTILS_INTERNALS_H

#include <cstdarg>
#include <string>

// Not part of the public API
std::string FormatString(const char *format, va_list args);

#endif /* PID_CONTROLLER_UTILS_INTERNALS_H */
