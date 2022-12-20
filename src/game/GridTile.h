#pragma once

#include <string>
#include <fstream>
#include <iostream>

#include "SDL2/SDL.h"

#include "../settings.h"
#include "../Coords.h"
#include "../Renderer.h"

using std::ostream;
using std::istream;
using std::cout;
using std::endl;

/*class for tile of the grid*/
class GridTile{
    public:
    GridTile(TexturesEnumeration gridTileTextureType, Coords coords);
    ~GridTile();

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    void render(Renderer* renderer);
    
    private:
    Coords coords;
    TexturesEnumeration gridTileTextureType;
};
