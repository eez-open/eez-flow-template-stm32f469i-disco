#include <math.h>
#include <stdio.h>
#include <string.h>

#ifdef EEZ_PLATFORM_STM32

#include "main.h"
#include "tim.h"
#include "usbd_cdc_if.h"
#include "usart.h"

#endif

#include <eez/gui/gui.h>

#include <eez/core/memory.h>
#include <eez/core/alloc.h>
#include <eez/core/debug.h>
#include <eez/core/os.h>
#include <eez/core/sound.h>
#include <eez/core/util.h>

#include <eez/gui/touch.h>
#include <eez/gui/thread.h>

#include <eez/flow/flow.h>

#include "date_time.h"
#include "firmware.h"
#include "tasks.h"
#include "gui/hooks.h"
#include "flow/hooks.h"

TouchScreenCalibrationParams g_touchScreenCalibrationParams;

void LCD_init();

using namespace eez;

#if defined(__EMSCRIPTEN__)
EM_PORT_API(void) init() {
#else
extern "C" void init() {
#endif
    LCD_init();

    eez::initAssetsMemory();
    eez::gui::loadMainAssets(eez::gui::assets, sizeof(eez::gui::assets));
    eez::initOtherMemory();
    eez::initAllocHeap(eez::ALLOC_BUFFER, eez::ALLOC_BUFFER_SIZE);

    eez::initHighPriorityMessageQueue();
    eez::startHighPriorityThread();

    eez::initLowPriorityMessageQueue();
    eez::startLowPriorityThread();

	flow::initHooks();

	//gui::display::g_calcFpsEnabled = true;
	//gui::display::g_drawFpsGraphEnabled = true;

#if defined(__EMSCRIPTEN__)
    gui::display::init();
#endif

	gui::display::turnOn();
	gui::initHooks();
	gui::startThread();

    DebugTrace("Firmware init. is done.\n");
}

#if defined(__EMSCRIPTEN__)
EM_PORT_API(void) startFlow() {
    eez::flow::start(eez::gui::g_mainAssets);
}

// clang-format off
void mountFileSystem() {
    EM_ASM(
        FS.mkdir("/{{projectName}}");
        FS.mount(IDBFS, {}, "/{{projectName}}");

        //Module.print("start file sync..");

        //flag to check when data are synchronized
        Module.syncdone = 0;

        FS.syncfs(true, function(err) {
            assert(!err);
            //Module.print("end file sync..");
            Module.syncdone = 1;
        });
    , 0);
}
// clang-format on

static int g_started = false;
extern void eez_system_tick();

EM_PORT_API(bool) mainLoop() {
    if (!g_started) {
        mountFileSystem();
        g_started = true;
    } else {
        if (emscripten_run_script_int("Module.syncdone") == 1) {
            eez_system_tick();

            if (eez::flow::isFlowStopped()) {
                return false;
            }

            // clang-format off
            EM_ASM(
                if (Module.syncdone) {
                    //Module.print("Start File sync..");
                    Module.syncdone = 0;

                    FS.syncfs(false, function(err) {
                        assert(!err);
                        //Module.print("End File sync..");
                        Module.syncdone = 1;
                    });
                }
            , 0);
            // clang-format on
        }
    }

    return true;
}
#endif

extern "C" void tick() {
    osDelay(1);
}

void serialWrite(const char *msg, int msgLen) {
	if (msgLen == -1) {
		msgLen = strlen(msg);
	}

#ifdef EEZ_PLATFORM_STM32
	CDC_Transmit_FS((uint8_t *)msg, (uint16_t)msgLen);
#endif

#ifdef EEZ_PLATFORM_SIMULATOR
	printf("%.*s", msgLen, msg);
#endif
}

#if defined(EEZ_PLATFORM_SIMULATOR) && !defined(__EMSCRIPTEN__)
void consoleInputTask(void *);
EEZ_THREAD_DECLARE(consoleInput, Normal, 1024);

int main() {
	init();

	EEZ_THREAD_CREATE(consoleInput, consoleInputTask);

    while (!eez::g_shutdown) {
        tick();
    }
}

void consoleInputTask(void *) {
    using namespace eez;
    //sendMessageToLowPriorityThread(SERIAL_LINE_STATE_CHANGED, 1);

    while (1) {
        int ch = getchar();
        if (ch == EOF) {
            break;
        }
        //Serial.put(ch);
    }
}
#endif // EEZ_PLATFORM_SIMULATOR

namespace eez {

bool g_shutdown;

void shutdown() {
    g_shutdown = true;   
}

} // namespace eez
