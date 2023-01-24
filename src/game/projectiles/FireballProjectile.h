#pragma once

#include "../abstractClasses/Projectile.h"

class FireballProjectile: public Projectile{
    public:

    FireballProjectile(Enemy* aimedEnemy, Coords spawnCoords): Projectile(aimedEnemy, spawnCoords){
        damage = 1;
        speed = 220;

        this->projectileTextureType = TexturesEnumeration::FIREBALL_PROJECTILE_TEXTURE;
    }
};
