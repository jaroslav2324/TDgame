#include "Renderer.h"

Renderer::Renderer(){

    this->window = SDL_CreateWindow("TD_Game", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    this->renderer = renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // fonts
    freeSans = TTF_OpenFont("../data/fonts/freesans/FreeSans/FreeSans.ttf", 24);

    // fill paths of textures
    map<TexturesEnumeration, const char*> texturesPaths;

    texturesPaths[TexturesEnumeration::BASIC_ENEMY_TEXTURE] = "../data/assets/enemy.png";
    texturesPaths[TexturesEnumeration::ORC_ENEMY_TEXTURE] = "../data/assets/orc.jpeg";
    texturesPaths[TexturesEnumeration::BASIC_TOWER_TEXTURE] = "../data/assets/towers/towerSD1.jpeg";
    texturesPaths[TexturesEnumeration::ICE_TOWER_TEXTURE] = "../data/assets/towers/towerSD7.jpeg";
    texturesPaths[TexturesEnumeration::FIRE_TOWER_TEXTURE] = "../data/assets/towers/towerSD11.jpeg";
    texturesPaths[TexturesEnumeration::BASIC_PROJECTILE_TEXTURE] = "../data/assets/projectile.jpg";
    texturesPaths[TexturesEnumeration::ICEBALL_PROJECTILE_TEXTURE] = "../data/assets/iceballs/iceballSD4.jpeg";
    texturesPaths[TexturesEnumeration::FIREBALL_PROJECTILE_TEXTURE] = "../data/assets/fireballs/fireballSD1.jpeg";
    texturesPaths[TexturesEnumeration::BASIC_GRID_TILE_TEXTURE] = "../data/assets/groundTiles/groundTileSD5.jpeg";
    texturesPaths[TexturesEnumeration::PORTAL_TEXTURE] = "../data/assets/portal.jpg";
    texturesPaths[TexturesEnumeration::BASE_TEXTURE] = "../data/assets/base.jpg";
    texturesPaths[TexturesEnumeration::TEST_TEXTURE] = "../data/assets/test.jpeg";
    texturesPaths[TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE] = "../data/assets/white_square.jpg";
    texturesPaths[TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE] = "../data/assets/dark_grey_square.png";
    texturesPaths[TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE] = "../data/assets/light_grey_square.jpg";
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

void Renderer::renderRect(const SDL_Rect* rect, SDL_Color& color){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawRect(renderer, rect);
}

void Renderer::renderLine(Coords& point1, Coords& point2, SDL_Color& color, int width){
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    if (width == 1){
    SDL_RenderDrawLine(renderer, point1.x, point1.y, point2.x, point2.y);
    return;
    }

    Line centralLine(point1, point2);
    Line perpendicularLine = getPerpendicularLine(centralLine);

    double startPointX;
    double startPointY;
    double endPointX;
    double endPointY;

    double diffX = abs(point2.x - point1.x);
    double diffY = abs(point2.y - point1.y);

    //TODO change algorythm
    if (diffX < diffY){

        for (int i = 0 ; i < width; i++){
            startPointX = point1.x - width / 2 + i;
            startPointY = perpendicularLine.findY(startPointX);

            endPointX = startPointX + centralLine.guidingVector.a;
            endPointY = startPointY + centralLine.guidingVector.b;

            SDL_RenderDrawLine(renderer, startPointX, startPointY, endPointX, endPointY);

            // this to reduce empty spaces in diagonal lines
            startPointX++;
            endPointX = startPointX + centralLine.guidingVector.a;

            SDL_RenderDrawLine(renderer, startPointX, startPointY, endPointX, endPointY);
        }
    }
    else{

        for (int i = 0 ; i < width; i++){
            startPointY = point1.y - width / 2 + i;
            startPointX = perpendicularLine.findX(startPointY);

            endPointX = startPointX + centralLine.guidingVector.a;
            endPointY = startPointY + centralLine.guidingVector.b;

            SDL_RenderDrawLine(renderer, startPointX, startPointY, endPointX, endPointY);

            // this to reduce empty spaces in diagonal lines
            startPointY++;
            endPointY = startPointY + centralLine.guidingVector.b;

            SDL_RenderDrawLine(renderer, startPointX, startPointY, endPointX, endPointY);
        }
    }
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
