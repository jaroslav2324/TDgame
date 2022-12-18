#pragma once

#include "../abstractClasses/Tower.h"

class IceTower: public Tower{
    public:
    IceTower(TexturesEnumeration towerTextureNum, EnemyManager* enemyManager, Coords coords): Tower(enemyManager, coords){
        attackSpeed = 1500;
        radius = 350;

        this->towerTextureNum = towerTextureNum;

        setAttackTimer();

    };
    IceTower(TexturesEnumeration towerTextureNum, EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords): 
    Tower(enemyManager, damage, radius, attackSpeed, level, coords){
        attackSpeed = 1500;
        radius = 350;

        this->towerTextureNum = towerTextureNum;
        
        setAttackTimer();

    };
    ~IceTower();

    private:

    void setAttackTimer();
    void deleteAttackTimer();
    Projectile* newProjectile(SDL_Renderer* renderer);
};
