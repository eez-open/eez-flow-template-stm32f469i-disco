#pragma once

#include <eez/gui/gui.h>

using namespace eez::gui;

namespace eez {
namespace gui {

class FrontPanelAppContext : public AppContext {
public:
    void stateManagment() override;

    int getLongTouchActionHook(const WidgetCursor &widgetCursor) override;

protected:
    int getMainPageId() override;
};

extern FrontPanelAppContext g_frontPanelAppContext;

} // namespace gui
} // namespace eez