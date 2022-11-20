#pragma once

#include "../Timers.h"
#include "../abstractClasses/Enemy.h"


class BasicEnemy: public Enemy{
    public:
    BasicEnemy(EnemiesWay* way, Base* base): Enemy(way, base){
        setMovementTimer();
    };

    ~BasicEnemy();

    private:
    void setMovementTimer();
    void deleteMovementTimer();
};