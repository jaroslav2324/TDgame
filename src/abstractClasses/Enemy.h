#pragma once

#include <iostream>

#include <SDL2/SDL.h>

#include "../Timers.h"
#include "../EnemiesWay.h"
#include "../Base.h"
#include "../approximateComparison.h"

using std::string;

/*Basic class for all enemies*/
class Enemy{
    
public:
    Enemy(string& enemySpritePath, EnemiesWay* way, Base* base);
    ~Enemy();

    void move();
    
    void applyDamage(float damage);
    bool isDead();

    void freeze(float freezeMultiplyer, double time);
    void unfreeze();

    virtual void setMovementTimer() = 0;

    bool isNearBase();
    void damageBaseAndGetKilled();

    //freezeTime in ms
    void activateFreezeTimer(double freezeTime);
    //TODO load sprite

    float getCoordX();
    float getCoordY();

protected:
    float hitPoints = 0;
    float maxHitPoints = 0;
    float currentSpeed = 0;
    float maxSpeed = 0;

    int damageToBase = 0;

    bool isFreezed = false;

    int numCurrentWaypoint = 0;
    std::pair<float, float> currentCoords;
    std::pair<float, float> coordsCurrentWaypoint;
    std::pair<float, float> coordsNextWaypoint;

    //TODO implement Timer
    //TODO add system changing timer
    PeriodicTimer* movementTimer = nullptr;
    
    CountdownTimer* freezeTimer = nullptr;

    EnemiesWay* way = nullptr;
    Base* base = nullptr;

/*baseSpeed multiplyes by timePeriodOfMoving in seconds*/
    void MoveToNextWaypoint(double timePeriodOfMoving);

    bool ifWaypointPassed();
    void replaceToNextWaypointCoords();

    void copyCoords(std::pair<float, float>& destination, std::pair<float, float>& source);
    
    SDL_Texture* enemySprite = nullptr;
};
