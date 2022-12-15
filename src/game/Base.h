#pragma once

#include <utility>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "../settings.h"
#include "../Coords.h"

class Base{
    public:
    //TODO add interaction with end game interfase
    //TODO end game
    Base(SDL_Renderer* renderer, Coords spawnCoords);
    ~Base();

    int getHitPoits();
    void setHitPoints(int hitPoints);
    bool noHitPoitsLeft();

    void applyDamage(int damage);

    void render(SDL_Renderer* renderer);

    private:
    int hitPoints = 10;

    Coords coords;

    SDL_Texture* baseTexture = nullptr;

    void loadTexture(SDL_Renderer* renderer);
};