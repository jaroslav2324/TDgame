#pragma once

#include "Tower.h"

class BasicTower: public Tower{
    public:
    BasicTower(EnemyManager* enemyManager): Tower(enemyManager){
        //TODO set attack timer
        setAttackTimer();
    };
    ~BasicTower();

    private:
    void setAttackTimer();
    void deleteAttackTimer();
};