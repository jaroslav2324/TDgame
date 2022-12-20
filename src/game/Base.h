#pragma once

#include <utility>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "../settings.h"
#include "../Coords.h"
#include "../Renderer.h"

class Base{
    public:
    //TODO add interaction with end game interfase
    //TODO end game
    Base(Coords spawnCoords);
    ~Base();

    int getHitPoits();
    void setHitPoints(int hitPoints);
    bool noHitPoitsLeft();

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    void applyDamage(int damage);

    void render(Renderer* renderer);

    private:
    int hitPoints = 10;

    Coords coords;
};