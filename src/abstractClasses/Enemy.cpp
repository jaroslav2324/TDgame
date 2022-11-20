#pragma once

#include "Enemy.h"

Enemy::Enemy(EnemiesWay* way, Base* base){
    //TODO implement constructor;
    //TODO add timers

    Enemy::way = way;
    Enemy::base = base;
}

Enemy::~Enemy(){

    if (freezeTimer != nullptr)
        delete freezeTimer;

    if (enemyTexture != nullptr)
        SDL_DestroyTexture(enemyTexture);
}

void Enemy::replaceToNextWaypointCoords(){
    coordsCurrentWaypoint = coordsNextWaypoint;
    coordsNextWaypoint = way->getNextWaypointCoords(numCurrentWaypoint);
    numCurrentWaypoint++;
}

void Enemy::MoveToNextWaypoint(double timePeriodOfMoving ){

    //find proportion of coords change
    float diffX = coordsNextWaypoint.first - coordsCurrentWaypoint.first;
    float diffY = coordsNextWaypoint.second - coordsCurrentWaypoint.second;

    float sumDiffXY = abs(diffX) + abs(diffY);

    double proportionChangeX = diffX / sumDiffXY;
    double proportionChangeY = diffY / sumDiffXY;

    /*find coords change*/
    float changeX = currentSpeed * proportionChangeX * timePeriodOfMoving;
    float changeY = currentSpeed * proportionChangeY * timePeriodOfMoving;

    /*change coords*/
    currentCoords.first += changeX;
    currentCoords.second += changeY;
}

bool Enemy::ifWaypointPassed(){

    float diffX = coordsNextWaypoint.first - coordsCurrentWaypoint.first;
    float diffY = coordsNextWaypoint.second - coordsCurrentWaypoint.second;

    /*if diffX < 0 x coord of the next waypoint is left from current waypoint
      if diffX > 0 x coord of the next waypoint is right from current waypoint*/
    if (diffX < 0){
        /*if enemy passed by waypoint*/ 
        if (currentCoords.first < coordsNextWaypoint.first)
            currentCoords.first = coordsNextWaypoint.first;
    }
    else{
        /*if enemy passed by waypoint*/ 
        if (currentCoords.first > coordsNextWaypoint.first)
            currentCoords.first = coordsNextWaypoint.first;
    }

    /*if diffY < 0 y coord of the next waypoint is up from current waypoint
      if diffY > 0 y coord of the next waypoint is down from current waypoint*/
    if (diffX < 0){
        /*if enemy passed by waypoint*/ 
        if (currentCoords.second < coordsNextWaypoint.second)
            currentCoords.second = coordsNextWaypoint.second;
    }
    else{
        /*if enemy passed by waypoint*/ 
        if (currentCoords.second > coordsNextWaypoint.second)
            currentCoords.second = coordsNextWaypoint.second;
    }

    if (ifPixelCoordsApprEqual(currentCoords, coordsNextWaypoint))
        return true;
    return false;
    
}

/*Copy coordinates from source to destination*/
void Enemy::copyCoords(std::pair<float, float>& destination, std::pair<float, float>& source){
    destination.first = source.first;
    destination.second = source.second;
}

float Enemy::getCoordX(){
    return currentCoords.first;
}

float Enemy::getCoordY(){
    return currentCoords.second;
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

        if (ifWaypointPassed())
            replaceToNextWaypointCoords();

        if (freezeTimer != nullptr)
            if (freezeTimer->isCountdownEnd() && isFreezed)
                unfreeze();
            

        MoveToNextWaypoint(movementTimer->getCountPeriod() / 1000);

        if(isNearBase())
            damageBaseAndGetKilled();
    }
}

bool Enemy::isNearBase(){
    std::pair<float, float> baseCoords = way->getLastCoords();
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

void Enemy::loadSprite(SDL_Renderer* renderer){
    enemyTexture = IMG_LoadTexture(renderer, TEST_SPRITE_PATH);    
}

void Enemy::render(SDL_Renderer* renderer){

    //TODO move to constructor
    if(enemyTexture == nullptr)
        loadSprite(renderer);

    int x = currentCoords.first - ENEMY_SPRITE_SIZE / 2;
    int y = currentCoords.second - ENEMY_SPRITE_SIZE / 2;
    SDL_Rect enemyRect = {x, y, ENEMY_SPRITE_SIZE, ENEMY_SPRITE_SIZE};
    SDL_RenderCopy(renderer, enemyTexture, 0, &enemyRect);
}