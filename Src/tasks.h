#pragma once

#include <eez/core/os.h>

namespace eez {

enum HighPriorityThreadMessage {
    HIGH_PRIORITY_THREAD_MESSAGE_DUMMY
};

void initHighPriorityMessageQueue();
void startHighPriorityThread();
bool isHighPriorityThread();
void sendMessageToHighPriorityThread(HighPriorityThreadMessage messageType, uint32_t messageParam = 0, uint32_t timeoutMillisec = osWaitForever);

enum LowPriorityThreadMessage {
    LOW_PRIORITY_THREAD_MESSAGE_DUMMY
};

void initLowPriorityMessageQueue();
void startLowPriorityThread();
bool isLowPriorityThread();
void sendMessageToLowPriorityThread(LowPriorityThreadMessage messageType, uint32_t messageParam = 0, uint32_t timeoutMillisec = osWaitForever);

} // namespace eez
