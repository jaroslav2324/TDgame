#include "Projectile.h"

Projectile::Projectile(SDL_Renderer* renderer, Enemy* aimedEnemy, Coords spawnCoords){
    Projectile::aimedEnemy = aimedEnemy;
    currentCoords = spawnCoords;

    loadTexture(renderer);

    movementTimer = new PeriodicTimer(1 / FPS);
}

Projectile::~Projectile(){

    if (projectileTexture != nullptr){
        SDL_DestroyTexture(projectileTexture);
        projectileTexture = nullptr;
    }

    delete movementTimer;
}

void Projectile::moveToEnemy(){

    double timePeriodOfMoving = movementTimer->getCountPeriod();

    float enemyCoordX = aimedEnemy->getCoordX();
    float enemyCoordY = aimedEnemy->getCoordY();

    //find proportion of coords change
    float diffX = enemyCoordX - currentCoords.x;
    float diffY = enemyCoordY - currentCoords.y;

    float sumDiffXY = abs(diffX) + abs(diffY);

    double proportionChangeX = diffX / sumDiffXY;
    double proportionChangeY = diffY / sumDiffXY;

    /*find coords change*/
    float changeX = speed * proportionChangeX * timePeriodOfMoving;
    float changeY = speed * proportionChangeY * timePeriodOfMoving;

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


void Projectile::loadTexture(SDL_Renderer* renderer){

    if (projectileTexture == nullptr)
        projectileTexture = IMG_LoadTexture(renderer, TEST_SPRITE_PATH);
    else{
        SDL_DestroyTexture(projectileTexture);
        projectileTexture = IMG_LoadTexture(renderer, TEST_SPRITE_PATH);
    }   
}

void Projectile::render(SDL_Renderer* renderer){

    int x = currentCoords.x - PROJECTILE_SPRITE_SIZE / 2;
    int y = currentCoords.y - PROJECTILE_SPRITE_SIZE / 2;
    SDL_Rect projectileRect = {x, y, PROJECTILE_SPRITE_SIZE, PROJECTILE_SPRITE_SIZE};
    SDL_RenderCopy(renderer, projectileTexture, 0, &projectileRect);
}