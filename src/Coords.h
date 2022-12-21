#pragma once

#include <iostream>
#include <fstream>

#include "settings.h"

using std::istream;
using std::ostream;
using std::cout;
using std::endl;

struct Coords{
    Coords(): x(0), y(0){};
    Coords(float x, float y): x(x), y(y){};
    float x;
    float y;

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    Coords& operator()(float x, float y);
};

ostream& operator<<(ostream& os, const Coords& coords);
