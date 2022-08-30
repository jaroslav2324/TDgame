#pragma once

#include "../Timers.h"
#include "../abstractClasses/Enemy.h"


class BasicEnemy: public Enemy{
    public:
    BasicEnemy(std::string spritePath): Enemy(spritePath){
        setMovementTimer();
    };

    ~BasicEnemy();

    private:
    void setMovementTimer();
    void deleteMovementTimer();
};