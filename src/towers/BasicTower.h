#pragma once

#include "../abstractClasses/Tower.h"

class BasicTower: public Tower{
    public:
    BasicTower(SDL_Renderer* renderer, EnemyManager* enemyManager, Coords coords): Tower(renderer, enemyManager, coords){
        attackSpeed = 750;
        setAttackTimer();

        radius = 200;
    };
    BasicTower(SDL_Renderer* renderer, EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords): 
    Tower(renderer, enemyManager, damage, radius, attackSpeed, level, coords){
        setAttackTimer();
    };
    ~BasicTower();

    private:

    void setAttackTimer();
    void deleteAttackTimer();
};