#pragma once

#include "../abstractClasses/Projectile.h"

class IceballProjectile: public Projectile{
    public:

    IceballProjectile(Enemy* aimedEnemy, Coords spawnCoords): Projectile(aimedEnemy, spawnCoords){
        damage = 1;
        speed = 220;

        this->projectileTextureType = TexturesEnumeration::ICEBALL_PROJECTILE_TEXTURE;
    }
};
