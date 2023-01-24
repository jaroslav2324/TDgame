#pragma once

#include <unordered_map>
#include <fstream>
#include <iostream>

#include "SDL2/SDL.h"

#include "../../maths/maths.h"
#include "../../engine/Engine.h"

using std::unordered_map;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;
/*
class-conatiner of waypoint coords
portal is always the first waypoint
base is always the last waypoint
*/
class EnemiesWay{
    public:
    EnemiesWay();
    Coords getNextWaypointCoords(int numCurrentWaypoint);
    Coords getFirstCoords();
    Coords getLastCoords();
    Coords getWaypointCoords(int numWaypoint);

    int getAmountWaypoints();

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    void render(Renderer* renderer, int lineWidth = 3, SDL_Color color = {0, 255, 255, 255});

    private:
    int amountWaypoints = -1;

    unordered_map<int, Coords> dictOfWaypoints;
};

// Test ways for enemies

// way with form of mirrored letter S
unordered_map<int, Coords> getWayInvS();
// way with form of letter S
unordered_map<int, Coords> getWayS();
// way with form of letter Z
unordered_map<int, Coords> getWayZ();
