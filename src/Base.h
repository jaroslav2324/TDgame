#pragma once

#include <utility>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "settings.h"

class Base{
    public:
    //TODO add interaction with end game interfase
    //TODO end game
    Base(SDL_Renderer* renderer, std::pair<float, float> spawnCoords);
    ~Base();

    int getHitPoits();
    void setHitPoints(int hitPoints);
    bool noHitPoitsLeft();

    void applyDamage(int damage);

    void render(SDL_Renderer* renderer);

    private:
    int hitPoints;

    std::pair<float, float> coords;

    SDL_Texture* baseTexture = nullptr;

    void loadTexture(SDL_Renderer* renderer);
};