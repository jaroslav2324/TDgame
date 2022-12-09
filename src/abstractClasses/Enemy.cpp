#include "Enemy.h"

Enemy::Enemy(SDL_Renderer* renderer, EnemiesWay* way, Base* base, Portal* portal, Coords coords){

    //TODO add timers
    //TODO delete SDL_Renderer from constructor or move to fields of the class?

    loadTexture(renderer);

    Enemy::way = way;
    Enemy::base = base;
    Enemy::currentCoords = coords;
    Enemy::portal = portal;

    Enemy::coordsCurrentWaypoint = way->getFirstCoords();
    Enemy::coordsNextWaypoint = way->getWaypointCoords(1);

}

Enemy::~Enemy(){

    if (freezeTimer != nullptr)
        delete freezeTimer;

    if (enemyTexture != nullptr){
        SDL_DestroyTexture(enemyTexture);
        enemyTexture = nullptr;
    }
}

void Enemy::replaceToNextWaypointCoords(){
    coordsCurrentWaypoint = coordsNextWaypoint;
    coordsNextWaypoint = way->getNextWaypointCoords(numNextWaypoint);
    numNextWaypoint++;
}

void Enemy::MoveToNextWaypoint(double timePeriodOfMoving ){

    //cout << currentCoords.x << " " << currentCoords.y << endl;

    //find proportion of coords change
    float diffX = coordsNextWaypoint.x - coordsCurrentWaypoint.x;
    float diffY = coordsNextWaypoint.y - coordsCurrentWaypoint.y;

    float sumDiffXY = abs(diffX) + abs(diffY);

    double proportionChangeX = diffX / sumDiffXY;
    double proportionChangeY = diffY / sumDiffXY;

    /*find coords change*/
    float changeX = currentSpeed * proportionChangeX * timePeriodOfMoving;
    float changeY = currentSpeed * proportionChangeY * timePeriodOfMoving;

    /*change coords*/
    currentCoords.x += changeX;
    currentCoords.y += changeY;
}

bool Enemy::ifWaypointPassed(){

    float diffX = coordsNextWaypoint.x - coordsCurrentWaypoint.x;
    float diffY = coordsNextWaypoint.y - coordsCurrentWaypoint.y;

    /*if diffX < 0 x coord of the next waypoint is left from current waypoint
      if diffX > 0 x coord of the next waypoint is right from current waypoint*/
    if (diffX < 0){
        /*if enemy passed by waypoint*/ 
        if (currentCoords.x < coordsNextWaypoint.x)
            currentCoords.x = coordsNextWaypoint.x;
    }
    else{
        /*if enemy passed by waypoint*/ 
        if (currentCoords.x > coordsNextWaypoint.x)
            currentCoords.x = coordsNextWaypoint.x;
    }

    /*if diffY < 0 y coord of the next waypoint is up from current waypoint
      if diffY > 0 y coord of the next waypoint is down from current waypoint*/
    if (diffY < 0){
        /*if enemy passed by waypoint*/ 
        if (currentCoords.y < coordsNextWaypoint.y)
            currentCoords.y = coordsNextWaypoint.y;
    }
    else{
        /*if enemy passed by waypoint*/ 
        if (currentCoords.y > coordsNextWaypoint.y)
            currentCoords.y = coordsNextWaypoint.y;
    }

    if (ifPixelCoordsApprEqual(currentCoords, coordsNextWaypoint)){
        // cout << currentCoords.x << " " << currentCoords.y << " are equal ";
        // cout << coordsNextWaypoint.x << " " << coordsNextWaypoint.y << endl;
        return true;
    }
    return false;
    
}

/*Copy coordinates from source to destination*/
void Enemy::copyCoords(Coords& destination, Coords& source){
    destination.x = source.x;
    destination.y = source.y;
}

float Enemy::getCoordX(){
    return currentCoords.x;
}

float Enemy::getCoordY(){
    return currentCoords.y;
}

/*hit Enemy*/
void Enemy::applyDamage(float damage){
    hitPoints -= damage;
}

bool Enemy::isDead(){
    if (hitPoints <= 0)
        return true;
    return false;
}

/*
Slow down Enemy
freezeMultiplyer between 0 and 1
*/
void Enemy::freeze(float freezeMultiplyer, double time){
    isFreezed = true;
    currentSpeed = maxSpeed * (1 - freezeMultiplyer);
    activateFreezeTimer(time);
}

void Enemy::unfreeze(){
    isFreezed = false;
    currentSpeed = maxSpeed;
}

void Enemy::damageBaseAndGetKilled(){
    base->applyDamage(damageToBase);
    hitPoints = 0;
}

void Enemy::move(){

    if (movementTimer->tickIfNeeded()){

        // cout << currentCoords.x << " " << currentCoords.y << endl;
        // cout << coordsNextWaypoint.x << " " << coordsNextWaypoint.y << endl;

        if (ifWaypointPassed())
            replaceToNextWaypointCoords();

        if (freezeTimer != nullptr)
            if (freezeTimer->isCountdownEnd() && isFreezed)
                unfreeze();
            

        MoveToNextWaypoint(movementTimer->getCountPeriod());

        if(isNearBase())
            damageBaseAndGetKilled();
    }
}

bool Enemy::isNearBase(){
    Coords baseCoords = way->getLastCoords();
    if (ifPixelCoordsApprEqual(currentCoords, baseCoords))
        return true;
    return false;
}

void Enemy::activateFreezeTimer(double freezeTime){

    if (freezeTimer == nullptr)
        freezeTimer = new CountdownTimer(freezeTime);
    else
        freezeTimer->replaceToMoreTime(freezeTime);
}

void Enemy::loadTexture(SDL_Renderer* renderer){

    if (enemyTexture == nullptr)
        enemyTexture = IMG_LoadTexture(renderer, BASIC_ENEMY_SPRITE_PATH);    
    else {
        SDL_DestroyTexture(enemyTexture);
        enemyTexture = IMG_LoadTexture(renderer, BASIC_ENEMY_SPRITE_PATH);    
    }
}

void Enemy::render(SDL_Renderer* renderer){

    int x = currentCoords.x - ENEMY_SPRITE_SIZE / 2;
    int y = currentCoords.y - ENEMY_SPRITE_SIZE / 2;
    SDL_Rect enemyRect = {x, y, ENEMY_SPRITE_SIZE, ENEMY_SPRITE_SIZE};
    SDL_RenderCopy(renderer, enemyTexture, 0, &enemyRect);
}