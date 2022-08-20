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

EnemiesWay::EnemiesWay(){
    //TODO initialise waypoint coords
}

std::pair<int, int> EnemiesWay::getNextWaypointCoords(int numCurrentWaypoint){
    //TODO check if no more waypoints left
    if (dictOfWaypoints.find(numCurrentWaypoint + 1) != dictOfWaypoints.end())
        return dictOfWaypoints[numCurrentWaypoint + 1];
    // else
}

std::pair<int, int> EnemiesWay::getWaypointCoords(int numWaypoint){

    if (numWaypoint < dictOfWaypoints.size() && numWaypoint > 0)
        return dictOfWaypoints[numWaypoint];
    //TODO else write to log or throw exception
}

std::pair<int, int> EnemiesWay::getFirstCoords(){
    return dictOfWaypoints[0];
}

std::pair<int, int> EnemiesWay::getLastCoords(){
    return dictOfWaypoints[dictOfWaypoints.size() - 1];
}