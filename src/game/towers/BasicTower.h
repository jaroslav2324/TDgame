#pragma once

#include "../abstractClasses/ProjectileTower.h"

class BasicTower: public ProjectileTower{
    public:
    //TODO add default arguments and merge constructors
    BasicTower(EnemyManager* enemyManager, Coords coords): ProjectileTower(enemyManager, coords){
        attackSpeed = 750;
        radius = 200;

        this->towerTextureType = TexturesEnumeration::BASIC_TOWER_TEXTURE;

        //setAttackTimer();

    };
    BasicTower(EnemyManager* enemyManager, double damage, double radius, double attackSpeed, int level, Coords coords): 
    ProjectileTower(enemyManager, damage, radius, attackSpeed, level, coords){
        attackSpeed = 750;
        radius = 200;

        this->towerTextureType = TexturesEnumeration::BASIC_TOWER_TEXTURE;

        //setAttackTimer();

    };
    ~BasicTower();

    private:
    
    Projectile* newProjectile();
};
