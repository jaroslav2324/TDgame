#pragma once

#include "../abstractClasses/Tower.h"

class BasicTower: public Tower{
    public:
    BasicTower(SDL_Renderer* renderer, EnemyManager* enemyManager): Tower(renderer, enemyManager){
        setAttackTimer();
    };
    ~BasicTower();

    private:

    void setAttackTimer();
    void deleteAttackTimer();
};