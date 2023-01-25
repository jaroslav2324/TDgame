#pragma once

#include "SDL2/SDL.h"

#include "../../maths/maths.h"
#include "../../engine/Engine.h"
#include "../../settings.h"

#include "GridTile.h"

/*grid class for render tiles
ONLY FOR RENDERING TILES*/
class Grid{
    public:
    Grid(Coords startCoords, Coords endCoords, int tileWidth = TILESIZE, int tileHeight = TILESIZE, 
         int gridTilesAmountWidth = GAME_LEVEL_WIDTH, int gridTilesAmountHeight = GAME_LEVEL_HEIGHT);

    ~Grid();
    void renderGrid(Renderer* renderer);

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    bool isPointInRect(Point p);

    Coords getStartCoords();
    Coords getEndCoords();

    private:
    int gridTilesAmountWidth = 0;
    int gridTilesAmountHeight = 0;

    int tileWidth;
    int tileHeight;

    Coords startCoords;
    Coords endCoords;
    
    GridTile*** gridTilesField = nullptr;
};
