#pragma once

#include "utility"

#include "../../engine/Engine.h"
#include "Enemy.h"

/*basic class for all projectiles
*/
class Projectile{
    public:
    Projectile(Enemy* aimedEnemy, Coords spawnCoords);
    ~Projectile();

    bool hasDamagedEnemy();
    
    void render(Renderer* renderer);

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

    TexturesEnumeration projectileTextureType;
    
    void moveToEnemy();
    void hitAndFreezeEnemy();

    bool isReachedEnemy();
};