#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../../engine/Engine.h"
#include "../../maths/maths.h"

#include "../grid/EnemiesWay.h"
#include "../grid/Base.h"
#include "../grid/Portal.h"
#include "../enemies/EnemyTypes.h"

using std::string;
using std::cout;
using std::endl;

/*Basic class for all enemies*/
class Enemy{
    
public:
    Enemy(EnemiesWay* way, Base* base, Portal * portal, Coords coords);
    ~Enemy();

    void move();
    
    void applyDamage(double damage);
    bool isDead();

    void freeze(double freezeMultiplyer, double time);
    void unfreeze();

    bool isNearBase();
    void damageBaseAndGetKilled();

    //freezeTime in ms
    void activateFreezeTimer(double freezeTime);
    
    void render(Renderer* renderer);

    EnemyTypes getType();
    Coords getCoords();
    int getNumNextWaypoint();

protected:
    double hitPoints = 0;
    double maxHitPoints = 0;
    double currentSpeed = 0;
    double maxSpeed = 0;

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
    EnemyTypes enemyType;

/*baseSpeed is multiplyed by timePeriodOfMoving. The last value is given in milliseconds*/
    void MoveToNextWaypoint(double timePeriodOfMoving); 

    bool ifWaypointPassed();
    void replaceToNextWaypointCoords();

    void renderHitPointsBar(Renderer* renderer);
};
