#pragma once

#include "../abstractClasses/Tower.h"
#include "../projectiles/FireballProjectile.h"

class FireTower: public Tower{
    public:
    FireTower(EnemyManager* enemyManager, Coords coords): Tower(enemyManager, coords){
        attackSpeed = 50;
        radius = 100;

        this->towerTextureType = TexturesEnumeration::FIRE_TOWER_TEXTURE;

        setAttackTimer();

    };
    FireTower(EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords): 
    Tower(enemyManager, damage, radius, attackSpeed, level, coords){
        attackSpeed =   50;
        radius = 100;

        this->towerTextureType = TexturesEnumeration::FIRE_TOWER_TEXTURE;

        setAttackTimer();

    };
    ~FireTower();

    private:

    void setAttackTimer();
    void deleteAttackTimer();
    Projectile* newProjectile();
};
