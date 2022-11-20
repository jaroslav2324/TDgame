#pragma once

#include <string>

#include "SDL2/SDL.h"

/*class for tile of the grid*/
class GridTile{
    public:
    GridTile(SDL_Renderer* renderer, std::pair<float, float> coords);
    GridTile(SDL_Renderer* renderer, std::string& spritePath, std::pair<float, float> coords);
    ~GridTile();

    void render(SDL_Renderer* renderer);
    
    private:
    std::pair<float, float> coords;

    std::string spritePath = "";

    SDL_Texture* tileTexture = nullptr;

    void loadTexture(SDL_Renderer* renderer);
};
