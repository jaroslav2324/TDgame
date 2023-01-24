#pragma once

#include <iostream>
#include <queue>
#include <map>

#include "SDL2/SDL.h"

#include "../EngineSettings.h"
#include "GameEvent.h"

using std::cout;
using std::endl;
using std::queue;
using std::map;

// Class for handle SDL_Events
class SystemEventsHandler{
    public:

    SystemEventsHandler();
    ~SystemEventsHandler();

    // returns 0 if queue is empty otherwise 1
    bool popGameEvent(GameEvent* dstEvent);
    // push to queue of GameEvents
    void pushGameEvent(GameEvent event);
    void pushGameEvent(GameEventType eventType);

    // handle queue of SDL_Events
    void handleSystemEvents();

    private:

    // map<Uint32, CountdownTimer*> delayEventActivateTimers;

    queue<GameEvent> queueOfGameEvents;
};