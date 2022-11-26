#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../Timers.h"
#include "../EnemiesWay.h"
#include "../Base.h"
#include "../approximateComparison.h"

using std::string;

/*Basic class for all enemies*/
class Enemy{
    
public:
    Enemy(SDL_Renderer* renderer, EnemiesWay* way, Base* base, std::pair<float, float> coords);
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
    
    virtual void loadTexture(SDL_Renderer* renderer);
    void render(SDL_Renderer* renderer);

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
    
    SDL_Texture* enemyTexture = nullptr;
};
