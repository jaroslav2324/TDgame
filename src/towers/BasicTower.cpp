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

Projectile* BasicTower::newProjectile(SDL_Renderer* renderer){
    return new BasicProjectile(TexturesEnumeration::BASIC_PROJECTILE_TEXTURE, aimedEnemy, towerCoords);
}

