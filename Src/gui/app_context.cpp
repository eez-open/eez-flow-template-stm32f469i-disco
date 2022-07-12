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

	if (getActivePageId() == PAGE_ID_NONE) {
		showPage(getMainPageId());
	}
}

int DeviceAppContext::getMainPageId() {
    return PAGE_ID_MAIN;
}

bool DeviceAppContext::isAutoRepeatAction(int action) {
	return action == ACTION_ID_KEYPAD_BACK;
}

} // namespace gui
} // namespace eez
