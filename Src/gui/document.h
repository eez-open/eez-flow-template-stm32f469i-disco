#pragma once

#include <eez/gui/data.h>
#include <eez/gui/widget.h>

namespace eez {
namespace gui {

#if defined(EEZ_PLATFORM_STM32)

enum DataEnum {
    DATA_ID_NONE = 0,
    DATA_ID_ALERT_MESSAGE = 1,
    DATA_ID_TOUCH_CALIBRATION_POINT = 2,
    DATA_ID_KEYPAD_TEXT = 3,
    DATA_ID_KEYPAD_EDIT_UNIT = 4,
    DATA_ID_KEYPAD_SIGN_ENABLED = 5,
    DATA_ID_KEYPAD_UNIT_ENABLED = 6,
    DATA_ID_KEYPAD_DOT_ENABLED = 7,
    DATA_ID_KEYPAD_OPTION1_ENABLED = 8,
    DATA_ID_KEYPAD_OPTION1_TEXT = 9,
    DATA_ID_KEYPAD_OPTION2_ENABLED = 10,
    DATA_ID_KEYPAD_OPTION2_TEXT = 11,
    DATA_ID_KEYPAD_OPTION3_ENABLED = 12,
    DATA_ID_KEYPAD_OPTION3_TEXT = 13,
    DATA_ID_KEYPAD_MODE = 14,
    DATA_ID_KEYPAD_OK_ENABLED = 15
};

void data_none(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_alert_message(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_touch_calibration_point(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
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
    FONT_ID_SHADOW = 1,
    FONT_ID_ICONS = 2,
    FONT_ID_MEDIUM = 3,
    FONT_ID_OSWALD_24 = 4,
    FONT_ID_GUI_ICONS = 5,
    FONT_ID_OSWALD_38 = 6,
    FONT_ID_OSWALD_17 = 7
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
    STYLE_ID_BACKGROUND = 15,
    STYLE_ID_INLINE15 = 16,
    STYLE_ID_INLINE16 = 17,
    STYLE_ID_INLINE17 = 18,
    STYLE_ID_DEFAULT_24 = 19,
    STYLE_ID_BUTTON = 20,
    STYLE_ID_BUTTON_DISABLED = 21,
    STYLE_ID_TOUCH_CALIBRATION = 22,
    STYLE_ID_NOTE_M = 23,
    STYLE_ID_TOUCH_CALIBRATION_POINT = 24,
    STYLE_ID_DEFAULT_38 = 25,
    STYLE_ID_DISABLED_BUTTON = 26,
    STYLE_ID_BUTTON_ICON = 27,
    STYLE_ID_TEXT_INPUT = 28,
    STYLE_ID_TEXT_BUTTON = 29,
    STYLE_ID_TEXT_BUTTON_ICON = 30,
    STYLE_ID_TEXT_BUTTON_ICON_DISABLED = 31,
    STYLE_ID_TAB = 32,
    STYLE_ID_QUOTE = 33,
    STYLE_ID_INLINE33 = 34,
    STYLE_ID_INLINE34 = 35,
    STYLE_ID_BLOCK = 36,
    STYLE_ID_INLINE36 = 37,
    STYLE_ID_INLINE37 = 38,
    STYLE_ID_LABEL_LEFT_ALIGNED = 39,
    STYLE_ID_BUTTON_LARGE = 40
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
	COLOR_ID_CUSTOM_UNDEFINED = 32,
	COLOR_ID_CUSTOM_000000 = 33,
	COLOR_ID_CUSTOM_00FF1E = 34,
	COLOR_ID_CUSTOM_3510E6 = 35,
	COLOR_ID_CUSTOM_14D224 = 36,
	COLOR_ID_CUSTOM_EC2A15 = 37,
	COLOR_ID_CUSTOM_FFFFFF = 38,
	COLOR_ID_CUSTOM_00FF00 = 39,
	COLOR_ID_CUSTOM_B9F3F0 = 40,
	COLOR_ID_CUSTOM_EEE30F = 41,
	COLOR_ID_CUSTOM_C8C8C8 = 42,
	COLOR_ID_CUSTOM_C0C0C0 = 43,
	COLOR_ID_CUSTOM_808080 = 44
};

enum PagesEnum {
    PAGE_ID_NONE = 0,
    PAGE_ID_MAIN = 1,
    PAGE_ID_TOUCH_CALIBRATION = 2,
    PAGE_ID_TOUCH_CALIBRATION_YES_NO = 3,
    PAGE_ID_NUMERIC_KEYPAD = 4,
    PAGE_ID_KEYBOARD = 5,
    PAGE_ID_ANIM_DEMO = 6,
    PAGE_ID_ANIM1 = 7,
    PAGE_ID_INPUT_DEMO = 8,
    PAGE_ID_ROLLER_INPUT_DEMO = 9
};

extern const uint8_t assets[68251];

#elif defined(EEZ_PLATFORM_SIMULATOR)

enum DataEnum {
    DATA_ID_NONE = 0,
    DATA_ID_ALERT_MESSAGE = 1,
    DATA_ID_TOUCH_CALIBRATION_POINT = 2,
    DATA_ID_KEYPAD_TEXT = 3,
    DATA_ID_KEYPAD_EDIT_UNIT = 4,
    DATA_ID_KEYPAD_SIGN_ENABLED = 5,
    DATA_ID_KEYPAD_UNIT_ENABLED = 6,
    DATA_ID_KEYPAD_DOT_ENABLED = 7,
    DATA_ID_KEYPAD_OPTION1_ENABLED = 8,
    DATA_ID_KEYPAD_OPTION1_TEXT = 9,
    DATA_ID_KEYPAD_OPTION2_ENABLED = 10,
    DATA_ID_KEYPAD_OPTION2_TEXT = 11,
    DATA_ID_KEYPAD_OPTION3_ENABLED = 12,
    DATA_ID_KEYPAD_OPTION3_TEXT = 13,
    DATA_ID_KEYPAD_MODE = 14,
    DATA_ID_KEYPAD_OK_ENABLED = 15,
    DATA_ID_MAIN_APP_VIEW = 16
};

void data_none(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_alert_message(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
void data_touch_calibration_point(DataOperationEnum operation, const WidgetCursor &cursor, Value &value);
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
    FONT_ID_SHADOW = 1,
    FONT_ID_ICONS = 2,
    FONT_ID_MEDIUM = 3,
    FONT_ID_OSWALD_24 = 4,
    FONT_ID_GUI_ICONS = 5,
    FONT_ID_OSWALD_38 = 6,
    FONT_ID_OSWALD_17 = 7
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
    STYLE_ID_BACKGROUND = 15,
    STYLE_ID_INLINE15 = 16,
    STYLE_ID_INLINE16 = 17,
    STYLE_ID_INLINE17 = 18,
    STYLE_ID_DEFAULT_24 = 19,
    STYLE_ID_BUTTON = 20,
    STYLE_ID_BUTTON_DISABLED = 21,
    STYLE_ID_TOUCH_CALIBRATION = 22,
    STYLE_ID_NOTE_M = 23,
    STYLE_ID_TOUCH_CALIBRATION_POINT = 24,
    STYLE_ID_DEFAULT_38 = 25,
    STYLE_ID_DISABLED_BUTTON = 26,
    STYLE_ID_BUTTON_ICON = 27,
    STYLE_ID_TEXT_INPUT = 28,
    STYLE_ID_TEXT_BUTTON = 29,
    STYLE_ID_TEXT_BUTTON_ICON = 30,
    STYLE_ID_TEXT_BUTTON_ICON_DISABLED = 31,
    STYLE_ID_TAB = 32,
    STYLE_ID_QUOTE = 33,
    STYLE_ID_INLINE33 = 34,
    STYLE_ID_INLINE34 = 35,
    STYLE_ID_BLOCK = 36,
    STYLE_ID_INLINE36 = 37,
    STYLE_ID_INLINE37 = 38,
    STYLE_ID_LABEL_LEFT_ALIGNED = 39,
    STYLE_ID_BUTTON_LARGE = 40,
    STYLE_ID_INLINE40 = 41
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
	COLOR_ID_CUSTOM_UNDEFINED = 32,
	COLOR_ID_CUSTOM_000000 = 33,
	COLOR_ID_CUSTOM_00FF1E = 34,
	COLOR_ID_CUSTOM_3510E6 = 35,
	COLOR_ID_CUSTOM_14D224 = 36,
	COLOR_ID_CUSTOM_EC2A15 = 37,
	COLOR_ID_CUSTOM_FFFFFF = 38,
	COLOR_ID_CUSTOM_00FF00 = 39,
	COLOR_ID_CUSTOM_B9F3F0 = 40,
	COLOR_ID_CUSTOM_EEE30F = 41,
	COLOR_ID_CUSTOM_C8C8C8 = 42,
	COLOR_ID_CUSTOM_C0C0C0 = 43,
	COLOR_ID_CUSTOM_808080 = 44
};

enum PagesEnum {
    PAGE_ID_NONE = 0,
    PAGE_ID_MAIN = 1,
    PAGE_ID_TOUCH_CALIBRATION = 2,
    PAGE_ID_TOUCH_CALIBRATION_YES_NO = 3,
    PAGE_ID_NUMERIC_KEYPAD = 4,
    PAGE_ID_KEYBOARD = 5,
    PAGE_ID_ANIM_DEMO = 6,
    PAGE_ID_ANIM1 = 7,
    PAGE_ID_INPUT_DEMO = 8,
    PAGE_ID_ROLLER_INPUT_DEMO = 9,
    PAGE_ID_FRONT_PANEL = 10
};

extern const uint8_t assets[84703];

#endif

} // namespace gui
} // namespace eez
