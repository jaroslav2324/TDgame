#pragma once

#include "../abstractClasses/LaserTower.h"
//#include "../projectiles/FireballProjectile.h"

class FireTower: public LaserTower{
    public:
    FireTower(EnemyManager* enemyManager, Coords coords): LaserTower(enemyManager, coords){
        radius = 200;
        damage = 1;
        attackSpeed = 100;

        this->towerTextureType = TexturesEnumeration::FIRE_TOWER_TEXTURE;

        laserColor = {255, 0, 0, 255};

        //setAttackTimer();

    };
    FireTower(EnemyManager* enemyManager, double damage, double radius, double attackSpeed, int level, Coords coords): 
    LaserTower(enemyManager, damage, radius, attackSpeed, level, coords){
        radius = 200;
        damage = 1;
        attackSpeed = 100;

        this->towerTextureType = TexturesEnumeration::FIRE_TOWER_TEXTURE;

        laserColor = {255, 0, 0, 255};
        //setAttackTimer();

    };
    ~FireTower();

    private:

};
