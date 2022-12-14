#pragma once

#include <iostream>
#include <list>

#include "EnemyTypes.h"

using std::list;
using std::cout;
using std::endl;

struct Wave{

    list<EnemyTypes> listEnemiesTypes;
    double spawnPeriod;
};


Wave getBasicTestWave();

