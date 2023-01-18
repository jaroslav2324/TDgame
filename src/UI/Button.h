#pragma once

#include <string>
#include <fstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../Renderer.h"
#include "../maths/Coords.h"
#include "../Timers.h"
#include "../ObjectCursorInteractionsModes.h"
#include "../SoundPlayer.h"

using std::ostream;
using std::istream;
using std::string;

class Button
{
public:

    Button( Coords coords, Renderer* renderer, SoundPlayer* soundPlayer,
    TexturesEnumeration textureNoInteraction = TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE,
     TexturesEnumeration textureHoveredOver = TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE,
    TexturesEnumeration texturePressedOn = TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE,
    SoundsEnumeration soundHoverOver = SoundsEnumeration::BTN_HOVERED_OVER,
     SoundsEnumeration soundPressOn = SoundsEnumeration::BTN_PRESSED_ON);
    ~Button();

    void render();

    void setModeAndPlaySound(ObjectCursorInteractionsModes btnMode);

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

    SoundsEnumeration soundHoverOver;
    SoundsEnumeration soundPressOn;

    // in milliseconds
    double pressingCooldownTime = 250;

    // center coords
    Coords coords;

    Renderer* renderer = nullptr;
    SoundPlayer* soundPlayer = nullptr;

    // void setModeNoCursorInteraction();
    // void setModeHoveredOver();
    // void setModePressedOn();
};
