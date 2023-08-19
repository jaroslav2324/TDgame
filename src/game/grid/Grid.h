#pragma once

#include "SDL2/SDL.h"

#include "../../maths/maths.h"
#include "../../maths/Coords.h"
#include "../../engine/Engine.h"
#include "../../settings.h"

#include "GridTile.h"

/*grid class for render tiles
ONLY FOR RENDERING TILES*/
class Grid{
    public:
    Grid(SDL_Rect gridRect, int tileWidth = TILESIZE, int tileHeight = TILESIZE, 
         int gridTilesAmountWidth = GAME_LEVEL_WIDTH, int gridTilesAmountHeight = GAME_LEVEL_HEIGHT);

    ~Grid();
    void renderGrid(Renderer* renderer);

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    bool isPointInGridRect(Point p);

    Coords getStartCoords();
    Coords getEndCoords();
    SDL_Rect getGridRect();

    private:
    int gridTilesAmountWidth = 0;
    int gridTilesAmountHeight = 0;

    int tileWidth;
    int tileHeight;

    Coords startCoords;
    Coords endCoords;
    SDL_Rect gridRect;
    
    GridTile*** gridTilesField = nullptr;
};
