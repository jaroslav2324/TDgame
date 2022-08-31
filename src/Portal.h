#pragma once

#include "SDL2/SDL.h"

class Portal{
    public:
    Portal(std::pair<float, float> spawnCoords);
    ~Portal();
    void render();

    private:
    std::pair<float, float> coords;
    SDL_Texture* portalSprite = nullptr;
};
