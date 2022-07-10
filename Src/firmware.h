#pragma once

#include <stdlib.h>
#include <stdint.h>

struct TouchScreenCalibrationParams {
	int16_t isValid;
	int16_t touchScreenCalTlx;
	int16_t touchScreenCalTly;
	int16_t touchScreenCalBrx;
	int16_t touchScreenCalBry;
	int16_t touchScreenCalTrx;
	int16_t touchScreenCalTry;
};

extern TouchScreenCalibrationParams g_touchScreenCalibrationParams;

// Initialize firmware. Called from the freertos.c only once after HW is initialized.
extern "C" void init();

// Called from freertos.c continuously after init() has been called.
extern "C" void tick();

void updateBrightness();
void serialWrite(const char *msg, int msgLen = -1);
