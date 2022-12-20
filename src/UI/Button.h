#pragma once

#include <string>
#include <fstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../Renderer.h"
#include "../Coords.h"
#include "../Timers.h"
#include "../ObjectCursorInteractionsModes.h"

using std::ostream;
using std::istream;
using std::string;

class Button
{
public:

    Button(TexturesEnumeration textureNoInteraction, TexturesEnumeration textureHoveredOver, TexturesEnumeration texturePressedOn, Coords coords);
    ~Button();

    void render(Renderer* renderer);

    void setModeNoCursorInteraction();
    void setModeHoveredOver();
    void setModePressedOn();

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    bool isPointInRect(Coords point);

    void setWidthHeight(int width, int height);

    bool isPressingCooldownInactive();

private:

    int btnWidth = 100;
    int btnHeight = 50;

    // how long show texture of pressed button after mouse clicking
    CountdownTimer* pressingCooldownTimer = nullptr;
    
    ObjectCursorInteractionsModes btnCursorInteractionMode = NO_INTERACTION;

    TexturesEnumeration textureNoInteraction;
    TexturesEnumeration textureHoveredOver;
    TexturesEnumeration texturePressedOn;

    // in milliseconds
    double pressingCooldownTime = 250;

    // center coords
    Coords coords;
};
