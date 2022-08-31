#pragma once

#include "SDL2/SDL_image.h"

#include <utility>

#include "settings.h"
#include "SDL2/SDL.h"

class Portal{
    public:
    Portal(std::pair<float, float> spawnCoords);
    ~Portal();
    void loadAndRenderPortal(SDL_Renderer* renderer);

    private:
    std::pair<float, float> coords;
    SDL_Texture* portalTexture = nullptr;
};
