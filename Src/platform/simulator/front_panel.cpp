#include <eez/gui/gui.h>

#include "../../gui/app_context.h"
#include "../../gui/document.h"

#include "front_panel.h"

namespace eez {
namespace gui {

FrontPanelAppContext g_frontPanelAppContext;

////////////////////////////////////////////////////////////////////////////////

void FrontPanelAppContext::stateManagment() {
    AppContext::stateManagment();

    if (getActivePageId() == PAGE_ID_NONE) {
        showPage(getMainPageId());
    }
}

int FrontPanelAppContext::getMainPageId() {
    return PAGE_ID_FRONT_PANEL;
}

int FrontPanelAppContext::getLongTouchActionHook(const WidgetCursor &widgetCursor) {
    return AppContext::getLongTouchActionHook(widgetCursor);
}

////////////////////////////////////////////////////////////////////////////////

void data_main_app_view(DataOperationEnum operation, const WidgetCursor &widgetCursor, Value &value) {
    if (operation == DATA_OPERATION_GET) {
        value = Value(&g_deviceAppContext);
    }
}

} // namespace gui
} // namespace eez
