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

void GridTile::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving grid tile stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    
    // save grid tile texture type
    outpustStream.write((char*)&gridTileTextureType, sizeof(gridTileTextureType));
}

void GridTile::loadFromBinaryFile(istream& inputStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !LOADING_LEVELS_ON)
        cout << "Loading levels is turned off. Loading grid tile stopped." << endl;

    if (!LOADING_LEVELS_ON)
        return;

    // load grid tile texture type
    inputStream.read((char*)&gridTileTextureType, sizeof(gridTileTextureType));

}
