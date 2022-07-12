#pragma once

#include <eez/gui/gui.h>

using namespace eez::gui;

namespace eez {
namespace gui {

class DeviceAppContext : public AppContext {
public:
    void stateManagment() override;
    bool isAutoRepeatAction(int action) override;

protected:
    int getMainPageId() override;
};

extern DeviceAppContext g_deviceAppContext;

} // namespace gui
} // namespace eez