#pragma once

#include "../abstractClasses/SplashwaveTower.h"
#include "../projectiles/IceballProjectile.h"

class IceTower: public SplashwaveTower{
    public:
    IceTower(EnemyManager* enemyManager, Coords coords): SplashwaveTower(enemyManager, coords){
        attackSpeed = 750;
        radius = 350;
        damage = 0.2;

        this->towerTextureType = TexturesEnumeration::ICE_TOWER_TEXTURE;

        //setAttackTimer();

    };
    IceTower(EnemyManager* enemyManager, double damage, double radius, double attackSpeed, int level, Coords coords): 
    SplashwaveTower(enemyManager, damage, radius, attackSpeed, level, coords){
        attackSpeed = 750;
        radius = 350;
        damage = 0.2;

        this->towerTextureType = TexturesEnumeration::ICE_TOWER_TEXTURE;
        
        //setAttackTimer();

    };
    ~IceTower();

    private:

};
