#pragma once

#include <iostream>
#include <string>
#include <map>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include "settings.h"
#include "Coords.h"
#include "TexturesEnum.h"

using std::map;
using std::string;
using std::cout;
using std::endl;

class Renderer{

    public:
    Renderer();
    ~Renderer();

    void renderPresent();
    void renderTexture(TexturesEnumeration textureNum, const SDL_Rect* textureRect);
    void renderRect(const SDL_Rect* rect, SDL_Color& color);
    void renderFilledRect(const SDL_Rect* rect, SDL_Color& color);
    void renderLine(Coords& point1, Coords& point2, SDL_Color& color);
    void renderCircle(Coords& center, int radius, SDL_Color& color, int borderWidth = 1);
    void renderText(const char* text, const SDL_Rect* rect, SDL_Color& color);
    void renderText(string& str, const SDL_Rect* rect, SDL_Color& color);

    private:

    SDL_Renderer * renderer = nullptr;
    SDL_Window* window =  nullptr;

    map<TexturesEnumeration, SDL_Texture*> textures;

    TTF_Font* freeSans = nullptr;
};
