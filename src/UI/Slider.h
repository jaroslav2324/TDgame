#pragma once

#include "iostream"
#include "string"

#include "SDL2/SDL.h"

#include "../CoutTextColors.h"
#include "../TexturesEnum.h"
#include "../Renderer.h"
#include "../Coords.h"

using std::cout;
using std::endl;
using std::string;

class Slider{

    public:

    Slider(Renderer* renderer, SDL_Rect sliderRect, int barWidth = 30, int barHeight = 30);
    ~Slider();

    void setBackgroundTexture(TexturesEnumeration textureNum);
    void setBarTexture(TexturesEnumeration textureNum);

    int getBarPosition();

    void unsetBackgroundTexture();
    void unsetBarTexture();

    void render();

    bool isPointInRect(Coords point);

    void setRect(SDL_Rect rect);
    void setWidth(int width);
    void setHeight(int height);
    void setBarWidth(int barWidth);
    void setBarHeight(int barHeight);

    void setBackgroundColor(SDL_Color color);
    void setBarColor(SDL_Color color);
    void setLineColor(SDL_Color color);
    void setTitleColor(SDL_Color color);

    void setTitle(string title);
    void setTitleWidth(int titleWidth);
    void setTitleHeight(int titleHeight);
    void setTitleRect(SDL_Rect titleRect);

    // bar position directly(MIN_POSITION-MAX_POSITION value)
    void setPosition(int position);
    // set bar position with mouse coords
    void setPosition(Coords mouseCoords);

    const static int MIN_POSITION = 0;
    const static int MAX_POSITION = 100;

    protected:

    Renderer* renderer;
    
    // MIN_POSITION-MAX_POSITION
    int position = 100;

    SDL_Rect rect = {0, 0, 0, 0};
    int barWidth = 30;
    int barHeight = 30;
    // shift from the left edge of rectangle
    int barLineStartShift = 15;
    // shift from the right edge of rectangle
    int barLineEndShift = 15;

    bool isBackgroundTextureSet = false;
    bool isBarTextureSet = false;
    TexturesEnumeration backgroundTexture;
    TexturesEnumeration barTexture;

    SDL_Color backgroundColor = {127, 127, 127, 255};
    SDL_Color barColor = {0, 150, 0, 255};
    SDL_Color lineColor = {100, 100, 100, 255};
    SDL_Color titleColor = {255, 255, 255, 255};

    string title = "Slider";
    SDL_Rect titleRect = {0, 0, 0, 0};
    int titleWidth = 50;
    int titleHeight = 25;
};
