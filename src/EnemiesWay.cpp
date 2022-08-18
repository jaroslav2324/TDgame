#pragma once

#include <unordered_map>

/*
class-conatiner of waypoint coords
*/
class EnemiesWay{
    public:
    EnemiesWay();
    std::pair<int, int> getNextWaypointCoords(int numCurrentWaypoint);
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