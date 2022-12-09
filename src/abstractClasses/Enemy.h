#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../Timers.h"
#include "../EnemiesWay.h"
#include "../Base.h"
#include "../Portal.h"
#include "../approximateComparison.h"

using std::string;

/*Basic class for all enemies*/
class Enemy{
    
public:
    Enemy(SDL_Renderer* renderer, EnemiesWay* way, Base* base, Portal * portal, Coords coords);
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
    Coords currentCoords;
    Coords coordsCurrentWaypoint;
    Coords coordsNextWaypoint;

    //TODO implement Timer
    //TODO add system changing timer
    PeriodicTimer* movementTimer = nullptr;
    
    CountdownTimer* freezeTimer = nullptr;

    EnemiesWay* way = nullptr;
    Base* base = nullptr;
    Portal * portal = nullptr;

/*baseSpeed multiplyes by timePeriodOfMoving in seconds*/
    void MoveToNextWaypoint(double timePeriodOfMoving);

    bool ifWaypointPassed();
    void replaceToNextWaypointCoords();

    void copyCoords(Coords& destination, Coords& source);
    
    SDL_Texture* enemyTexture = nullptr;
};
