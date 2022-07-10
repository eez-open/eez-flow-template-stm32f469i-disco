#include <eez/core/sound.h>

#include <eez/gui/gui.h>
#include <eez/gui/touch_calibration.h>

#include "app_context.h"
#include "document.h"
#include "keypad.h"

namespace eez {
namespace gui {

DeviceAppContext g_deviceAppContext;

void DeviceAppContext::stateManagment() {
    AppContext::stateManagment();

	// if none page is active then show touch screen calibration page or banner
	if (getActivePageId() == PAGE_ID_NONE) {
		if (!isTouchCalibrated()) {
			enterTouchCalibration(&g_deviceAppContext);
		} else {
			showPage(getMainPageId());
		}
	}

	// play power up tune when banner page shows up
	static bool g_powerUpPlayed;
	if (!g_powerUpPlayed && getActivePageId() == PAGE_ID_MAIN) {
		sound::playPowerUp(sound::PLAY_POWER_UP_CONDITION_NONE);
		g_powerUpPlayed = true;
	}
}

int DeviceAppContext::getMainPageId() {
    return PAGE_ID_MAIN;
}

void DeviceAppContext::pageRenderCustom(int i, WidgetCursor &widgetCursor) {
    if (getActivePageId() == PAGE_ID_TOUCH_CALIBRATION_YES_NO) {
		auto touchEvent = touch::getLastEvent();
        if (touchEvent.type == EVENT_TYPE_TOUCH_DOWN || touchEvent.type == EVENT_TYPE_TOUCH_MOVE) {
            int x = MIN(MAX(touchEvent.x, 1), display::getDisplayWidth() - 2);
            int y = MIN(MAX(touchEvent.y, 1), display::getDisplayHeight() - 2);
            display::setColor(255, 255, 255);
            display::fillRect(x - 1, y - 1, x + 1, y + 1);
        }
    }
}

bool DeviceAppContext::isAutoRepeatAction(int action) {
	return action == ACTION_ID_KEYPAD_BACK;
}

} // namespace gui
} // namespace eez
