#pragma once

#include "../abstractClasses/SplashwaveTower.h"

namespace ice_tower_standart_properties{
    const double ICE_TOWER_RADIUS = 350;
    const double ICE_TOWER_DAMAGE = 0.2;
    const double ICE_TOWER_ATTACK_SPEED = 750;
}

class IceTower: public SplashwaveTower{
    public:

    IceTower(EnemyManager* enemyManager,
    Coords coords,
    int level = 0,
    double damage = ice_tower_standart_properties::ICE_TOWER_DAMAGE,
    double radius = ice_tower_standart_properties::ICE_TOWER_RADIUS,
    double attackSpeed = ice_tower_standart_properties::ICE_TOWER_ATTACK_SPEED): SplashwaveTower(enemyManager, damage, radius, attackSpeed, level, coords)
    {
        this->towerTextureType = TexturesEnumeration::ICE_TOWER_TEXTURE;
    };
    ~IceTower();

    private:

};
