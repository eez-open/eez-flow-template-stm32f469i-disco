#include <eez/core/os.h>
#include <eez/core/eeprom.h>

#include <eez/gui/gui.h>
#include <eez/gui/keypad.h>
#include <eez/gui/touch_calibration.h>
#include <eez/flow/flow.h>

#include "../firmware.h"

#include "app_context.h"
#include "keypad.h"

#if defined(EEZ_PLATFORM_SIMULATOR)
#include "../platform/simulator/front_panel.h"
#endif

#if defined(EEZ_PLATFORM_SIMULATOR)

// for home directory (see getConfFilePath)
#ifdef _WIN32
#undef INPUT
#undef OUTPUT
#include <Shlobj.h>
#include <Windows.h>
#include <direct.h>
#else
#include <string.h>
#include <pwd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#endif

#endif

namespace eez {

#if defined(EEZ_PLATFORM_SIMULATOR)

char *getConfFilePath(const char *file_name) {
	static char file_path[1024];

	*file_path = 0;

#ifdef _WIN32
	if (SUCCEEDED(SHGetFolderPathA(NULL, CSIDL_PROFILE, NULL, 0, file_path))) {
		stringAppendString(file_path, sizeof(file_path), "\\.{{projectName}}");
		_mkdir(file_path);
		stringAppendString(file_path, sizeof(file_path), "\\");
	}
#elif defined(__EMSCRIPTEN__)
	stringAppendString(file_path, sizeof(file_path), "/{{projectName}}/");
#else
	const char *home_dir = 0;
	if ((home_dir = getenv("HOME")) == NULL) {
		home_dir = getpwuid(getuid())->pw_dir;
	}
	if (home_dir) {
		stringAppendString(file_path, sizeof(file_path), home_dir);
		stringAppendString(file_path, sizeof(file_path), "/.{{projectName}}");
		mkdir(file_path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		stringAppendString(file_path, sizeof(file_path), "/");
	}
#endif

	char *q = file_path + strlen(file_path);
	const char *p = file_name;
	while (*p) {
		char ch = *p++;
#ifdef _WIN32
		if (ch == '/')
			*q++ = '\\';
#else
		if (ch == '\\')
			*q++ = '/';
#endif
		else
			*q++ = ch;
	}
	*q = 0;

	return file_path;
}

#endif


namespace gui {

AppContext *getAppContextFromId(int16_t id) {
    if (id == APP_CONTEXT_ID_DEVICE) {
        return &g_deviceAppContext;
    }

#if defined(EEZ_PLATFORM_SIMULATOR)
    if (id == APP_CONTEXT_ID_SIMULATOR_FRONT_PANEL) {
        return &g_frontPanelAppContext;
    }
#endif

    return nullptr;
}

static int overrideStyleHook(const WidgetCursor &widgetCursor, int styleId) {
    return styleId;
}

static bool styleGetSmallerFontHook(font::Font &font) {
    return true;
}

static int getExtraLongTouchActionHook() {
	return ACTION_ID_NONE;
}

void initHooks() {
	g_hooks.overrideStyle = overrideStyleHook;
	g_hooks.getExtraLongTouchAction = getExtraLongTouchActionHook;
	g_hooks.styleGetSmallerFont = styleGetSmallerFontHook;
}

} // namespace gui
} // namespace eez
