#include <eez/core/debug.h>
#include <eez/core/os.h>
#include "firmware.h"

namespace eez {
namespace debug {

void pushDebugTraceHook(const char *message, size_t messageLength) {
    serialWrite("DEBUG: ");
    osDelay(1);
    serialWrite(message, messageLength);
}

void pushInfoTraceHook(const char *message, size_t messageLength) {
    serialWrite("INFO: ");
    osDelay(1);
    serialWrite(message, messageLength);
}

void pushErrorTraceHook(const char *message, size_t messageLength) {
    serialWrite("ERROR: ");
    osDelay(1);
    serialWrite(message, messageLength);
}

} // namespace debug
} // namespace eez
