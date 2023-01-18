#pragma once

#include "SDL2/SDL_image.h"

#include <utility>

#include "SDL2/SDL.h"

#include "../settings.h"
#include "../maths/Coords.h"
#include "../Renderer.h"

/*Only graphical class, enemies spawn in enemy manager*/
class Portal{
    public:
    Portal(Coords coords);
    ~Portal();

    void render(Renderer* renderer);

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    Coords getCoords();

    private:
    Coords coords;
};
