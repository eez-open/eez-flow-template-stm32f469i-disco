#ifdef EEZ_PLATFORM_STM32
#include "main.h"
//#include "rtc.h"
#endif

#if defined(EEZ_PLATFORM_SIMULATOR)
#include <stdio.h>
#include <time.h>
#endif

#include "date_time.h"

namespace date_time {

// leap year calulator expects year argument as years offset from 1970
#define LEAP_YEAR(Y)                                                                               \
    (((1970 + Y) > 0) && !((1970 + Y) % 4) && (((1970 + Y) % 100) || !((1970 + Y) % 400)))

#define SECONDS_PER_MINUTE 60UL
#define SECONDS_PER_HOUR (SECONDS_PER_MINUTE * 60)
#define SECONDS_PER_DAY (SECONDS_PER_HOUR * 24)

// API starts months from 1, this array starts from 0
static const uint8_t monthDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

#if defined(EEZ_PLATFORM_SIMULATOR)
static uint32_t g_offset;
#endif

DateTime g_dateTime;

uint32_t makeTime(int year, int month, int day, int hour, int minute, int second) {
	// seconds from 1970 till 1 jan 00:00:00 of the given year
	year -= 1970;

	uint32_t seconds = year * 365 * SECONDS_PER_DAY;

	for (int i = 0; i < year; i++) {
		if (LEAP_YEAR(i)) {
			seconds += SECONDS_PER_DAY; // add extra days for leap years
		}
	}

	// add days for this year, months start from 1
	for (int i = 1; i < month; i++) {
		if ((i == 2) && LEAP_YEAR(year)) {
			seconds += SECONDS_PER_DAY * 29;
		}
		else {
			seconds += SECONDS_PER_DAY * monthDays[i - 1]; // monthDay array starts from 0
		}
	}
	seconds += (day - 1) * SECONDS_PER_DAY;
	seconds += hour * SECONDS_PER_HOUR;
	seconds += minute * SECONDS_PER_MINUTE;
	seconds += second;

	return seconds;
}

void breakTime(uint32_t time, int &resultYear, int &resultMonth, int &resultDay, int &resultHour,
	int &resultMinute, int &resultSecond) {
	// break the given time_t into time components
	uint8_t year;
	uint8_t month, monthLength;
	uint32_t days;

	resultSecond = time % 60;
	time /= 60; // now it is minutes

	resultMinute = time % 60;
	time /= 60; // now it is hours

	resultHour = time % 24;
	time /= 24; // now it is days

	year = 0;
	days = 0;
	while ((unsigned)(days += (LEAP_YEAR(year) ? 366 : 365)) <= time) {
		year++;
	}
	resultYear = year + 1970; // year is offset from 1970

	days -= LEAP_YEAR(year) ? 366 : 365;
	time -= days; // now it is days in this year, starting at 0

	days = 0;
	month = 0;
	monthLength = 0;
	for (month = 0; month < 12; ++month) {
		if (month == 1) { // february
			if (LEAP_YEAR(year)) {
				monthLength = 29;
			}
			else {
				monthLength = 28;
			}
		}
		else {
			monthLength = monthDays[month];
		}

		if (time >= monthLength) {
			time -= monthLength;
		}
		else {
			break;
		}
	}

	resultMonth = month + 1; // jan is month 1
	resultDay = time + 1;    // day of month
}

#if defined(EEZ_PLATFORM_SIMULATOR)
uint32_t nowUtc() {
	time_t now_time_t = time(0);
	struct tm *now_tm = gmtime(&now_time_t);
	return makeTime(1900 + now_tm->tm_year, now_tm->tm_mon + 1, now_tm->tm_mday,
		now_tm->tm_hour, now_tm->tm_min, now_tm->tm_sec);
}
#endif

bool readTime(uint8_t &hour, uint8_t &minute, uint8_t &second, uint8_t &subSeconds) {
#if defined(EEZ_PLATFORM_STM32)
//	RTC_TimeTypeDef time;
//	HAL_RTC_GetTime(&hrtc, &time, FORMAT_BIN);
//
//	second = time.Seconds;
//	minute = time.Minutes;
//	hour = time.Hours;
//	subSeconds = time.SubSeconds;
#endif

#if defined(EEZ_PLATFORM_SIMULATOR)
	int year_, month_, day_, hour_, minute_, second_;
	breakTime(g_offset + nowUtc(), year_, month_, day_, hour_, minute_, second_);

	hour = uint8_t(hour_);
	minute = uint8_t(minute_);
	second = uint8_t(second_);
	subSeconds = 0;
#endif

	return true;
}

bool readDate(uint8_t &year, uint8_t &month, uint8_t &day) {
#if defined(EEZ_PLATFORM_STM32)
//	RTC_DateTypeDef date;
//	HAL_RTC_GetDate(&hrtc, &date, FORMAT_BIN);
//
//	day = date.Date;
//	month = date.Month;
//	year = date.Year;
#endif

#if defined(EEZ_PLATFORM_SIMULATOR)
	int year_, month_, day_, hour_, minute_, second_;
	breakTime(g_offset + nowUtc(), year_, month_, day_, hour_, minute_, second_);

	year = uint8_t(year_ - 2000);
	month = uint8_t(month_);
	day = uint8_t(day_);
#endif

	return true;
}

void tick() {
	readTime(g_dateTime.hour, g_dateTime.minute, g_dateTime.second, g_dateTime.subSecond);
	readDate(g_dateTime.year, g_dateTime.month, g_dateTime.day);
}

} // date_time
