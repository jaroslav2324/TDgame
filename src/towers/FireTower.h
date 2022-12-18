#pragma once

#include "../abstractClasses/Tower.h"

class FireTower: public Tower{
    public:
    FireTower(TexturesEnumeration towerTextureNum, EnemyManager* enemyManager, Coords coords): Tower(enemyManager, coords){
        attackSpeed = 50;
        radius = 100;

        this->towerTextureNum = towerTextureNum;

        setAttackTimer();

    };
    FireTower(TexturesEnumeration towerTextureNum, EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords): 
    Tower(enemyManager, damage, radius, attackSpeed, level, coords){
        attackSpeed =   50;
        radius = 100;

        this->towerTextureNum = towerTextureNum;

        setAttackTimer();

    };
    ~FireTower();

    private:

    void setAttackTimer();
    void deleteAttackTimer();
    Projectile* newProjectile(SDL_Renderer* renderer);
};
