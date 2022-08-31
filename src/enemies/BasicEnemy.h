#pragma once

#include "../Timers.h"
#include "../abstractClasses/Enemy.h"


class BasicEnemy: public Enemy{
    public:
    BasicEnemy(std::string spritePath, EnemiesWay* way, Base* base): Enemy(spritePath, way, base){
        setMovementTimer();
    };

    ~BasicEnemy();

    private:
    void setMovementTimer();
    void deleteMovementTimer();
};