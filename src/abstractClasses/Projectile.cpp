#pragma once

#include "utility"

#include "Tower.cpp"
#include "Enemy.cpp"

/*basic class for all projectiles
*/
class Projectile{
    public:
    Projectile(Tower* motherTower, Enemy* aimedEnemy, std::pair<float, float> spawnCoords);
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

Projectile::Projectile(Tower* motherTower, Enemy* aimedEnemy, std::pair<float, float> spawnCoords){
    Projectile::aimedEnemy = aimedEnemy;
    currentCoords = spawnCoords;

    movementTimer = new PeriodicTimer(1 / FPS);
}

Projectile::~Projectile(){
    delete movementTimer;
}

void Projectile::moveToEnemy(){

    double timePeriodOfMoving = movementTimer->getCountPeriod();

    float enemyCoordX = aimedEnemy->getCoordX();
    float enemyCoordY = aimedEnemy->getCoordY();

    //find proportion of coords change
    float diffX = enemyCoordX - currentCoords.first;
    float diffY = enemyCoordY - currentCoords.second;

    float sumDiffXY = abs(diffX) + abs(diffY);

    double proportionChangeX = diffX / sumDiffXY;
    double proportionChangeY = diffY / sumDiffXY;

    /*find coords change*/
    float changeX = speed * proportionChangeX * timePeriodOfMoving;
    float changeY = speed * proportionChangeY * timePeriodOfMoving;

    /*change coords*/
    currentCoords.first += changeX;
    currentCoords.second += changeY;


    //FIXME projectile won`t hit enemy because of diffX and diffY, it will go back and fourth

    /*if diffX < 0 x coord of the projectile is right from the enemy
      if diffX > 0 x coord of the projectile is left from the enemy*/
    if (diffX < 0){
        /*if enemy passed by waypoint*/ 
        if (currentCoords.first < enemyCoordX)
            currentCoords.first = enemyCoordX;
    }
    else{
        /*if enemy passed by waypoint*/ 
        if (currentCoords.first > enemyCoordX)
            currentCoords.first = enemyCoordX;
    }

    /*if diffY < 0 y coord of the projectile is down from the enemy
      if diffY > 0 y coord of the projectile is up from the enemy*/
    if (diffX < 0){
        /*if enemy passed by waypoint*/ 
        if (currentCoords.second < enemyCoordY)
            currentCoords.second = enemyCoordY;
    }
    else{
        /*if enemy passed by waypoint*/ 
        if (currentCoords.second > enemyCoordY)
            currentCoords.second = enemyCoordY;
    }
}

bool Projectile::isReachedEnemy(){

    float enemyCoordX = aimedEnemy->getCoordX();
    float enemyCoordY = aimedEnemy->getCoordY();
    std::pair<float, float> enemyCoords(enemyCoordX, enemyCoordY);

    if (ifPixelCoordsApprEqual(currentCoords, enemyCoords))
        return true;
    return false;
}

void Projectile::hitAndFreezeEnemy(){
    aimedEnemy->applyDamage(damage);
    damagedEnemy = true;
    if (isFreezing)
        aimedEnemy->freeze(freezeMultiplyer, freezeTime);
}

void Projectile::attack(){

    moveToEnemy();
    if (isReachedEnemy())
        hitAndFreezeEnemy();
}

bool Projectile::hasDamagedEnemy(){
    if (damagedEnemy)
        return true;
    return false;
}
