#pragma once

#include "../abstractClasses/ProjectileTower.h"
#include "../projectiles/FireballProjectile.h"

class FireTower: public ProjectileTower{
    public:
    FireTower(EnemyManager* enemyManager, Coords coords): ProjectileTower(enemyManager, coords){
        attackSpeed = 50;
        radius = 100;

        this->towerTextureType = TexturesEnumeration::FIRE_TOWER_TEXTURE;

        //setAttackTimer();

    };
    FireTower(EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords): 
    ProjectileTower(enemyManager, damage, radius, attackSpeed, level, coords){
        attackSpeed =   50;
        radius = 100;

        this->towerTextureType = TexturesEnumeration::FIRE_TOWER_TEXTURE;

        //setAttackTimer();

    };
    ~FireTower();

    private:

    void setAttackTimer();
    void deleteAttackTimer();
    Projectile* newProjectile();
};
