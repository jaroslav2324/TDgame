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
    return new BasicProjectile(renderer, aimedEnemy, towerCoords);
}

void BasicTower::loadTexture(SDL_Renderer* renderer){

    if (towerTexture == nullptr)
        towerTexture = IMG_LoadTexture(renderer, BASIC_TOWER_SPRITE_PATH);
    else{
        SDL_DestroyTexture(towerTexture);
        towerTexture = IMG_LoadTexture(renderer, BASIC_TOWER_SPRITE_PATH);
    }    
}
