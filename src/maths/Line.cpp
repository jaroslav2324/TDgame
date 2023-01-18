#include "Line.h"

void Line::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving coordinates stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    
    // save x and y
    outpustStream.write((char*)&p1, sizeof(p1));
    outpustStream.write((char*)&p2, sizeof(p2));
}

void Line::loadFromBinaryFile(istream& inputStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !LOADING_LEVELS_ON)
        cout << "Loading levels is turned off. Loading coordinates stopped." << endl;

    if (!LOADING_LEVELS_ON)
        return;

    // load save x and y
    inputStream.read((char*)&p1, sizeof(p1));
    inputStream.read((char*)&p2, sizeof(p2));
}

double Line::findX(double y){

    if (guidingVector.b != 0)
        return p1.x + (guidingVector.a / guidingVector.b) * (y - p1.y);
    else
        return 0;
}

double Line::findY(double x){
    
    if (guidingVector.a != 0)
        return p1.y + (guidingVector.b / guidingVector.a) * (x - p1.x);
    else
        return 0;
}

Line& Line::operator()(Point& p1, Point& p2){
    
    this->p1 = p1;
    this->p2 = p2;
    return *this;
}

Line getPerpendicularLine(Line& line){

    Line perpendicularLine;

    perpendicularLine.p1 = line.p1;
    perpendicularLine.guidingVector = getPerpendicularVector(line.guidingVector);

    perpendicularLine.p2 = line.p2 + perpendicularLine.guidingVector;

    return perpendicularLine;
}


