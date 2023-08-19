#pragma once

// this header file contains infiormation about Coords struct, functions for manipulating with rects, coords, points

#include <iostream>
#include <fstream>
#include <math.h>

#include "SDL2/SDL.h"

#include "../settings.h"
#include "Vector.h"

using std::istream;
using std::ostream;
using std::cout;
using std::endl;

struct Coords{
    Coords(): x(0), y(0){};
    Coords(double x, double y): x(x), y(y){};
    double x;
    double y;

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    Coords operator+(Coords& coords);
    Coords operator+(Vector& vec);
    // for initialisation
    Coords& operator()(double x, double y);

};
// print coords
ostream& operator<<(ostream& os, const Coords& coords);
// print rect
ostream& operator<<(ostream& os, const SDL_Rect& rect);


typedef Coords Point;

// calculate distance between two points
double distance(Point& point1, Point& point2);
// check is point lies inside rect
bool isPointInRect(Point& point, SDL_Rect& rect);
