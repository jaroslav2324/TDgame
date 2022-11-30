#pragma once

#include <string>

#include "SDL2/SDL.h"

#include "Coords.h"

/*class for tile of the grid*/
class GridTile{
    public:
    GridTile(SDL_Renderer* renderer, Coords coords);
    GridTile(SDL_Renderer* renderer, std::string& spritePath, Coords coords);
    ~GridTile();

    void render(SDL_Renderer* renderer);
    
    private:
    Coords coords;

    std::string spritePath = "";

    SDL_Texture* tileTexture = nullptr;

    void loadTexture(SDL_Renderer* renderer);
};
