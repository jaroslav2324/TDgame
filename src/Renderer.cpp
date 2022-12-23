#include "Renderer.h"

Renderer::Renderer(){

    this->window = SDL_CreateWindow("TD_Game", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    this->renderer = renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // fonts
    freeSans = TTF_OpenFont("../fonts/freesans/FreeSans/FreeSans.ttf", 24);

    // fill paths of textures
    map<TexturesEnumeration, const char*> texturesPaths;

    texturesPaths[TexturesEnumeration::BASIC_ENEMY_TEXTURE] = "../Assets/enemy.png";
    texturesPaths[TexturesEnumeration::ORC_ENEMY_TEXTURE] = "../Assets/orc.jpeg";
    texturesPaths[TexturesEnumeration::BASIC_TOWER_TEXTURE] = "../Assets/towers/towerSD1.jpeg";
    texturesPaths[TexturesEnumeration::ICE_TOWER_TEXTURE] = "../Assets/towers/towerSD7.jpeg";
    texturesPaths[TexturesEnumeration::FIRE_TOWER_TEXTURE] = "../Assets/towers/towerSD11.jpeg";
    texturesPaths[TexturesEnumeration::BASIC_PROJECTILE_TEXTURE] = "../Assets/projectile.jpg";
    texturesPaths[TexturesEnumeration::ICEBALL_PROJECTILE_TEXTURE] = "../Assets/iceballs/iceballSD4.jpeg";
    texturesPaths[TexturesEnumeration::FIREBALL_PROJECTILE_TEXTURE] = "../Assets/fireballs/fireballSD1.jpeg";
    texturesPaths[TexturesEnumeration::BASIC_GRID_TILE_TEXTURE] = "../Assets/groundTiles/groundTileSD5.jpeg";
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

Renderer::~Renderer(){

    for (const auto textureNum: TexturesEnumeration())
        SDL_DestroyTexture(textures[textureNum]);
    
    if (renderer != nullptr){
        SDL_DestroyRenderer(renderer);
        renderer = nullptr;
    }

    if (window != nullptr){
        SDL_DestroyWindow(window);
        window = nullptr;
    }

    if (freeSans != nullptr){
        TTF_CloseFont(freeSans);
        freeSans = nullptr;
    }
}

void Renderer::renderTexture(TexturesEnumeration textureNum, const SDL_Rect* textureRect){
    SDL_RenderCopy(renderer, textures[textureNum], 0, textureRect);
}

void Renderer::renderFilledRect(const SDL_Rect* rect, SDL_Color& color){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderFillRect(renderer, rect);
}

void Renderer::renderLine(Coords& point1, Coords& point2, SDL_Color& color){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, point1.x, point1.y, point2.x, point2.y);
}

void Renderer::renderCircle(Coords& center, int radius, SDL_Color& color, int borderWidth){

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    int centerX = center.x;
    int centerY = center.y;

    for (int circleNum = 0; circleNum < borderWidth; circleNum++, radius++){
        int diameter = (radius * 2);

        int x = (radius - 1);
        int y = 0;

        int tx = 1;
        int ty = 1;
        int error = (tx - diameter);

        while (x >= y)
        {
            //  Each of the following renders an octant of the circle
            SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
            SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
            SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
            SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
            SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
            SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
            SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
            SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);

            if (error <= 0)
            {
                ++y;
                error += ty;
                ty += 2;
            }

            if (error > 0)
            {
                --x;
                tx += 2;
                error += (tx - diameter);
            }
        }
    }
}

void Renderer::renderText(const char* text, const SDL_Rect* rect, SDL_Color& color){
    
    SDL_Surface* messageSurface = TTF_RenderText_Blended(freeSans, text, color);
    SDL_Texture* messageTexture = SDL_CreateTextureFromSurface(renderer, messageSurface);
    
    SDL_RenderCopy(renderer, messageTexture, 0, rect);

    SDL_DestroyTexture(messageTexture);
    SDL_FreeSurface(messageSurface);
}

void Renderer::renderText(string& str, const SDL_Rect* rect, SDL_Color& color){
    renderText(str.c_str(), rect, color);
}

void Renderer::renderPresent(){
    SDL_RenderPresent(renderer);
}
