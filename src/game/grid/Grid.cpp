#include "Grid.h"

Grid::Grid(Coords startCoords, Coords endCoords, int tileWidth, int tileHeight, int gridWidth, int gridHeight){

    this->startCoords = startCoords;
    this->endCoords = endCoords;
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    this->gridWidth = gridWidth;
    this->gridHeight = gridHeight;

    gridTilesField = new GridTile**[gridHeight];

    for (int i = 0, coordY = startCoords.y; i < gridHeight; i++, coordY += tileHeight){
        gridTilesField[i] = new GridTile*[gridWidth];
        for (int j = 0, coordX = startCoords.x; j < gridWidth; j ++, coordX += tileWidth){
            auto gridCoords = Coords(coordX + tileWidth / 2, coordY + tileHeight / 2);
            gridTilesField[i][j] = new GridTile(TexturesEnumeration::BASIC_GRID_TILE_TEXTURE, gridCoords);
        }
    }
}

Grid::~Grid(){

    for (int i = 0; i < gridHeight; i++){
        for (int j = 0; j < gridWidth; j++){
            delete gridTilesField[i][j];
            gridTilesField[i][j] = nullptr;
        }
        delete[] gridTilesField[i];
        gridTilesField[i] = nullptr;
    }
    delete[] gridTilesField;
    gridTilesField = nullptr;
}

void Grid::renderGrid(Renderer* renderer){

    for (int i = 0; i < gridHeight; i++)
        for (int j = 0; j < gridWidth; j++)
            gridTilesField[i][j]->render(renderer);
}

void Grid::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving grid stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    
    // save grid width and height
    //TODO add
    outpustStream.write((char*)&gridWidth, sizeof(gridWidth));
    outpustStream.write((char*)&gridHeight, sizeof(gridHeight));

    // save grid tiles
    for (int i = 0; i < gridHeight; i++)
        for (int j = 0; j < gridWidth; j++)
        gridTilesField[i][j]->saveToBinaryFile(outpustStream);
}

void Grid::loadFromBinaryFile(istream& inputStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !LOADING_LEVELS_ON)
        cout << "Loading levels is turned off. Loading grid stopped." << endl;

    if (!LOADING_LEVELS_ON)
        return;

    // load grid width and height
    //TODO add
    inputStream.read((char*)&gridWidth, sizeof(gridWidth));
    inputStream.read((char*)&gridHeight, sizeof(gridHeight));

    // load grid tiles
    for (int i = 0; i < gridHeight; i++)
        for (int j = 0; j < gridWidth; j++)
        gridTilesField[i][j]->loadFromBinaryFile(inputStream);
}
