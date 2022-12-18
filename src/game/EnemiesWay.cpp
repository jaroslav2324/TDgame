#include "EnemiesWay.h"

EnemiesWay::EnemiesWay(){
    //TODO find more convenient way to fill waypoints

    int numWaypoint = 0;
    dictOfWaypoints[numWaypoint] = Coords(250, 250);
    numWaypoint++;
    dictOfWaypoints[numWaypoint] = Coords(1050, 250);
    numWaypoint++;
    dictOfWaypoints[numWaypoint] = Coords(1050, 550);
    numWaypoint++;
    dictOfWaypoints[numWaypoint] = Coords(250, 550);
    numWaypoint++;
    dictOfWaypoints[numWaypoint] = Coords(250, 750);
    numWaypoint++;
    // dictOfWaypoints[numWaypoint] = Coords(500, 400);
    // numWaypoint++;
    // dictOfWaypoints[numWaypoint] = Coords(700, 500);
    // numWaypoint++;
    // dictOfWaypoints[numWaypoint] = Coords(600, 500);
    // numWaypoint++;
    // dictOfWaypoints[numWaypoint] = Coords(600, 600);
    // numWaypoint++;
    dictOfWaypoints[numWaypoint] = Coords(1050, 750);
    numWaypoint++;

    amountWaypoints = numWaypoint;
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

void EnemiesWay::render(SDL_Renderer* renderer){
    
    SDL_SetRenderDrawColor(renderer, 0, 255, 255, 255);

    int lineWidth = 3;
    int x1, y1, x2, y2;

    // TODO change rendereing algorythm
    for (int i = 0; i < amountWaypoints - 1; i++){
        x1 = dictOfWaypoints[i].x;
        y1 = dictOfWaypoints[i].y;
        x2 = dictOfWaypoints[i + 1].x;
        y2 = dictOfWaypoints[i + 1].y;

        for (int j = 0; j < lineWidth; j++, x1++, x2++, y1++, y2++)
            SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
    }
        
}
