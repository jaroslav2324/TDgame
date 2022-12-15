#pragma once

#include <unordered_map>
#include <iostream>

#include "SDL2/SDL.h"

#include "../Coords.h"

using std::cout;
using std::endl;
/*
class-conatiner of waypoint coords
portal is always the first waypoint
base is always the last waypoint
*/
class EnemiesWay{
    public:
    EnemiesWay();
    Coords getNextWaypointCoords(int numCurrentWaypoint);
    Coords getFirstCoords();
    Coords getLastCoords();
    Coords getWaypointCoords(int numWaypoint);

    int getAmountWaypoints();

    void render(SDL_Renderer* renderer);

    private:
    int amountWaypoints = -1;

    std::unordered_map<int, Coords> dictOfWaypoints;
};