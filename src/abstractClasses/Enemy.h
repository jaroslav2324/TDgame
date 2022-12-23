#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../Renderer.h"
#include "../Timers.h"
#include "../game/EnemiesWay.h"
#include "../game/Base.h"
#include "../game/Portal.h"
#include "../approximateComparison.h"

using std::string;
using std::cout;
using std::endl;

/*Basic class for all enemies*/
class Enemy{
    
public:
    Enemy(EnemiesWay* way, Base* base, Portal * portal, Coords coords);
    ~Enemy();

    void move();
    
    void applyDamage(float damage);
    bool isDead();

    void freeze(float freezeMultiplyer, double time);
    void unfreeze();

    bool isNearBase();
    void damageBaseAndGetKilled();

    //freezeTime in ms
    void activateFreezeTimer(double freezeTime);
    
    void render(Renderer* renderer);

    Coords getCoords();
    int getNumNextWaypoint();

protected:
    float hitPoints = 0;
    float maxHitPoints = 0;
    float currentSpeed = 0;
    float maxSpeed = 0;

    int damageToBase = 0;

    bool isFreezed = false;

    int numNextWaypoint = 1;
    Coords currentCoords;
    Coords coordsCurrentWaypoint;
    Coords coordsNextWaypoint;

    PeriodicTimer* movementTimer = nullptr;
    
    CountdownTimer* freezeTimer = nullptr;

    EnemiesWay* way = nullptr;
    Base* base = nullptr;
    Portal * portal = nullptr;

    TexturesEnumeration enemyTextureType;

/*baseSpeed is multiplyed by timePeriodOfMoving. The last value is given in milliseconds*/
    void MoveToNextWaypoint(double timePeriodOfMoving); 

    bool ifWaypointPassed();
    void replaceToNextWaypointCoords();

    void renderHitPointsLine(Renderer* renderer);
};
