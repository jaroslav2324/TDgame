#pragma once

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../Renderer.h"
#include "../Coords.h"
#include "../Timers.h"
#include "../ObjectCursorInteractionsModes.h"

using std::string;

class Button
{
public:

    Button(TexturesEnumeration textureNoInteraction, TexturesEnumeration textureHoveredOver, TexturesEnumeration texturePressedOn, Coords coords);
    ~Button();

    void render(Renderer* renderer);

    void setModeNoCursorInteraction();
    void setModePressedOn();
    void setModeHoveredOver();
    //void setRecentlyPressedFlag();
    //void unsetRecentlyPressedFlag();

    bool isPointInRect(Coords point);

    void setWidthHeight(int width, int height);

    bool isPressingCooldownInactive();

private:

    int btn_width = 100;
    int btn_height = 50;

    // how long show texture of pressed button after mouse clicking
    CountdownTimer* pressingCooldownTimer = nullptr;
    
    ObjectCursorInteractionsModes btnCursorInteractionMode = NO_INTERACTION;

    TexturesEnumeration textureNoInteraction;
    TexturesEnumeration texturePressedOn;
    TexturesEnumeration textureHoveredOver;

    // in milliseconds
    const double pressingCooldownTime = 250;

    // center coords
    Coords coords;
};
