#pragma once

#include "../abstractClasses/LaserTower.h"


namespace fire_tower_standart_properties{
    const double FIRE_TOWER_RADIUS = 200;
    const double FIRE_TOWER_DPS = 1;
    const double FIRE_TOWER_ATTACK_SPEED = 100;
    const SDL_Color FIRE_TOWER_LASER_COLOR = {255, 255, 0, 255};
}

class FireTower: public LaserTower{
    public:

    FireTower(EnemyManager* enemyManager,
    Coords coords,
    int level = 0,
    double damage = fire_tower_standart_properties::FIRE_TOWER_DPS,
    double radius = fire_tower_standart_properties::FIRE_TOWER_RADIUS,
    double attackSpeed = fire_tower_standart_properties::FIRE_TOWER_ATTACK_SPEED) : LaserTower(enemyManager, damage, radius, attackSpeed, level, coords)
    {
        towerTextureType = TexturesEnumeration::FIRE_TOWER_TEXTURE;
        laserColor = fire_tower_standart_properties::FIRE_TOWER_LASER_COLOR;
    }

    ~FireTower();

    private:

};
