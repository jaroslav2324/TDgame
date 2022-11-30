#pragma once

#include "../Timers.h"
#include "../abstractClasses/Enemy.h"


class BasicEnemy: public Enemy{
    public:
    BasicEnemy(SDL_Renderer* renderer, EnemiesWay* way, Base* base, Coords coords): Enemy(renderer, way, base, coords){
        setMovementTimer();
    };

    ~BasicEnemy();

    private:
    void setMovementTimer();
    void deleteMovementTimer();
};