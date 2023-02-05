#pragma once

#include "../EngineSettings.h"
#include "GameEventTypes.h"

struct UndefinedGameEvent{};

struct MouseGameEvent{
    MouseGameEvent(MouseEventType mouseEventType, Coords mouseCoords): mEvType(mouseEventType), mouseCoords(mouseCoords){};

    MouseEventType mEvType;
    Coords mouseCoords;
};

struct KeyboardGameEvent{
    KeyboardGameEvent(KeyboardEventType keyboardEventType): kEvType(keyboardEventType){};
    KeyboardEventType kEvType;
};

//TODO rename
struct GlobalGameEvent{
    GlobalGameEvent(GlobalEventType globalEventType): gEvType(globalEventType){};
    GlobalEventType gEvType;
};

struct GameEvent{

    GameEvent();
    GameEvent(const MouseGameEvent& mouseGameEvent);
    GameEvent(const KeyboardGameEvent& keyboardGameEvent);
    GameEvent(const GlobalGameEvent& globalGameEvent);
    GameEvent(const UndefinedGameEvent& undefinedGameEvent);  

    GameEventType eventType = GameEventType::UNDEFINED_GAME_EVENT;

    union{
        MouseGameEvent mouseGameEvent;
        KeyboardGameEvent keyboardGameEvent;
        GlobalGameEvent globalGameEvent;
        UndefinedGameEvent undefinedGameEvent;
    };

    GameEvent& operator=(const MouseGameEvent& mouseGameEvent);
    GameEvent& operator=(const KeyboardGameEvent& keyboardGameEvent);
    GameEvent& operator=(const GlobalGameEvent& globalGameEvent);
    GameEvent& operator=(const UndefinedGameEvent& undefinedGameEvent);
};
