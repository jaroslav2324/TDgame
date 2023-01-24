#pragma once

#include <iostream>
#include <fstream>
#include <list>

#include "../settings.h"
#include "enemies/EnemyKinds.h"

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

    int size();

    //TODO  add countdown before each enemy
    list<EnemyKinds> listEnemiesTypes;
    double spawnPeriod;
    // in ms
    double countdownBeforeWave = 10000;
};


// value is period between spawning enemies

Wave getBasicWave(uint amount, double msSpawnPeriod, double countdownBeforeWave);
Wave getOrcWave(uint amount, double msSpawnPeriod, double countdownBeforeWave);
Wave getBasicOrcWave(uint amount, double msSpawnPeriod, double countdownBeforeWave);

// lists of waves for different levels
list<Wave> getListWaves1();
list<Wave> getListWaves2();
list<Wave> getListWaves3();
