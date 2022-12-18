
#include "SDL2/SDL.h"

#include "../settings.h"
#include "GridTile.h"
#include "../TexturesHolder.h"

/*grid class for render tiles
ONLY FOR RENDERING TILES*/
class Grid{
    public:
    Grid();
    ~Grid();
    void renderGrid(TexturesHolder* texturesHolder);

    private:
    GridTile* gridTilesField[GAME_LEVEL_HEIGHT][GAME_LEVEL_WIDTH];
};
