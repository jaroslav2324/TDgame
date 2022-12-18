#pragma once

#include <utility>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "../settings.h"
#include "../Coords.h"
#include "../TexturesHolder.h"

class Base{
    public:
    //TODO add interaction with end game interfase
    //TODO end game
    Base(Coords spawnCoords);
    ~Base();

    int getHitPoits();
    void setHitPoints(int hitPoints);
    bool noHitPoitsLeft();

    void applyDamage(int damage);

    void render(TexturesHolder* texturesHolder);

    private:
    int hitPoints = 10;

    Coords coords;
};