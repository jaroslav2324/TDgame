#pragma once

#include <math.h>

#include "settings.h"

bool ifPixelCoordsApprEqual(float x1, float y1, float x2, float y2){

    float diffX = abs(x1 - x2);
    float diffY = abs(y1 - y2);

    float diffBetweenPoints = sqrt(pow(diffX, 2) + pow(diffY, 2));

    if (diffBetweenPoints < EPSILON_COORDS) 
        return true;
    return false;
}

bool ifPixelCoordsApprEqual(std::pair<float, float>& first, std::pair<float, float>& second){

    float diffX = abs(first.first - second.first);
    float diffY = abs(first.second - second.second);

    float diffBetweenPoints = sqrt(pow(diffX, 2) + pow(diffY, 2));

    if (diffBetweenPoints < EPSILON_COORDS) 
        return true;
    return false;
}