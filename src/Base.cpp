#include "Base.h"

Base::Base(SDL_Renderer* renderer, Coords spawnCoords){
    coords = spawnCoords;
    
    loadTexture(renderer);
}

Base::~Base(){

    if (baseTexture != nullptr)
        SDL_DestroyTexture(baseTexture);
}

int Base::getHitPoits(){
    return hitPoints;
}

void Base::setHitPoints(int hitPoints){
    Base::hitPoints = hitPoints;
}

void Base::applyDamage(int damage){
    hitPoints -= damage;
}

bool Base::noHitPoitsLeft(){
    if (hitPoints <= 0)
        return true;
    return false;
}

void Base::loadTexture(SDL_Renderer* renderer){

    if (baseTexture == nullptr)
        baseTexture = IMG_LoadTexture(renderer, BASE_TILE_SPRITE_PATH);    
    else {
        SDL_DestroyTexture(baseTexture);
        baseTexture = IMG_LoadTexture(renderer, BASE_TILE_SPRITE_PATH);    
    }
}

void Base::render(SDL_Renderer* renderer){

    int x = coords.x - TILESIZE / 2;
    int y = coords.y - TILESIZE / 2;
    SDL_Rect baseRect = {x, y, TILESIZE, TILESIZE};
    SDL_RenderCopy(renderer, baseTexture, 0, &baseRect);
}
