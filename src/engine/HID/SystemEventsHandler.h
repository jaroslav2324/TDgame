#pragma once

#include <iostream>
#include <queue>
#include <map>

#include "SDL2/SDL.h"

#include "../EngineSettings.h"
#include "GameEvents.h"

using std::cout;
using std::endl;
using std::queue;
using std::map;

//TODO rename
// Class for handle SDL_Events
class SystemEventsHandler{
    public:

    SystemEventsHandler();
    ~SystemEventsHandler();

    // returns 0 if queue is empty otherwise 1
    bool popGameEvent(GameEvent* dstEvent);
    // push to queue of GameEvents
    void pushGameEvent(GameEvent event);

    // handle queue of SDL_Events
    void handleSystemEvents();

    Coords getCurrentMouseCoords();

    queue<GameEvent>* getQueueOfGameEventsPtr();

    private:

    void saveCurrentMouseCoords();
    Coords savedCurrentMouseCoords;

    queue<GameEvent> queueOfGameEvents;
};