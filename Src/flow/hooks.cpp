#include <assert.h>

#include <eez/flow/flow.h>
#include <eez/flow/hooks.h>

#include "../gui/app_context.h"
#include "../gui/keypad.h"

namespace eez {
namespace flow {

void showKeyboard(Value label, Value initialText, Value minChars, Value maxChars, bool isPassword, void(*onOk)(char *), void(*onCancel)()) {
	eez::gui::startTextKeyboard(label.getString(), initialText.getString(), minChars.toInt32(), maxChars.toInt32(), isPassword, onOk, onCancel, nullptr);
}

void showKeypad(Value label, Value initialValue, Value min, Value max, Unit unit, void(*onOk)(float), void(*onCancel)()) {
	NumericKeypadOptions options;
	options.pageId = PAGE_ID_NUMERIC_KEYPAD;
	options.min = min.toFloat();
	options.max = max.toFloat();
	options.editValueUnit = unit;

	eez::gui::startNumericKeypad(&g_deviceAppContext, label.getString(), initialValue, options, onOk, nullptr, onCancel);
}

void initHooks() {
	showKeyboardHook = showKeyboard;
	showKeypadHook = showKeypad;
}

} // namespace flow
} // namespace eez
