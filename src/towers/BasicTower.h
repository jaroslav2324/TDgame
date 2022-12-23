#pragma once

#include "../abstractClasses/Tower.h"

class BasicTower: public Tower{
    public:
    BasicTower(EnemyManager* enemyManager, Coords coords): Tower(enemyManager, coords){
        attackSpeed = 750;
        radius = 200;

        this->towerTextureType = TexturesEnumeration::BASIC_TOWER_TEXTURE;

        //setAttackTimer();

    };
    BasicTower(EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords): 
    Tower(enemyManager, damage, radius, attackSpeed, level, coords){
        attackSpeed = 750;
        radius = 200;

        this->towerTextureType = TexturesEnumeration::BASIC_TOWER_TEXTURE;

        //setAttackTimer();

    };
    ~BasicTower();

    private:
    
    void setAttackTimer();
    void deleteAttackTimer();
    Projectile* newProjectile();
};
