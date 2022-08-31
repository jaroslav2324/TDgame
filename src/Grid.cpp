#include "Grid.h"

Grid::Grid(){
    //TODO create game level by filling field with different sprites
    for (int i = 0; i < GAME_LEVEL_HEIGHT; i++)
        for (int j = 0; j < GAME_LEVEL_WIDTH; j++)
            gridTilesField[i][j] = new GridTile();
    
}

Grid::~Grid(){
    for (int i = 0; i < GAME_LEVEL_HEIGHT; i++)
        for (int j = 0; j < GAME_LEVEL_WIDTH; j++)
            delete gridTilesField[i][j];
}

void Grid::renderGrid(){
    //TODO render grid
}
