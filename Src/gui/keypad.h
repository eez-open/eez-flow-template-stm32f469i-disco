#pragma once

#include <eez/gui/keypad.h>

namespace eez {
namespace gui {

NumericKeypad *startNumericKeypad(
	AppContext *appContext,
	const char *label,
	const Value &value,
	NumericKeypadOptions &options,
	void(*okFloat)(float),
	void(*okUint32)(uint32_t),
	void(*cancel)()
);

void startTextKeyboard(
	const char *label,
	const char *text,
	int minChars_,
	int maxChars_,
	bool isPassword_,
	void(*ok)(char *),
	void(*cancel)(),
	void(*setDefault)()
);

} // namespace gui
} // namespace eez
