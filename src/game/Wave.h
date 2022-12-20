#pragma once

#include <iostream>
#include <fstream>
#include <list>

#include "../settings.h"
#include "../enemies/EnemyTypes.h"

using std::list;
using std::ostream;
using std::istream;
using std::cout;
using std::endl;

struct Wave{

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    list<EnemyTypes> listEnemiesTypes;
    double spawnPeriod;
};


Wave getBasicTestWave();

