#include "GameEvents.h"

GameEvent::GameEvent(){
    this->eventType = GameEventType::UNDEFINED_GAME_EVENT;
    this->undefinedGameEvent = UndefinedGameEvent();
}

GameEvent::GameEvent(const KeyboardGameEvent& keyboardGameEvent){
    this->operator=(keyboardGameEvent);
}

GameEvent::GameEvent(const MouseGameEvent& mouseGameEvent){
    this->operator=(mouseGameEvent);
}
GameEvent::GameEvent(const GlobalGameEvent& globalGameEvent){
    this->operator=(globalGameEvent);
}
GameEvent::GameEvent(const UndefinedGameEvent& undefinedGameEvent){
    this->operator=(undefinedGameEvent);
}

GameEvent& GameEvent::operator=(const MouseGameEvent& mouseGameEvent){
    this->mouseGameEvent = mouseGameEvent;
    this->eventType = GameEventType::MOUSE_EVENT;
    return *this;
}

GameEvent& GameEvent::operator=(const KeyboardGameEvent& keyboardGameEvent){
    this->keyboardGameEvent = keyboardGameEvent;
    this->eventType = GameEventType::KEYBOARD_EVENT;
    return *this;
}

GameEvent& GameEvent::operator=(const GlobalGameEvent& globalGameEvent){
    this->globalGameEvent = globalGameEvent;
    this->eventType = GameEventType::GLOBAL_EVENT;
    return *this;
}

GameEvent& GameEvent::operator=(const UndefinedGameEvent& undefinedGameEvent){
    this->undefinedGameEvent = undefinedGameEvent;
    this->eventType = GameEventType::UNDEFINED_GAME_EVENT;
    return *this;
}
