#pragma once

#include "utility"

#include "Enemy.h"

/*basic class for all projectiles
*/
class Projectile{
    public:
    Projectile(SDL_Renderer* renderer, Enemy* aimedEnemy, Coords spawnCoords);
    //TODO add constructor setting private fields
    ~Projectile();

    bool hasDamagedEnemy();
    
    virtual void loadTexture(SDL_Renderer* renderer) = 0;
    void render(SDL_Renderer* renderer);

    void attack();

    protected:

    double speed = 0;
    double damage = 0;
    bool isFreezing = false;

    bool damagedEnemy = false;

    double freezeMultiplyer = 0;
    double freezeTime = 0;

    Enemy* aimedEnemy;
    PeriodicTimer* movementTimer;

    Coords currentCoords;

    SDL_Texture* projectileTexture = nullptr;
    
    void moveToEnemy();
    void hitAndFreezeEnemy();

    bool isReachedEnemy();
};