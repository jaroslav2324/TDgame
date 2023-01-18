#include "approximateComparison.h"

bool ifCoordsApprEqual(float x1, float y1, float x2, float y2){

    float diffX = abs(x1 - x2);
    float diffY = abs(y1 - y2);

    float diffBetweenPoints = sqrt(pow(diffX, 2) + pow(diffY, 2));

    if (diffBetweenPoints < EPSILON_COORDS) 
        return true;
    return false;
}

bool ifCoordsApprEqual(double x1, double y1, double x2, double y2){

    double diffX = abs(x1 - x2);
    double diffY = abs(y1 - y2);

    double diffBetweenPoints = sqrt(pow(diffX, 2) + pow(diffY, 2));

    if (diffBetweenPoints < EPSILON_COORDS) 
        return true;
    return false;
}

bool ifCoordsApprEqual(Coords first, Coords second){

    double diffX = abs(first.x - second.x);
    double diffY = abs(first.y - second.y);

    double diffBetweenPoints = sqrt(pow(diffX, 2) + pow(diffY, 2));

    if (diffBetweenPoints < EPSILON_COORDS) 
        return true;
    return false;
}