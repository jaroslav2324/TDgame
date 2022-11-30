#pragma once

#include "../abstractClasses/Tower.h"

class BasicTower: public Tower{
    public:
    BasicTower(SDL_Renderer* renderer, EnemyManager* enemyManager, Coords coords): Tower(renderer, enemyManager, coords){
        setAttackTimer();
    };
    ~BasicTower();

    private:

    void setAttackTimer();
    void deleteAttackTimer();
};