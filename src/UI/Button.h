#pragma once

#include <string>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../Coords.h"
#include "../Timers.h"
#include "../ObjectCursorInteractionsModes.h"

using std::string;

class Button
{
public:

    Button(SDL_Renderer* renderer, string& btnImgPath, string& btnPressedImgPath, string& btnHoveredImgPath, Coords coords);
    Button(SDL_Renderer* renderer, const char* btnImgPath, const char* btnPressedImgPath, const char* btnHoveredImgPath, Coords coords);
    ~Button();

    void render(SDL_Renderer* renderer);

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

    void loadTextures(SDL_Renderer* renderer, string& btnImgPath, string& btnPressedImgPath, string& btnHoveredImgPath);
    void loadTextures(SDL_Renderer* renderer, const char* btnImgPath, const char* btnPressedImgPath, const char* btnHoveredImgPath);

    SDL_Texture* btnTexture = nullptr;
    SDL_Texture* pressedBtnTexture = nullptr;
    SDL_Texture* hoveredBtnTexture = nullptr;

    // how long show texture of pressed button after mouse clicking
    CountdownTimer* pressingCooldownTimer = nullptr;
    
    ObjectCursorInteractionsModes btnCursorInteractionMode = NO_INTERACTION;

    // in milliseconds
    const double pressingCooldownTime = 250;

    // center coords
    Coords coords;
};
