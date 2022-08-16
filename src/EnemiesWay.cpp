#pragma once

#include <unordered_map>

/*
class-conatiner of waypoint coords
*/
class EnemiesWay{
    public:
    EnemiesWay();
    std::pair<int, int> getNextVaypointCoords(int numCurrentWaypoint);

    private:

    std::unordered_map<int, std::pair<int, int>> dictOfWaypoints;
};

EnemiesWay::EnemiesWay(){
    //TODO initialise waypoint coords
}

std::pair<int, int> EnemiesWay::getNextVaypointCoords(int numCurrentWaypoint){
    //TODO check if no more waypoints left
    if (dictOfWaypoints.find(numCurrentWaypoint + 1) != dictOfWaypoints.end())
        return dictOfWaypoints[numCurrentWaypoint + 1];
    // else
}