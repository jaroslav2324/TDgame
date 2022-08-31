
#include "Portal.h"

Portal::Portal(std::pair<float, float> spawnCoords){
    coords = spawnCoords;
}

Portal::~Portal(){
    SDL_DestroyTexture(portalTexture);
}

void Portal::loadAndRenderPortal(SDL_Renderer* renderer){

    if (portalTexture == nullptr)
        portalTexture = IMG_LoadTexture(renderer, PORTAL_TILE_SPRITE_PATH);

    SDL_Rect placeRect = {coords.first, coords.second, TILESIZE, TILESIZE};
    SDL_RenderCopy(renderer, portalTexture, NULL, &placeRect);
}