#include "IceTower.h"

IceTower::~IceTower(){
    deleteAttackTimer();
}

void IceTower::setAttackTimer(){
    attackTimer = new PeriodicTimer(attackSpeed);
}

void IceTower::deleteAttackTimer(){
    if (attackTimer != nullptr){
        delete attackTimer;
        attackTimer = nullptr;
    }
}

Projectile* IceTower::newProjectile(){
    // TODO change
    return new BasicProjectile(aimedEnemy, towerCoords);
}

