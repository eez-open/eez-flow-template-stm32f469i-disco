#pragma once

#include <stdint.h>

#if defined(EEZ_PLATFORM_STM32)
#if CONF_OPTION_FPGA
static const uint32_t DISPLAY_WIDTH = 800;
static const uint32_t DISPLAY_HEIGHT = 480;
#else
static const uint32_t DISPLAY_WIDTH = 480;
static const uint32_t DISPLAY_HEIGHT = 272;
#endif
static const uint32_t DISPLAY_BPP = 16; // RGB565
#endif

#if defined(EEZ_PLATFORM_SIMULATOR)
static const uint32_t DISPLAY_WIDTH = 680;
static const uint32_t DISPLAY_HEIGHT = 472;
static const uint32_t DISPLAY_BPP = 32;  // RGBA8888

static const char *TITLE = "Uvitron Integrated Rayven";
static const char *ICON = "uvitron.png";
#endif


#define MAX_NUM_OF_Y_AXES 18
#define MAX_NUM_OF_Y_VALUES MAX_NUM_OF_Y_AXES

#define OPTION_KEYBOARD 0
#define OPTION_MOUSE 0

#define CUSTOM_VALUE_TYPES

#define DISPLAY_BACKGROUND_LUMINOSITY_STEP_MIN 0
#define DISPLAY_BACKGROUND_LUMINOSITY_STEP_MAX 20
#define DISPLAY_BACKGROUND_LUMINOSITY_STEP_DEFAULT 10

#define UTF8_SUPPORT 0

#if defined(EEZ_PLATFORM_STM32)
static const uint32_t GUI_STATE_BUFFER_SIZE = 64 * 1024;
#endif
#if defined(EEZ_PLATFORM_SIMULATOR)
static const uint32_t GUI_STATE_BUFFER_SIZE = 128 * 1024;
#endif
