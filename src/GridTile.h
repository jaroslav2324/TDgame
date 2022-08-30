#pragma once

#include <string>

#include "SDL2/SDL.h"

/*class for tile of the grid*/
class GridTile{
    public:
    GridTile();
    GridTile(std::string& spritePath);
    ~GridTile();
    void renderTile();
    
    private:
    SDL_Texture* tileTexture;
};
