#pragma once

#include "SDL2/SDL_image.h"

#include <utility>

#include "SDL2/SDL.h"

#include "../settings.h"
#include "../Coords.h"
#include "../TexturesHolder.h"

/*Only graphical class, enemies spawn in enemy manager*/
class Portal{
    public:
    Portal(Coords coords);
    ~Portal();

    void render(TexturesHolder* texturesHolder);

    Coords getCoords();

    private:
    Coords coords;
};
