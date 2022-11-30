#pragma once

#include "SDL2/SDL_image.h"

#include <utility>

#include "SDL2/SDL.h"

#include "settings.h"
#include "Coords.h"

/*Only graphical class, enemies spawn in enemy manager*/
class Portal{
    public:
    Portal(SDL_Renderer* renderer, Coords spawnCoords);
    ~Portal();

    void render(SDL_Renderer* renderer);

    private:
    Coords coords;
    SDL_Texture* portalTexture = nullptr;

    void loadTexture(SDL_Renderer* renderer);
};
