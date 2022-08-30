#include "EnemiesWay.h"

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