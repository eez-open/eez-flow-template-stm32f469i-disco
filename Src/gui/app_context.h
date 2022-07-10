#pragma once

#include <eez/gui/gui.h>

using namespace eez::gui;

namespace eez {
namespace gui {

class DeviceAppContext : public AppContext {
public:
    void stateManagment() override;
    void pageRenderCustom(int i, WidgetCursor &widgetCursor) override;
    bool isAutoRepeatAction(int action) override;

protected:
    int getMainPageId() override;
};

extern DeviceAppContext g_deviceAppContext;

} // namespace gui
} // namespace eez