#include "Grid.h"

Grid::Grid(SDL_Rect gridRect, int tileWidth, int tileHeight, int gridTilesAmountWidth, int gridTilesAmountHeight){

    this->gridRect = gridRect;
    Coords startCoords(gridRect.x, gridRect.y);
    Coords endCoords(gridRect.x + gridRect.w, gridRect.y + gridRect.h);
    
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    this->gridTilesAmountWidth = gridTilesAmountWidth;
    this->gridTilesAmountHeight = gridTilesAmountHeight;

    gridTilesField = new GridTile**[gridTilesAmountHeight];

    for (int i = 0, coordY = startCoords.y; i < gridTilesAmountHeight; i++, coordY += tileHeight){
        gridTilesField[i] = new GridTile*[gridTilesAmountWidth];
        for (int j = 0, coordX = startCoords.x; j < gridTilesAmountWidth; j ++, coordX += tileWidth){
            auto gridCoords = Coords(coordX + tileWidth / 2, coordY + tileHeight / 2);
            gridTilesField[i][j] = new GridTile(TexturesEnumeration::BASIC_GRID_TILE_TEXTURE, gridCoords);
        }
    }
}

Grid::~Grid(){

    for (int i = 0; i < gridTilesAmountHeight; i++){
        for (int j = 0; j < gridTilesAmountWidth; j++){
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

    for (int i = 0; i < gridTilesAmountHeight; i++)
        for (int j = 0; j < gridTilesAmountWidth; j++)
            gridTilesField[i][j]->render(renderer);
}

bool Grid::isPointInGridRect(Point p){
    return isPointInRect(p, gridRect);
}

Coords Grid::getStartCoords(){
    return Coords(gridRect.x, gridRect.y);
}

Coords Grid::getEndCoords(){
    return Coords(gridRect.x + gridRect.w, gridRect.y + gridRect.h);
}

SDL_Rect Grid::getGridRect(){
    return gridRect;
}

void Grid::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving grid stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    
    // save grid width and height
    //TODO add
    outpustStream.write((char*)&gridTilesAmountWidth, sizeof(gridTilesAmountWidth));
    outpustStream.write((char*)&gridTilesAmountHeight, sizeof(gridTilesAmountHeight));

    // save grid tiles
    for (int i = 0; i < gridTilesAmountHeight; i++)
        for (int j = 0; j < gridTilesAmountWidth; j++)
        gridTilesField[i][j]->saveToBinaryFile(outpustStream);
}

void Grid::loadFromBinaryFile(istream& inputStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !LOADING_LEVELS_ON)
        cout << "Loading levels is turned off. Loading grid stopped." << endl;

    if (!LOADING_LEVELS_ON)
        return;

    // load grid width and height
    //TODO add
    inputStream.read((char*)&gridTilesAmountWidth, sizeof(gridTilesAmountWidth));
    inputStream.read((char*)&gridTilesAmountHeight, sizeof(gridTilesAmountHeight));

    // load grid tiles
    for (int i = 0; i < gridTilesAmountHeight; i++)
        for (int j = 0; j < gridTilesAmountWidth; j++)
        gridTilesField[i][j]->loadFromBinaryFile(inputStream);
}
