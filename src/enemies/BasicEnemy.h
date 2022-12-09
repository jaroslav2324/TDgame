#pragma once

#include "../Timers.h"
#include "../abstractClasses/Enemy.h"
#include "../Portal.h"


class BasicEnemy: public Enemy{
    public:
    BasicEnemy(SDL_Renderer* renderer, EnemiesWay* way, Base* base, Portal* portal, Coords coords): Enemy(renderer, way, base, portal, coords){
        setMovementTimer();

    hitPoints = 10;
    maxHitPoints = 10;
    currentSpeed = 100;
    maxSpeed = 5;

    damageToBase = 1;
    };

    ~BasicEnemy();

    private:
    void setMovementTimer();
    void deleteMovementTimer();
};