#pragma once

#include <iostream>
#include <fstream>

struct Coords{
    Coords(): x(0), y(0){};
    Coords(float x, float y): x(x), y(y){};
    float x;
    float y;

};

std::ostream& operator<<(std::ostream& os, const Coords& coords);
//ostream& operator<<(ostream& os, Coords coords);

