#include "Vector.h"

void Vector::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving coordinates stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    
    // save x and y
    outpustStream.write((char*)&a, sizeof(a));
    outpustStream.write((char*)&b, sizeof(b));
}

void Vector::loadFromBinaryFile(istream& inputStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !LOADING_LEVELS_ON)
        cout << "Loading levels is turned off. Loading coordinates stopped." << endl;

    if (!LOADING_LEVELS_ON)
        return;

    // load save x and y
    inputStream.read((char*)&b, sizeof(b));
    inputStream.read((char*)&b, sizeof(b));
}

Vector& Vector::operator()(double x, double y){
    
    this->a = x;
    this->b = y;
    return *this;
}

Vector getPerpendicularVector(Vector& vec){

    Vector perpendicularVector;
    perpendicularVector.a = vec.b;
    perpendicularVector.b = -vec.a;

    return perpendicularVector;
}
