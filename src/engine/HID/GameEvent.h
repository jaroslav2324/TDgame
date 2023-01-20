#pragma once

#include "GameEventType.h"

struct GameEvent{
    GameEvent(GameEventType gameEventType): eventType(gameEventType){};
    GameEventType eventType;
};