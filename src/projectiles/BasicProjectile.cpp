#include "BasicProjectile.h"

void BasicProjectile::loadTexture(SDL_Renderer* renderer){
    
    if (projectileTexture == nullptr)
        projectileTexture = IMG_LoadTexture(renderer, BASIC_PROJECTILE_SPRITE_PATH);
    else{
        SDL_DestroyTexture(projectileTexture);
        projectileTexture = IMG_LoadTexture(renderer, BASIC_PROJECTILE_SPRITE_PATH);
    }   
}
