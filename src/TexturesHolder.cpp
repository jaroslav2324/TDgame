#include "TexturesHolder.h"

TexturesHolder::TexturesHolder(SDL_Renderer* renderer){
    this->renderer = renderer;

    // fill paths of textures
    map<TexturesEnumeration, const char*> texturesPaths;

    texturesPaths[TexturesEnumeration::BASIC_ENEMY_TEXTURE] = "../Assets/enemy.png";
    texturesPaths[TexturesEnumeration::BASIC_TOWER_TEXTURE] = "../Assets/towerSD1.jpeg";
    texturesPaths[TexturesEnumeration::ICE_TOWER_TEXTURE] = "../Assets/towerSD7.jpeg";
    texturesPaths[TexturesEnumeration::FIRE_TOWER_TEXTURE] = "../Assets/towerSD11.jpeg";
    texturesPaths[TexturesEnumeration::BASIC_PROJECTILE_TEXTURE] = "../Assets/projectile.jpg";
    texturesPaths[TexturesEnumeration::BASIC_GRID_TILE_TEXTURE] = "../Assets/tile.jpg";
    texturesPaths[TexturesEnumeration::PORTAL_TEXTURE] = "../Assets/portal.jpg";
    texturesPaths[TexturesEnumeration::BASE_TEXTURE] = "../Assets/base.jpg";
    texturesPaths[TexturesEnumeration::TEST_TEXTURE] = "../Assets/test.jpeg";
    texturesPaths[TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE] = "../Assets/white_square.jpg";
    texturesPaths[TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE] = "../Assets/dark_grey_square.png";
    texturesPaths[TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE] = "../Assets/light_grey_square.jpg";
    // add new paths here


    // if something was not loaded
    if (DEBUG_CONSOLE_OUTPUT_ON)
        for (const auto textureNum: TexturesEnumeration())
            if (texturesPaths.find(textureNum) == texturesPaths.end())
                cout << "No path was added for texture " << textureNum << endl;
  
    // load textures
    for (const auto textureNum: TexturesEnumeration())
        textures[textureNum] = IMG_LoadTexture(renderer, texturesPaths[textureNum]);
}

TexturesHolder::~TexturesHolder(){

    for (const auto textureNum: TexturesEnumeration())
        SDL_DestroyTexture(textures[textureNum]);
}

void TexturesHolder::renderTexture(TexturesEnumeration textureNum, const SDL_Rect* textureRect){
    SDL_RenderCopy(renderer, textures[textureNum], 0, textureRect);
}
