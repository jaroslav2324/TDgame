#pragma once

#include "../abstractClasses/Projectile.h"

class BasicProjectile: public Projectile{
    public:

    BasicProjectile(Enemy* aimedEnemy, Coords spawnCoords): Projectile(aimedEnemy, spawnCoords){
        damage = 1;
        speed = 220;

        this->projectileTextureType = TexturesEnumeration::BASIC_PROJECTILE_TEXTURE;
    }

    private:
};