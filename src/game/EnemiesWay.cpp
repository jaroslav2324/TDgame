#include "EnemiesWay.h"

EnemiesWay::EnemiesWay(){

    // change way if needed
    dictOfWaypoints = getWayInvS();
    amountWaypoints = dictOfWaypoints.size();
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

void EnemiesWay::render(Renderer* renderer, int lineWidth, SDL_Color color){
    
    int x1, y1, x2, y2;
    Coords point1, point2;

    // TODO change rendering algorythm(check on diagonal lines)
    for (int i = 0; i < amountWaypoints - 1; i++){

        x1 = dictOfWaypoints[i].x - lineWidth / 2;
        y1 = dictOfWaypoints[i].y - lineWidth / 2;
        
        x2 = dictOfWaypoints[i + 1].x - lineWidth / 2;
        y2 = dictOfWaypoints[i + 1].y - lineWidth / 2;

        if (x1 != x2){

            for (int j = 0; j < lineWidth; j++, y1++, y2++)                
                renderer->renderLine(point1(x1, y1), point2(x2, y2), color);
        }
        else{

            for (int j = 0; j < lineWidth; j++, x1++, x2++)
                renderer->renderLine(point1(x1, y1), point2(x2, y2), color);
            
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

// Test ways for enemies

// way with form of mirrored letter S
unordered_map<int, Coords> getWayInvS(){

    unordered_map<int, Coords> mapOfWaypoints;

    int numWaypoint = 0;
    mapOfWaypoints[numWaypoint] = Coords(250, 250);
    numWaypoint++;
    mapOfWaypoints[numWaypoint] = Coords(1050, 250);
    numWaypoint++;
    mapOfWaypoints[numWaypoint] = Coords(1050, 550);
    numWaypoint++;
    mapOfWaypoints[numWaypoint] = Coords(250, 550);
    numWaypoint++;
    mapOfWaypoints[numWaypoint] = Coords(250, 750);
    numWaypoint++;
    mapOfWaypoints[numWaypoint] = Coords(1050, 750);

    return mapOfWaypoints;
}
// way with form of letter S
unordered_map<int, Coords> getWayS(){

    unordered_map<int, Coords> mapOfWaypoints;

    int numWaypoint = 0;
    mapOfWaypoints[numWaypoint] = Coords(1050, 250);
    numWaypoint++;
    mapOfWaypoints[numWaypoint] = Coords(250, 250);
    numWaypoint++;
    mapOfWaypoints[numWaypoint] = Coords(250, 550);
    numWaypoint++;
    mapOfWaypoints[numWaypoint] = Coords(1050, 550);
    numWaypoint++;
    mapOfWaypoints[numWaypoint] = Coords(1050, 750);
    numWaypoint++;
    mapOfWaypoints[numWaypoint] = Coords(250, 750);

    return mapOfWaypoints;
}
// way with form of letter Z
unordered_map<int, Coords> getWayZ(){

    unordered_map<int, Coords> mapOfWaypoints;

    int numWaypoint = 0;
    mapOfWaypoints[numWaypoint] = Coords(250, 250);
    numWaypoint++;
    mapOfWaypoints[numWaypoint] = Coords(1050, 250);
    numWaypoint++;
    mapOfWaypoints[numWaypoint] = Coords(250, 750);
    numWaypoint++;
    mapOfWaypoints[numWaypoint] = Coords(1050, 750);

    return mapOfWaypoints;
}

