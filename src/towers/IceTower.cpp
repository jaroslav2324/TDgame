#include "IceTower.h"

IceTower::~IceTower(){
    deleteAttackTimer();
}

void IceTower::setAttackTimer(){
    if (attackTimer == nullptr)
        attackTimer = new PeriodicTimer(attackSpeed);
    else{
        delete attackTimer;
        attackTimer = nullptr;
    }
}

void IceTower::deleteAttackTimer(){
    if (attackTimer != nullptr){
        delete attackTimer;
        attackTimer = nullptr;
    }
}

