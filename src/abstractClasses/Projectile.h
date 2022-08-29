#pragma once

#include "utility"

#include "Tower.h"
#include "Enemy.h"

/*basic class for all projectiles
*/
class Projectile{
    public:
    Projectile(Enemy* aimedEnemy, std::pair<float, float> spawnCoords);
    //TODO add constructor setting private fields
    ~Projectile();

    bool hasDamagedEnemy();
    //TODO load sprite
    //TODO render
    void attack();

    protected:

    double speed = 0;
    double damage = 0;
    bool isFreezing = false;

    bool damagedEnemy = false;

    double freezeMultiplyer = 0;
    double freezeTime = 0;

    Enemy* aimedEnemy;
    Tower* moterTower;
    PeriodicTimer* movementTimer;

    std::pair<float, float> currentCoords;
    
    void moveToEnemy();
    void hitAndFreezeEnemy();

    bool isReachedEnemy();
};