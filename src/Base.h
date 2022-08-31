#pragma once

#include <utility>

#include "SDL2/SDL.h"

class Base{
    public:
    //TODO add interaction with end game interfase
    //TODO end game
    Base(std::pair<float, float> spawnCoords);

    int getHitPoits();
    void setHitPoints(int hitPoints);
    bool noHitPoitsLeft();

    void applyDamage(int damage);

    private:
    int hitPoints;

    std::pair<float, float> coords;

    SDL_Texture* baseSprite = nullptr;
};