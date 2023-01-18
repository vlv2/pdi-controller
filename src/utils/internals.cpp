#include "internals.h"

#include <cstdarg>
#include <string>

#ifdef __GNUC__
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wformat-nonliteral"
    #pragma GCC diagnostic ignored "-Wunknown-pragmas"
#elif defined(__clang__)
    #pragma clang diagnostic push
    #pragma clang diagnostic ignored "-Wformat-nonliteral"
    #pragma clang diagnostic ignored "-Wunknown-pragmas"
#endif

// Not part of the public API
std::string FormatString(const char *format, va_list args) {
    static constexpr uint16_t MAX_BUFFER_TO_READ = 1024;
    std::string buffer(static_cast<size_t>(2 * MAX_BUFFER_TO_READ), ' ');
    const int bytesWritten = vsnprintf(buffer.data(), MAX_BUFFER_TO_READ, format, args);
    buffer.resize(static_cast<size_t>(bytesWritten));
    return buffer;
}

#ifdef __GNUC__
    #pragma GCC diagnostic pop    // NOLINT
#elif defined(__clang__)
    #pragma clang diagnostic pop    // NOLINT
#endif
