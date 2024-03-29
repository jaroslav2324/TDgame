
#pragma once

#include <cmath>

#include "Tower.h"

class SplashwaveTower: public Tower{
public:
    SplashwaveTower(EnemyManager* enemyManager, Coords coords);
    SplashwaveTower(EnemyManager* enemyManager, double damage, double radius, double attackSpeed, int level, Coords coords);
    ~SplashwaveTower();

    void findAllEnemiesInRadius();

    void attack();

    void renderSplashWave(Renderer* renderer);

protected:

    list<Enemy*> listOfAimedEnemies; 

    SDL_Color frontWaveColor = {150, 150, 200, 150};
    SDL_Color endWaveColor = {120, 120, 170, 150};
};
