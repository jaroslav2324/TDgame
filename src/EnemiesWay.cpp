#include "EnemiesWay.h"

EnemiesWay::EnemiesWay(){
    //TODO initialise waypoint coords
}

Coords EnemiesWay::getNextWaypointCoords(int numCurrentWaypoint){
    //TODO check if no more waypoints left
    if (dictOfWaypoints.find(numCurrentWaypoint + 1) != dictOfWaypoints.end())
        return dictOfWaypoints[numCurrentWaypoint + 1];
    // else
}

Coords EnemiesWay::getWaypointCoords(int numWaypoint){

    if (numWaypoint < dictOfWaypoints.size() && numWaypoint > 0)
        return dictOfWaypoints[numWaypoint];
    //TODO else write to log or throw exception
}

Coords EnemiesWay::getFirstCoords(){
    return dictOfWaypoints[0];
}

Coords EnemiesWay::getLastCoords(){
    return dictOfWaypoints[dictOfWaypoints.size() - 1];
}