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

Projectile* IceTower::newProjectile(SDL_Renderer* renderer){
    // TODO change
    return new BasicProjectile(TexturesEnumeration::BASIC_PROJECTILE_TEXTURE, aimedEnemy, towerCoords);
}

