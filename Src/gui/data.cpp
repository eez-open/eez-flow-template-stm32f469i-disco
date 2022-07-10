#include <eez/core/alloc.h>
#include <eez/core/os.h>
#include <limits.h>

#include <eez/gui/gui.h>
#include <eez/gui/draw.h>

#include "../date_time.h"
#include "../firmware.h"

namespace eez {
namespace gui {

const EnumItem *g_enumDefinitions[] = { nullptr };

void data_date_year(DataOperationEnum operation, const WidgetCursor &widgetCursor, Value &value) {
    value = date_time::g_dateTime.year + 2000;
}

void data_date_month(DataOperationEnum operation, const WidgetCursor &widgetCursor, Value &value) {
    value = date_time::g_dateTime.month;
}

void data_date_day(DataOperationEnum operation, const WidgetCursor &widgetCursor, Value &value) {
    value = date_time::g_dateTime.day;
}

void data_time_hour(DataOperationEnum operation, const WidgetCursor &widgetCursor, Value &value) {
    value = date_time::g_dateTime.hour;
}

void data_time_minute(DataOperationEnum operation, const WidgetCursor &widgetCursor, Value &value) {
    value = date_time::g_dateTime.minute;
}

void data_time_second(DataOperationEnum operation, const WidgetCursor &widgetCursor, Value &value) {
    value = date_time::g_dateTime.second;
}

void data_time_sub_second(DataOperationEnum operation, const WidgetCursor &widgetCursor, Value &value) {
    value = date_time::g_dateTime.subSecond;
}

} // namespace gui
} // namespace eez
