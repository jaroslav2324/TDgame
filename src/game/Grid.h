
#include "SDL2/SDL.h"

#include "GridTile.h"
#include "../settings.h"
#include "../maths/Coords.h"
#include "../engine/Engine.h"

/*grid class for render tiles
ONLY FOR RENDERING TILES*/
class Grid{
    public:
    //TODO add grid start and end position
    Grid(Coords startCoords, Coords endCoords, int tileWidth = TILESIZE, int tileHeight = TILESIZE, 
         int gridWidth = GAME_LEVEL_WIDTH, int gridHeight = GAME_LEVEL_HEIGHT);

    ~Grid();
    void renderGrid(Renderer* renderer);

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    private:
    int gridWidth = 0;
    int gridHeight = 0;

    int tileWidth;
    int tileHeight;

    Coords startCoords;
    Coords endCoords;
    
    GridTile*** gridTilesField = nullptr;
};
