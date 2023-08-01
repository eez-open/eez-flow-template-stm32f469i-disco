#pragma once

#include <eez/gui/data.h>
#include <eez/gui/widget.h>

namespace eez {
namespace gui {

#if defined(EEZ_PLATFORM_STM32)

enum DataEnum {
    DATA_ID_NONE = 0,
    DATA_ID_ALERT_MESSAGE = 1,
    DATA_ID_KEYPAD_TEXT = 2,
    DATA_ID_KEYPAD_EDIT_UNIT = 3,
    DATA_ID_KEYPAD_SIGN_ENABLED = 4,
    DATA_ID_KEYPAD_UNIT_ENABLED = 5,
    DATA_ID_KEYPAD_DOT_ENABLED = 6,
    DATA_ID_KEYPAD_OPTION1_ENABLED = 7,
    DATA_ID_KEYPAD_OPTION1_TEXT = 8,
    DATA_ID_KEYPAD_OPTION2_ENABLED = 9,
    DATA_ID_KEYPAD_OPTION2_TEXT = 10,
    DATA_ID_KEYPAD_OPTION3_ENABLED = 11,
    DATA_ID_KEYPAD_OPTION3_TEXT = 12,
    DATA_ID_KEYPAD_MODE = 13,
    DATA_ID_KEYPAD_OK_ENABLED = 14
};

void data_none(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_alert_message(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_text(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_edit_unit(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_sign_enabled(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_unit_enabled(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_dot_enabled(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_option1_enabled(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_option1_text(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_option2_enabled(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_option2_text(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_option3_enabled(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_option3_text(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_mode(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_ok_enabled(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);

typedef void (*DataOperationsFunction)(DataOperationEnum operation, const WidgetCursor &widgetCursor, Value &value);

extern DataOperationsFunction g_dataOperationsFunctions[];

enum ActionsEnum {
    ACTION_ID_NONE = 0,
    ACTION_ID_YES = 1,
    ACTION_ID_NO = 2,
    ACTION_ID_CANCEL = 3,
    ACTION_ID_EDIT = 4,
    ACTION_ID_DRAG_OVERLAY = 5,
    ACTION_ID_SCROLL = 6,
    ACTION_ID_KEYPAD_KEY = 7,
    ACTION_ID_KEYPAD_BACK = 8,
    ACTION_ID_KEYPAD_UNIT = 9,
    ACTION_ID_KEYPAD_OPTION1 = 10,
    ACTION_ID_KEYPAD_OPTION2 = 11,
    ACTION_ID_KEYPAD_OPTION3 = 12,
    ACTION_ID_KEYPAD_SIGN = 13,
    ACTION_ID_KEYPAD_OK = 14,
    ACTION_ID_KEYPAD_CANCEL = 15,
    ACTION_ID_TOGGLE_KEYPAD_MODE = 16,
    ACTION_ID_KEYPAD_SPACE = 17
};

void action_yes();
void action_no();
void action_cancel();
void action_edit();
void action_drag_overlay();
void action_scroll();
void action_keypad_key();
void action_keypad_back();
void action_keypad_unit();
void action_keypad_option1();
void action_keypad_option2();
void action_keypad_option3();
void action_keypad_sign();
void action_keypad_ok();
void action_keypad_cancel();
void action_toggle_keypad_mode();
void action_keypad_space();

extern ActionExecFunc g_actionExecFunctions[];

enum FontsEnum {
    FONT_ID_NONE = 0,
    FONT_ID_ICONS = 1,
    FONT_ID_SHADOW = 2,
    FONT_ID_TEXT_M = 3,
    FONT_ID_TEXT_L = 4,
    FONT_ID_TEXT_XL = 5,
    FONT_ID_TEXT_XXL = 6
};

enum BitmapsEnum {
    BITMAP_ID_NONE = 0
};

enum StylesEnum {
    STYLE_ID_NONE = 0,
    STYLE_ID_DEFAULT = 1,
    STYLE_ID_INFO_ALERT = 2,
    STYLE_ID_ERROR_ALERT = 3,
    STYLE_ID_ERROR_ALERT_BUTTON = 4,
    STYLE_ID_SELECT_ENUM_ITEM_POPUP_CONTAINER = 5,
    STYLE_ID_SELECT_ENUM_ITEM_POPUP_CONTAINER_S = 6,
    STYLE_ID_SELECT_ENUM_ITEM_POPUP_ITEM = 7,
    STYLE_ID_SELECT_ENUM_ITEM_POPUP_ITEM_S = 8,
    STYLE_ID_SELECT_ENUM_ITEM_POPUP_DISABLED_ITEM = 9,
    STYLE_ID_SELECT_ENUM_ITEM_POPUP_DISABLED_ITEM_S = 10,
    STYLE_ID_MENU_WITH_BUTTONS_MESSAGE = 11,
    STYLE_ID_MENU_WITH_BUTTONS_CONTAINER = 12,
    STYLE_ID_MENU_WITH_BUTTONS_BUTTON = 13,
    STYLE_ID_FPS_GRAPH = 14,
    STYLE_ID_SLIDER = 15,
    STYLE_ID_SWITCH = 16,
    STYLE_ID_BACKGROUND = 17,
    STYLE_ID_BUTTON = 18,
    STYLE_ID_BUTTON_DISABLED = 19,
    STYLE_ID_NOTE_M = 20,
    STYLE_ID_DROP_DOWN_LIST = 21,
    STYLE_ID_ROLLER = 22,
    STYLE_ID_ROLLER_SELECTED_VALUE = 23,
    STYLE_ID_ROLLER_UNSELECTED_VALUE = 24
};

enum ThemesEnum {
    THEME_ID_DEFAULT = 0
};

enum ColorsEnum {
    COLOR_ID_TRANSPARENT = 65535,
    COLOR_ID_BACKGROUND = 0,
    COLOR_ID_BACKDROP = 1,
    COLOR_ID_TEXT = 2,
    COLOR_ID_TEXT_INACTIVE = 3,
    COLOR_ID_DARK_TEXT = 4,
    COLOR_ID_BORDER = 5,
    COLOR_ID_ACTIVE_BACKGROUND = 6,
    COLOR_ID_BUTTON_TEXT = 7,
    COLOR_ID_BUTTON_BACKGROUND = 8,
    COLOR_ID_BUTTON_ACTIVE_BACKGROUND = 9,
    COLOR_ID_BUTTON_BORDER = 10,
    COLOR_ID_BUTTON_DISABLED_TEXT = 11,
    COLOR_ID_BUTTON_DISABLED_BACKGROUND = 12,
    COLOR_ID_BUTTON_DISABLED_BORDER = 13,
    COLOR_ID_ERROR = 14,
    COLOR_ID_NOTE = 15,
    COLOR_ID_SWITCH_WIDGET_COLOR = 16,
    COLOR_ID_SWITCH_WIDGET_BACKGROUND_ON = 17,
    COLOR_ID_SWITCH_WIDGET_BACKGROUND_OFF = 18,
    COLOR_ID_SWITCH_WIDGET_BORDER = 19,
    COLOR_ID_SLIDER_WIDGET_COLOR = 20,
    COLOR_ID_SLIDER_WIDGET_BACKGROUND = 21,
    COLOR_ID_DROP_DOWN_LIST_COLOR = 22,
    COLOR_ID_DROP_DOWN_LIST_COLOR_DISABLED = 23,
    COLOR_ID_DROP_DOWN_LIST_BACKGROUND = 24,
    COLOR_ID_DROP_DOWN_LIST_BORDER = 25,
    COLOR_ID_DROP_DOWN_LIST_ACTIVE_BACKGROUND = 26,
    COLOR_ID_TEXT_INPUT_COLOR = 27,
    COLOR_ID_TEXT_INPUT_COLOR_DISABLED = 28,
    COLOR_ID_TEXT_INPUT_BACKGROUND = 29,
    COLOR_ID_TEXT_INPUT_ACTIVE_BACKGROUND = 30,
    COLOR_ID_TEXT_INPUT_BORDER = 31,
	COLOR_ID_CUSTOM_000000 = 32,
	COLOR_ID_CUSTOM_FFFFFF = 33,
	COLOR_ID_CUSTOM_00FF1E = 34,
	COLOR_ID_CUSTOM_C0C0C0 = 35,
	COLOR_ID_CUSTOM_808080 = 36
};

enum PagesEnum {
    PAGE_ID_NONE = 0,
    PAGE_ID_MAIN = 1,
    PAGE_ID_NUMERIC_KEYPAD = 2,
    PAGE_ID_KEYBOARD = 3
};

extern const uint8_t assets[59128];

#elif defined(EEZ_PLATFORM_SIMULATOR)

enum DataEnum {
    DATA_ID_NONE = 0,
    DATA_ID_ALERT_MESSAGE = 1,
    DATA_ID_KEYPAD_TEXT = 2,
    DATA_ID_KEYPAD_EDIT_UNIT = 3,
    DATA_ID_KEYPAD_SIGN_ENABLED = 4,
    DATA_ID_KEYPAD_UNIT_ENABLED = 5,
    DATA_ID_KEYPAD_DOT_ENABLED = 6,
    DATA_ID_KEYPAD_OPTION1_ENABLED = 7,
    DATA_ID_KEYPAD_OPTION1_TEXT = 8,
    DATA_ID_KEYPAD_OPTION2_ENABLED = 9,
    DATA_ID_KEYPAD_OPTION2_TEXT = 10,
    DATA_ID_KEYPAD_OPTION3_ENABLED = 11,
    DATA_ID_KEYPAD_OPTION3_TEXT = 12,
    DATA_ID_KEYPAD_MODE = 13,
    DATA_ID_KEYPAD_OK_ENABLED = 14,
    DATA_ID_MAIN_APP_VIEW = 15
};

void data_none(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_alert_message(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_text(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_edit_unit(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_sign_enabled(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_unit_enabled(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_dot_enabled(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_option1_enabled(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_option1_text(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_option2_enabled(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_option2_text(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_option3_enabled(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_option3_text(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_mode(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_keypad_ok_enabled(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_main_app_view(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);

typedef void (*DataOperationsFunction)(DataOperationEnum operation, const WidgetCursor &widgetCursor, Value &value);

extern DataOperationsFunction g_dataOperationsFunctions[];

enum ActionsEnum {
    ACTION_ID_NONE = 0,
    ACTION_ID_YES = 1,
    ACTION_ID_NO = 2,
    ACTION_ID_CANCEL = 3,
    ACTION_ID_EDIT = 4,
    ACTION_ID_DRAG_OVERLAY = 5,
    ACTION_ID_SCROLL = 6,
    ACTION_ID_KEYPAD_KEY = 7,
    ACTION_ID_KEYPAD_BACK = 8,
    ACTION_ID_KEYPAD_UNIT = 9,
    ACTION_ID_KEYPAD_OPTION1 = 10,
    ACTION_ID_KEYPAD_OPTION2 = 11,
    ACTION_ID_KEYPAD_OPTION3 = 12,
    ACTION_ID_KEYPAD_SIGN = 13,
    ACTION_ID_KEYPAD_OK = 14,
    ACTION_ID_KEYPAD_CANCEL = 15,
    ACTION_ID_TOGGLE_KEYPAD_MODE = 16,
    ACTION_ID_KEYPAD_SPACE = 17
};

void action_yes();
void action_no();
void action_cancel();
void action_edit();
void action_drag_overlay();
void action_scroll();
void action_keypad_key();
void action_keypad_back();
void action_keypad_unit();
void action_keypad_option1();
void action_keypad_option2();
void action_keypad_option3();
void action_keypad_sign();
void action_keypad_ok();
void action_keypad_cancel();
void action_toggle_keypad_mode();
void action_keypad_space();

extern ActionExecFunc g_actionExecFunctions[];

enum FontsEnum {
    FONT_ID_NONE = 0,
    FONT_ID_ICONS = 1,
    FONT_ID_SHADOW = 2,
    FONT_ID_TEXT_M = 3,
    FONT_ID_TEXT_L = 4,
    FONT_ID_TEXT_XL = 5,
    FONT_ID_TEXT_XXL = 6
};

enum BitmapsEnum {
    BITMAP_ID_NONE = 0,
    BITMAP_ID_FRONT_PANEL = 1
};

enum StylesEnum {
    STYLE_ID_NONE = 0,
    STYLE_ID_DEFAULT = 1,
    STYLE_ID_INFO_ALERT = 2,
    STYLE_ID_ERROR_ALERT = 3,
    STYLE_ID_ERROR_ALERT_BUTTON = 4,
    STYLE_ID_SELECT_ENUM_ITEM_POPUP_CONTAINER = 5,
    STYLE_ID_SELECT_ENUM_ITEM_POPUP_CONTAINER_S = 6,
    STYLE_ID_SELECT_ENUM_ITEM_POPUP_ITEM = 7,
    STYLE_ID_SELECT_ENUM_ITEM_POPUP_ITEM_S = 8,
    STYLE_ID_SELECT_ENUM_ITEM_POPUP_DISABLED_ITEM = 9,
    STYLE_ID_SELECT_ENUM_ITEM_POPUP_DISABLED_ITEM_S = 10,
    STYLE_ID_MENU_WITH_BUTTONS_MESSAGE = 11,
    STYLE_ID_MENU_WITH_BUTTONS_CONTAINER = 12,
    STYLE_ID_MENU_WITH_BUTTONS_BUTTON = 13,
    STYLE_ID_FPS_GRAPH = 14,
    STYLE_ID_SLIDER = 15,
    STYLE_ID_SWITCH = 16,
    STYLE_ID_BACKGROUND = 17,
    STYLE_ID_BUTTON = 18,
    STYLE_ID_BUTTON_DISABLED = 19,
    STYLE_ID_NOTE_M = 20,
    STYLE_ID_DROP_DOWN_LIST = 21,
    STYLE_ID_ROLLER = 22,
    STYLE_ID_ROLLER_SELECTED_VALUE = 23,
    STYLE_ID_ROLLER_UNSELECTED_VALUE = 24
};

enum ThemesEnum {
    THEME_ID_DEFAULT = 0
};

enum ColorsEnum {
    COLOR_ID_TRANSPARENT = 65535,
    COLOR_ID_BACKGROUND = 0,
    COLOR_ID_BACKDROP = 1,
    COLOR_ID_TEXT = 2,
    COLOR_ID_TEXT_INACTIVE = 3,
    COLOR_ID_DARK_TEXT = 4,
    COLOR_ID_BORDER = 5,
    COLOR_ID_ACTIVE_BACKGROUND = 6,
    COLOR_ID_BUTTON_TEXT = 7,
    COLOR_ID_BUTTON_BACKGROUND = 8,
    COLOR_ID_BUTTON_ACTIVE_BACKGROUND = 9,
    COLOR_ID_BUTTON_BORDER = 10,
    COLOR_ID_BUTTON_DISABLED_TEXT = 11,
    COLOR_ID_BUTTON_DISABLED_BACKGROUND = 12,
    COLOR_ID_BUTTON_DISABLED_BORDER = 13,
    COLOR_ID_ERROR = 14,
    COLOR_ID_NOTE = 15,
    COLOR_ID_SWITCH_WIDGET_COLOR = 16,
    COLOR_ID_SWITCH_WIDGET_BACKGROUND_ON = 17,
    COLOR_ID_SWITCH_WIDGET_BACKGROUND_OFF = 18,
    COLOR_ID_SWITCH_WIDGET_BORDER = 19,
    COLOR_ID_SLIDER_WIDGET_COLOR = 20,
    COLOR_ID_SLIDER_WIDGET_BACKGROUND = 21,
    COLOR_ID_DROP_DOWN_LIST_COLOR = 22,
    COLOR_ID_DROP_DOWN_LIST_COLOR_DISABLED = 23,
    COLOR_ID_DROP_DOWN_LIST_BACKGROUND = 24,
    COLOR_ID_DROP_DOWN_LIST_BORDER = 25,
    COLOR_ID_DROP_DOWN_LIST_ACTIVE_BACKGROUND = 26,
    COLOR_ID_TEXT_INPUT_COLOR = 27,
    COLOR_ID_TEXT_INPUT_COLOR_DISABLED = 28,
    COLOR_ID_TEXT_INPUT_BACKGROUND = 29,
    COLOR_ID_TEXT_INPUT_ACTIVE_BACKGROUND = 30,
    COLOR_ID_TEXT_INPUT_BORDER = 31,
	COLOR_ID_CUSTOM_000000 = 32,
	COLOR_ID_CUSTOM_FFFFFF = 33,
	COLOR_ID_CUSTOM_00FF1E = 34,
	COLOR_ID_CUSTOM_C0C0C0 = 35,
	COLOR_ID_CUSTOM_808080 = 36
};

enum PagesEnum {
    PAGE_ID_NONE = 0,
    PAGE_ID_MAIN = 1,
    PAGE_ID_NUMERIC_KEYPAD = 2,
    PAGE_ID_KEYBOARD = 3,
    PAGE_ID_FRONT_PANEL = 4
};

extern const uint8_t assets[75517];

#endif

} // namespace gui
} // namespace eez
