#pragma once

#include "../abstractClasses/Tower.h"

class BasicTower: public Tower{
    public:
    BasicTower(EnemyManager* enemyManager): Tower(enemyManager){
        setAttackTimer();
    };
    ~BasicTower();

    private:

    void setAttackTimer();
    void deleteAttackTimer();
};