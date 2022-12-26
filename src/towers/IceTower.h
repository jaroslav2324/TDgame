#pragma once

#include "../abstractClasses/ProjectileTower.h"
#include "../projectiles/IceballProjectile.h"

class IceTower: public ProjectileTower{
    public:
    IceTower(EnemyManager* enemyManager, Coords coords): ProjectileTower(enemyManager, coords){
        attackSpeed = 1500;
        radius = 350;

        this->towerTextureType = TexturesEnumeration::ICE_TOWER_TEXTURE;

        //setAttackTimer();

    };
    IceTower(EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords): 
    ProjectileTower(enemyManager, damage, radius, attackSpeed, level, coords){
        attackSpeed = 1500;
        radius = 350;

        this->towerTextureType = TexturesEnumeration::ICE_TOWER_TEXTURE;
        
        //setAttackTimer();

    };
    ~IceTower();

    private:

    void setAttackTimer();
    void deleteAttackTimer();
    Projectile* newProjectile();
};
