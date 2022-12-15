
#include "Portal.h"

Portal::Portal(SDL_Renderer* renderer, Coords coords){
    Portal::coords = coords;
    loadTexture(renderer);
}

Portal::~Portal(){
    if (portalTexture != nullptr){
        SDL_DestroyTexture(portalTexture);
        portalTexture = nullptr;
    }
}

void Portal::loadTexture(SDL_Renderer* renderer){

    if (portalTexture == nullptr)
        portalTexture = IMG_LoadTexture(renderer, PORTAL_TILE_SPRITE_PATH);    
    else {
        SDL_DestroyTexture(portalTexture);
        portalTexture = IMG_LoadTexture(renderer, PORTAL_TILE_SPRITE_PATH);    
    }
}

void Portal::render(SDL_Renderer* renderer){

    int x = coords.x - TILESIZE / 2;
    int y = coords.y - TILESIZE / 2;
    SDL_Rect portalRect = {x, y, TILESIZE, TILESIZE};
    SDL_RenderCopy(renderer, portalTexture, 0, &portalRect);
}

Coords Portal::getCoords(){
    return coords;
}
