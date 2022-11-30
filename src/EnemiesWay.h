#pragma once

#include <unordered_map>

#include "Coords.h"
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

    private:

    std::unordered_map<int, Coords> dictOfWaypoints;
};