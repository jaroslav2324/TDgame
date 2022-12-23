#include "FireTower.h"

FireTower::~FireTower(){
    deleteAttackTimer();
}

void FireTower::setAttackTimer(){
    attackTimer = new PeriodicTimer(attackSpeed);
}

void FireTower::deleteAttackTimer(){
    if (attackTimer != nullptr){
        delete attackTimer;
        attackTimer = nullptr;
    }
}

Projectile* FireTower::newProjectile(){
    return new FireballProjectile(aimedEnemy, towerCoords);
}

