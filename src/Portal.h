#pragma once

#include "SDL2/SDL_image.h"

#include <utility>

#include "settings.h"
#include "SDL2/SDL.h"

/*Only graphical class, enemies spawn in enemy manager*/
class Portal{
    public:
    Portal(SDL_Renderer* renderer, std::pair<float, float> spawnCoords);
    ~Portal();

    void render(SDL_Renderer* renderer);

    private:
    std::pair<float, float> coords;
    SDL_Texture* portalTexture = nullptr;

    void loadTexture(SDL_Renderer* renderer);
};
