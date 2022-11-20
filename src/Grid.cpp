#include "Grid.h"

Grid::Grid(SDL_Renderer* renderer){

    //TODO create game level by filling field with different sprites
    for (int i = 0, coordY = 0; i < GAME_LEVEL_HEIGHT; i++, coordY += TILESIZE)
        for (int j = 0, coordX = 0; j < GAME_LEVEL_WIDTH; j ++, coordX += TILESIZE){
            auto gridCoords = std::make_pair(coordX + TILESIZE / 2, coordY + TILESIZE / 2);
            gridTilesField[i][j] = new GridTile(renderer, gridCoords);
        }
}

Grid::~Grid(){

    for (int i = 0; i < GAME_LEVEL_HEIGHT; i++)
        for (int j = 0; j < GAME_LEVEL_WIDTH; j++)
            delete gridTilesField[i][j];
}

void Grid::renderGrid(SDL_Renderer* renderer){

    for (int i = 0; i < GAME_LEVEL_HEIGHT; i++)
        for (int j = 0; j < GAME_LEVEL_WIDTH; j++)
            gridTilesField[i][j]->render(renderer);
}
