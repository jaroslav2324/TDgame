#pragma once

#include "fstream"
#include "iostream"

#include "settings.h"

using std::ostream;
using std::istream; 
using std::cout;
using std::endl;

struct Vector{

    Vector(): a(0), b(0){};
    Vector(double a, double b): a(a), b(b){};

    double a;
    double b;

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    Vector& operator()(double x, double y);
};

Vector getPerpendicularVector(Vector& vec);
