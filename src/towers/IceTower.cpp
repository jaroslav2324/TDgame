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
    return new IceballProjectile(aimedEnemy, towerCoords);
}

