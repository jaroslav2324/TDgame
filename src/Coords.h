#pragma once

#include <iostream>
#include <fstream>
#include <math.h>

#include "settings.h"
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
    Coords& operator()(double x, double y);

};

double distance(Coords& point1, Coords& point2);

ostream& operator<<(ostream& os, const Coords& coords);

typedef Coords Point;
