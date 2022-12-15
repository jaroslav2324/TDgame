#include "Wave.h"

Wave getBasicTestWave(){
    Wave wave;
    int waveLen = 5;

    for (int i = 0; i < waveLen; i ++)
        wave.listEnemiesTypes.push_back(BASIC_ENEMY);

    wave.spawnPeriod = 2000;

    return wave;
}
