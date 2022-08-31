#include <SDL2/SDL_image.h>

#include "settings.h"
#include "GridTile.h"

GridTile::GridTile(std::pair<float, float> coords){
    GridTile::coords = coords;
}

GridTile::GridTile(std::string& spritePath, std::pair<float, float> coords){
    GridTile::coords = coords;
    GridTile::spritePath = spritePath;
}

GridTile::~GridTile(){
    SDL_DestroyTexture(tileTexture);
}

/*loads texture of tile if it was not loaded, renders tile*/
void GridTile::loadAndRenderTile(SDL_Renderer* renderer){

    //load texture
    if (tileTexture == nullptr){
        if (spritePath == "")
            tileTexture = IMG_LoadTexture(renderer, BASIC_GRID_TILE_SPRITE_PATH);
        else
            tileTexture = IMG_LoadTexture(renderer, spritePath.c_str());
    }
    //render texture
    SDL_Rect placeRect = {coords.first, coords.second, TILESIZE, TILESIZE};
    SDL_RenderCopy(renderer, tileTexture, NULL, &placeRect);
}
