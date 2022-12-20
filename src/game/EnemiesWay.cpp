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

void EnemiesWay::render(Renderer* renderer){
    
    SDL_Color color = {0, 255, 255, 255};

    int lineWidth = 3;
    int x1, y1, x2, y2;
    Coords point1, point2;

    // TODO change rendereing algorythm
    for (int i = 0; i < amountWaypoints - 1; i++){
        x1 = dictOfWaypoints[i].x;
        y1 = dictOfWaypoints[i].y;
        x2 = dictOfWaypoints[i + 1].x;
        y2 = dictOfWaypoints[i + 1].y;

        for (int j = 0; j < lineWidth; j++, x1++, x2++, y1++, y2++){
            point1.x = x1;
            point1.y = y1;
            point2.x = x2;
            point2.y = y2;
            renderer->renderLine(point1, point2, color);
        }
    }     
}

void EnemiesWay::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving enemies way stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    
    // save amount of waypoints
    outpustStream.write((char*)&amountWaypoints, sizeof(amountWaypoints));

    // save waypoints coords
    for (int i = 0; i < amountWaypoints; i++)
        dictOfWaypoints[i].saveToBinaryFile(outpustStream);
}

void EnemiesWay::loadFromBinaryFile(istream& inputStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !LOADING_LEVELS_ON)
        cout << "Loading levels is turned off. Loading enemies way stopped." << endl;

    if (!LOADING_LEVELS_ON)
        return;

    // load amount of waypoints
    inputStream.read((char*)&amountWaypoints, sizeof(amountWaypoints));

    // save waypoints coords
    for (int i = 0; i < amountWaypoints; i++)
        dictOfWaypoints[i].loadFromBinaryFile(inputStream);
}

