#include "Coords.h"

ostream& operator<<(ostream& os, const Coords& coords){
    os << "Coords: " << coords.x << " " << coords.y << std::endl;
    return os;
}

void Coords::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving coordinates stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    
    // save x and y
    outpustStream.write((char*)&x, sizeof(x));
    outpustStream.write((char*)&y, sizeof(y));
}

void Coords::loadFromBinaryFile(istream& inputStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !LOADING_LEVELS_ON)
        cout << "Loading levels is turned off. Loading coordinates stopped." << endl;

    if (!LOADING_LEVELS_ON)
        return;

    // load save x and y
    inputStream.read((char*)&y, sizeof(y));
    inputStream.read((char*)&y, sizeof(y));
}

