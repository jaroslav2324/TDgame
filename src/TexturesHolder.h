#pragma once

#include <iostream>
#include <string>
#include <map>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

#include "settings.h"
#include "TexturesEnum.h"

using std::map;
using std::string;
using std::cout;
using std::endl;

class TexturesHolder{

    public:
    TexturesHolder(SDL_Renderer* renderer);
    ~TexturesHolder();

    void renderTexture(TexturesEnumeration textureNum, const SDL_Rect* textureRect);

    private:

    SDL_Renderer * renderer = nullptr;

    map<TexturesEnumeration, SDL_Texture*> textures;
};
