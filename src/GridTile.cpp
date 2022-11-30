#include <SDL2/SDL_image.h>

#include "settings.h"
#include "GridTile.h"

GridTile::GridTile(SDL_Renderer* renderer, Coords coords){
    GridTile::coords = coords;
    loadTexture(renderer);
}

GridTile::GridTile(SDL_Renderer* renderer, std::string& spritePath, Coords coords){
    GridTile::coords = coords;
    GridTile::spritePath = spritePath;
    loadTexture(renderer);
}

GridTile::~GridTile(){
    if (tileTexture != nullptr)
        SDL_DestroyTexture(tileTexture);
}

void GridTile::loadTexture(SDL_Renderer* renderer){

    if (tileTexture == nullptr)
        tileTexture = IMG_LoadTexture(renderer, BASIC_GRID_TILE_SPRITE_PATH);
    else{
        SDL_DestroyTexture(tileTexture);
        tileTexture = IMG_LoadTexture(renderer, BASIC_GRID_TILE_SPRITE_PATH);
    }  

}

void GridTile::render(SDL_Renderer* renderer){

    int x = coords.x - TILESIZE/ 2;
    int y = coords.y - TILESIZE / 2;
    SDL_Rect tileRect = {x, y, TILESIZE, TILESIZE};
    SDL_RenderCopy(renderer, tileTexture, 0, &tileRect);
}
