#include "io.h"

#include <fmt/format.h>

#include "internals.h"

#ifdef __cplusplus
extern "C" {
#endif

void Print(const char *format, ...) {
    va_list args;
    va_start(args, format);
    const auto buffer = FormatString(format, args);
    va_end(args);
    fmt::print(buffer);
}

#ifdef __cplusplus
}
#endif
