#pragma once

#include <math.h>

#include "../settings.h"
#include "Coords.h"

bool ifCoordsApprEqual(float x1, float y1, float x2, float y2);
bool ifCoordsApprEqual(double x1, double y1, double x2, double y2);
bool ifCoordsApprEqual(Coords first, Coords second);
