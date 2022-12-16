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
    return new BasicProjectile(renderer, aimedEnemy, towerCoords);
}

void FireTower::loadTexture(SDL_Renderer* renderer){

    if (towerTexture == nullptr)
        towerTexture = IMG_LoadTexture(renderer, FIRE_TOWER_SPRITE_PATH);
    else{
        SDL_DestroyTexture(towerTexture);
        towerTexture = IMG_LoadTexture(renderer, FIRE_TOWER_SPRITE_PATH);
    }    
}
