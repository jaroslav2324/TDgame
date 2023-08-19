#include "Coords.h"

double distance(Coords& point1, Coords& point2){
    
    double deltaX = point2.x - point1.x;
    double deltaY = point2.y - point1.y;

    return sqrt(pow(deltaX, 2) + pow(deltaY, 2));
}


ostream& operator<<(ostream& os, const Coords& coords){
    os << "Coords: " << coords.x << " " << coords.y << std::endl;
    return os;
}

ostream& operator<<(ostream& os, const SDL_Rect& rect){
    os << "Rect: { " << rect.x << ", " << rect.y << ", " << rect.w << ", " << rect.h << "}" << std::endl;
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

Coords Coords::operator+(Coords& coords){
    
    Coords outCoords;

    outCoords.x = x + coords.x;
    outCoords.y = y + coords.y;

    return outCoords;
}

Coords Coords::operator+(Vector& vec){
    
    Coords outCoords;

    outCoords.x = x + vec.a;
    outCoords.y = y + vec.b;

    return outCoords;
}

Coords& Coords::operator()(double x, double y){
    
    this->x = x;
    this->y = y;
    return *this;
}

bool isPointInRect(Point& point, SDL_Rect& rect){
    if (point.x >= rect.x && point.x <= rect.x + rect.w &&
        point.y >= rect.y && point.y <= rect.y + rect.h)
        return true;
    return false;
}

