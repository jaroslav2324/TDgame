#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "./EnemiesWay.cpp"
#include "./Base.cpp"
#include "./approximateComparison.cpp"

using std::string;


/*Basic class for all enemies*/
class Enemy{
public:
    Enemy(string& enemySpritePath);
    
    void MoveToNextWaypoint();

    bool ifWaypointPassed(EnemiesWay&);
    void replaceToNextWaypointCoords(EnemiesWay& way);

    void applyDamage(float damage);
    bool isDead();

    void freeze(float freezeMultiplyer);
    void unfreeze();

    //TODO check position near base
    void damageBaseAndGetKilled(Base& base);
    //TODO time of freezing
    //TODO load sprite

    float getCoordX();
    float getCoordY();

protected:
    float hitPoints = 0;
    float maxHitPoints = 0;
    float currentSpeed = 0;
    float maxSpeed = 0;

    int damageToBase = 0;

    int numCurrentWaypoint = 0;
    std::pair<float, float> currentCoords;
    std::pair<float, float> coordsCurrentWaypoint;
    std::pair<float, float> coordsNextWaypoint;

    void copyCoords(std::pair<float, float>& destination, std::pair<float, float>& source);
    
    SDL_Texture* enemySprite = nullptr;
};

void Enemy::replaceToNextWaypointCoords(EnemiesWay& way){
    coordsCurrentWaypoint = coordsNextWaypoint;
    coordsNextWaypoint = way.getNextWaypointCoords(numCurrentWaypoint);
    numCurrentWaypoint++;
}

void Enemy::MoveToNextWaypoint(){
    //TODO add timer
    //find proportion of coords change
    float diffX = coordsNextWaypoint.first - coordsCurrentWaypoint.first;
    float diffY = coordsNextWaypoint.second = coordsCurrentWaypoint.second;

    float sumDiffXY = abs(diffX) + abs(diffY);

    double proportionChangeX = diffX / sumDiffXY;
    double proportionChangeY = diffY / sumDiffXY;

    /*find coords change*/
    float changeX = currentSpeed * proportionChangeX;
    float changeY = currentSpeed * proportionChangeY;

    /*change coords*/
    currentCoords.first += changeX;
    currentCoords.second += changeY;
}

bool Enemy::ifWaypointPassed(EnemiesWay& way){

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
void Enemy::freeze(float freezeMultiplyer){
    currentSpeed = maxSpeed * (1 - freezeMultiplyer);
}

void Enemy::unfreeze(){
    currentSpeed = maxSpeed;
}

void Enemy::damageBaseAndGetKilled(Base& base){
    base.applyDamage(damageToBase);
    hitPoints = 0;
}