#pragma once

#include "utility"

#include "../TexturesHolder.h"
#include "Enemy.h"

/*basic class for all projectiles
*/
class Projectile{
    public:
    Projectile(Enemy* aimedEnemy, Coords spawnCoords);
    //TODO add constructor setting private fields
    ~Projectile();

    bool hasDamagedEnemy();
    
    void render(TexturesHolder* texturesHolder);

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