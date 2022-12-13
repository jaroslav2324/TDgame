#pragma once

#include "../abstractClasses/Projectile.h"

class BasicProjectile: public Projectile{
    public:
    //TODO set sprite
    //TODO render

    BasicProjectile(SDL_Renderer* renderer, Enemy* aimedEnemy, Coords spawnCoords): Projectile(renderer, aimedEnemy, spawnCoords){
        damage = 1;
        speed = 220;
    }
};