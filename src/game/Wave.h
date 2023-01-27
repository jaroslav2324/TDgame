#pragma once

#include <iostream>
#include <fstream>
#include <list>
#include <vector>

#include "../settings.h"
#include "enemies/EnemyKinds.h"

using std::vector;
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

    list<int> listCountdownBeforeEnemies;
    list<EnemyKinds> listEnemiesTypes;
    // in ms
    double countdownBeforeWave = 10000;
};



// for wave with const period between enemy spawn
Wave getBasicWave(uint amount, double countdownBeforeWave, int countdownBeforeEachEnemy);
// for wave with const period between enemy spawn
Wave getOrcWave(uint amount, double countdownBeforeWave, int countdownBeforeEachEnemy);
// for wave with const period between enemy spawn
Wave getBasicOrcWave(uint amount, double countdownBeforeWave, int countdownBeforeEachEnemy);

//TODO add check lendth of vector and amount
// for custom wave
Wave getBasicWave(uint amount, double countdownBeforeWave, vector<int> vectorCountdownsBeforeEachEnemy);
// for custom wave
Wave getOrcWave(uint amount, double countdownBeforeWave, vector<int> vectorCountdownsBeforeEachEnemy);
// for custom wave
Wave getBasicOrcWave(uint amount, double countdownBeforeWave, vector<int> vectorCountdownsBeforeEachEnemy);

// lists of waves for different levels
list<Wave> getListWaves1();
list<Wave> getListWaves2();
list<Wave> getListWaves3();
