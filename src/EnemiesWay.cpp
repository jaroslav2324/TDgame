#include "EnemiesWay.h"

EnemiesWay::EnemiesWay(){
    //TODO find more convenient way to fill waypoints
    amountWaypoints = 10;

    int numWaypoint = 0;
    dictOfWaypoints[numWaypoint] = Coords(400, 200);
    numWaypoint++;
    dictOfWaypoints[numWaypoint] = Coords(500, 200);
    numWaypoint++;
    dictOfWaypoints[numWaypoint] = Coords(500, 300);
    numWaypoint++;
    dictOfWaypoints[numWaypoint] = Coords(400, 400);
    numWaypoint++;
    dictOfWaypoints[numWaypoint] = Coords(300, 500);
    numWaypoint++;
    dictOfWaypoints[numWaypoint] = Coords(500, 400);
    numWaypoint++;
    dictOfWaypoints[numWaypoint] = Coords(700, 500);
    numWaypoint++;
    dictOfWaypoints[numWaypoint] = Coords(600, 500);
    numWaypoint++;
    dictOfWaypoints[numWaypoint] = Coords(600, 600);
    numWaypoint++;
    dictOfWaypoints[numWaypoint] = Coords(500, 500);
}

// if there is no next waypoint returns current waypoint
Coords EnemiesWay::getNextWaypointCoords(int numCurrentWaypoint){

    if (dictOfWaypoints.find(numCurrentWaypoint + 1) != dictOfWaypoints.end())
        return dictOfWaypoints[numCurrentWaypoint + 1];
    else return dictOfWaypoints[numCurrentWaypoint];
}

Coords EnemiesWay::getWaypointCoords(int numWaypoint){

    if (numWaypoint < amountWaypoints && numWaypoint >= 0)
        return dictOfWaypoints[numWaypoint];
        
    cout << "Use of wrong waypoint number in enemies way!" << endl;
    return Coords(0, 0);
}

Coords EnemiesWay::getFirstCoords(){
    return dictOfWaypoints[0];
}

Coords EnemiesWay::getLastCoords(){
    return dictOfWaypoints[amountWaypoints - 1];
}

int EnemiesWay::getAmountWaypoints(){
    return amountWaypoints;
}