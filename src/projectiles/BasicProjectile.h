#pragma once

#include "../abstractClasses/Projectile.h"

class BasicProjectile: public Projectile{
    public:

    BasicProjectile(TexturesEnumeration projectileTextureType, Enemy* aimedEnemy, Coords spawnCoords): Projectile(aimedEnemy, spawnCoords){
        damage = 1;
        speed = 220;

        this->projectileTextureType = projectileTextureType;
    }

    private:
};