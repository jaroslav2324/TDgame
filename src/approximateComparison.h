#pragma once

#include <math.h>

#include "settings.h"

bool ifPixelCoordsApprEqual(float x1, float y1, float x2, float y2);
bool ifPixelCoordsApprEqual(std::pair<float, float>& first, std::pair<float, float>& second);
