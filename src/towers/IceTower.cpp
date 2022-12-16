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
    return new BasicProjectile(renderer, aimedEnemy, towerCoords);
}

void IceTower::loadTexture(SDL_Renderer* renderer){

    if (towerTexture == nullptr)
        towerTexture = IMG_LoadTexture(renderer, ICE_TOWER_SPRITE_PATH);
    else{
        SDL_DestroyTexture(towerTexture);
        towerTexture = IMG_LoadTexture(renderer, ICE_TOWER_SPRITE_PATH);
    }    
}
