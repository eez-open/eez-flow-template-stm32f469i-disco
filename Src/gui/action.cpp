#include <eez/gui/gui.h>

#include <eez/core/util.h>
#include <eez/gui/widgets/input.h>

#include "../firmware.h"
#include "app_context.h"
#include "keypad.h"

namespace eez {
namespace gui {

void action_show_toast_message1() {
	g_deviceAppContext.infoMessage("This is info message\nWith line 2!");
}

void action_show_toast_message2() {
	g_deviceAppContext.errorMessage("This is error message\nWith line 2 ...\nand line 3!", true);
}

void doAction() {
    g_deviceAppContext.infoMessage("It should be fixed now!");
}

void action_show_toast_message3() {
	g_deviceAppContext.errorMessageWithAction("Some error occured!\nYou should fix it.", doAction, "Fix");
}

} // namespace gui
} // namespace eez
