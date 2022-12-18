#pragma once

#include <string>

#include "SDL2/SDL.h"

#include "../settings.h"
#include "../Coords.h"
#include "../TexturesHolder.h"

/*class for tile of the grid*/
class GridTile{
    public:
    GridTile(TexturesEnumeration gridTileTextureType, Coords coords);
    ~GridTile();

    void render(TexturesHolder* texturesHolder);
    
    private:
    Coords coords;
    TexturesEnumeration gridTileTextureType;
};
