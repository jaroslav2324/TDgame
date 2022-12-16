#include "Projectile.h"

Projectile::Projectile(SDL_Renderer* renderer, Enemy* aimedEnemy, Coords spawnCoords){
    Projectile::aimedEnemy = aimedEnemy;
    currentCoords = spawnCoords;

    movementTimer = new PeriodicTimer(1 / FPS);
}

Projectile::~Projectile(){

    if (projectileTexture != nullptr){
        SDL_DestroyTexture(projectileTexture);
        projectileTexture = nullptr;
    }

    if (movementTimer != nullptr){
        delete movementTimer;
        movementTimer = nullptr;
    }
}

void Projectile::moveToEnemy(){

    double timePeriodOfMoving = movementTimer->getCountPeriod();

    float enemyCoordX = aimedEnemy->getCoordX();
    float enemyCoordY = aimedEnemy->getCoordY();

    //find proportion of coords change
    double diffX = enemyCoordX - currentCoords.x;
    double diffY = enemyCoordY - currentCoords.y;

    char signOfDiffX = 1;
    if (diffX < 0)
        signOfDiffX = -1;

    double distanceToEnemy = sqrt(pow(diffX, 2) + pow(diffY, 2));
    double movingDistance = speed * timePeriodOfMoving;
    double scale = movingDistance / distanceToEnemy;

    // equality movingDistance^2 = changeX^2 + changeY^2
    double changeY = diffY * scale;
    double changeX;
    changeX = sqrt(pow(movingDistance, 2) - pow(changeY, 2));
    changeX *= signOfDiffX;

    /*change coords*/
    currentCoords.x += changeX;
    currentCoords.y += changeY;

    // the projectile flies to the left and passing by the enemy
    if (diffX < 0 && currentCoords.x < enemyCoordX)
        currentCoords.x = enemyCoordX;

    // the projectile flies to the right and passing by the enemy   
    if (diffX >= 0 && currentCoords.x > enemyCoordX)
        currentCoords.x = enemyCoordX;

    // the projectile up and passing by the enemy
    if (diffY < 0 && currentCoords.y < enemyCoordY)
        currentCoords.y = enemyCoordY;

    // the projectile flies down and passing by the enemy   
    if (diffY >= 0 && currentCoords.y > enemyCoordY)
        currentCoords.y = enemyCoordY;
    
}

bool Projectile::isReachedEnemy(){

    float enemyCoordX = aimedEnemy->getCoordX();
    float enemyCoordY = aimedEnemy->getCoordY();
    Coords enemyCoords(enemyCoordX, enemyCoordY);

    if (ifCoordsApprEqual(currentCoords, enemyCoords))
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

void Projectile::render(SDL_Renderer* renderer){

    int x = currentCoords.x - PROJECTILE_SPRITE_SIZE / 2;
    int y = currentCoords.y - PROJECTILE_SPRITE_SIZE / 2;
    SDL_Rect projectileRect = {x, y, PROJECTILE_SPRITE_SIZE, PROJECTILE_SPRITE_SIZE};
    SDL_RenderCopy(renderer, projectileTexture, 0, &projectileRect);
}