#include "BasicTower.h"

BasicTower::~BasicTower(){
    deleteAttackTimer();
}

void BasicTower::setAttackTimer(){
    attackTimer = new PeriodicTimer(attackSpeed);
}

void BasicTower::deleteAttackTimer(){
    if (attackTimer != nullptr){
        delete attackTimer;
        attackTimer = nullptr;
    }
}

