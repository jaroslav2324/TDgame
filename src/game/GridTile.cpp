#include <SDL2/SDL_image.h>

#include "GridTile.h"

GridTile::GridTile(TexturesEnumeration gridTileTextureType, Coords coords){
    GridTile::coords = coords;
    this->gridTileTextureType = gridTileTextureType;
}

GridTile::~GridTile(){

}

void GridTile::render(Renderer* renderer){

    int x = coords.x - TILESIZE/ 2;
    int y = coords.y - TILESIZE / 2;
    SDL_Rect tileRect = {x, y, TILESIZE, TILESIZE};
    renderer->renderTexture(gridTileTextureType, &tileRect);
}
