#pragma once

#include <string>

#include "SDL2/SDL.h"

/*class for tile of the grid*/
class GridTile{
    public:
    GridTile(std::pair<float, float> coords);
    GridTile(std::string& spritePath, std::pair<float, float> coords);
    ~GridTile();
    void loadAndRenderTile(SDL_Renderer* renderer);
    
    private:
    std::pair<float, float> coords;

    std::string spritePath = "";

    SDL_Texture* tileTexture;
};
