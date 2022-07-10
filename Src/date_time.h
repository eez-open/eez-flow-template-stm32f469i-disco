#pragma once

#include <stdint.h>

namespace date_time {

struct DateTime {
    uint8_t year;
    uint8_t month;
    uint8_t day;

    uint8_t hour;
    uint8_t minute;
    uint8_t second;
    uint8_t subSecond;
};

extern DateTime g_dateTime;

void tick();

}