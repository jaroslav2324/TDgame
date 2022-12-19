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

Projectile* FireTower::newProjectile(SDL_Renderer* renderer){
    // TODO change
    return new BasicProjectile(aimedEnemy, towerCoords);
}

