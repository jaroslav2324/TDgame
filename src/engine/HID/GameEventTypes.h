#pragma once

enum class GameEventType{
    UNDEFINED_GAME_EVENT,
    MOUSE_EVENT,
    KEYBOARD_EVENT,
    //TODO rename
    GLOBAL_EVENT
};

enum class MouseEventType{
    MOUSE_LEFT_BTN_PRESSED,
    MOUSE_LEFT_BTN_RELEASED
};

enum class KeyboardEventType{
    w_PRESSED,
    w_RELEASED,
    s_PRESSED,
    s_RELEASED
};

//TODO rename
enum class GlobalEventType{
    QUIT_GAME
};
