#pragma once

#include "../abstractClasses/ProjectileTower.h"

namespace basic_tower_standart_properties{
    const double BASIC_TOWER_RADIUS = 200;
    const double BASIC_TOWER_DAMAGE = 2;
    const double BASIC_TOWER_ATTACK_SPEED = 750;
}

class BasicTower: public ProjectileTower{
    public:

    BasicTower(EnemyManager* enemyManager,
    Coords coords,
    int level = 0,
    double damage = basic_tower_standart_properties::BASIC_TOWER_DAMAGE,
    double radius = basic_tower_standart_properties::BASIC_TOWER_RADIUS,
    double attackSpeed = basic_tower_standart_properties::BASIC_TOWER_ATTACK_SPEED): ProjectileTower(enemyManager, damage, radius, attackSpeed, level, coords)
    {
        this->towerTextureType = TexturesEnumeration::BASIC_TOWER_TEXTURE;
    };
    ~BasicTower();

    private:
    
    Projectile* newProjectile();
};
