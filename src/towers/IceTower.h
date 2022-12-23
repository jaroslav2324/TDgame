#pragma once

#include "../abstractClasses/Tower.h"
#include "../projectiles/IceballProjectile.h"

class IceTower: public Tower{
    public:
    IceTower(EnemyManager* enemyManager, Coords coords): Tower(enemyManager, coords){
        attackSpeed = 1500;
        radius = 350;

        this->towerTextureType = TexturesEnumeration::ICE_TOWER_TEXTURE;

        setAttackTimer();

    };
    IceTower(EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords): 
    Tower(enemyManager, damage, radius, attackSpeed, level, coords){
        attackSpeed = 1500;
        radius = 350;

        this->towerTextureType = TexturesEnumeration::ICE_TOWER_TEXTURE;
        
        setAttackTimer();

    };
    ~IceTower();

    private:

    void setAttackTimer();
    void deleteAttackTimer();
    Projectile* newProjectile();
};
