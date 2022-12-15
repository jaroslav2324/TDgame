#pragma once

#include "../abstractClasses/Projectile.h"

class BasicProjectile: public Projectile{
    public:

    BasicProjectile(SDL_Renderer* renderer, Enemy* aimedEnemy, Coords spawnCoords): Projectile(renderer, aimedEnemy, spawnCoords){
        loadTexture(renderer);
        damage = 1;
        speed = 220;
    }

    private:
    void loadTexture(SDL_Renderer* renderer);
};