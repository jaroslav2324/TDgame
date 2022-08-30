#pragma once

#include <unordered_map>

/*
class-conatiner of waypoint coords
portal is always the first waypoint
base is always the last waypoint
*/
class EnemiesWay{
    public:
    EnemiesWay();
    std::pair<int, int> getNextWaypointCoords(int numCurrentWaypoint);
    std::pair<int, int> getFirstCoords();
    std::pair<int, int> getLastCoords();
    std::pair<int, int> getWaypointCoords(int numWaypoint);

    private:

    std::unordered_map<int, std::pair<int, int>> dictOfWaypoints;
};