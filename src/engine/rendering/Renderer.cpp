#include "Renderer.h"

Renderer::Renderer(){

    this->window = SDL_CreateWindow("TD_Game", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // fonts
    freeSans24 = TTF_OpenFont("../data/fonts/freesans/FreeSans/FreeSans.ttf", 24);
    freeSans48 = TTF_OpenFont("../data/fonts/freesans/FreeSans/FreeSans.ttf", 48);
    freeSans64 = TTF_OpenFont("../data/fonts/freesans/FreeSans/FreeSans.ttf", 64);

    // fill paths of textures
    map<TexturesEnumeration, const char*> texturesPaths;

    //TODO create list of paths
    texturesPaths[TexturesEnumeration::BASIC_ENEMY_TEXTURE] = "../data/assets/enemy.jpeg";
    texturesPaths[TexturesEnumeration::ORC_ENEMY_TEXTURE] = "../data/assets/orc.jpeg";
    texturesPaths[TexturesEnumeration::BASIC_TOWER_TEXTURE] = "../data/assets/towers/towerSD1.jpeg";
    texturesPaths[TexturesEnumeration::ICE_TOWER_TEXTURE] = "../data/assets/towers/towerSD7.jpeg";
    texturesPaths[TexturesEnumeration::FIRE_TOWER_TEXTURE] = "../data/assets/towers/laserTower.png";
    texturesPaths[TexturesEnumeration::BASIC_PROJECTILE_TEXTURE] = "../data/assets/white_circle.png";
    texturesPaths[TexturesEnumeration::ICEBALL_PROJECTILE_TEXTURE] = "../data/assets/iceballs/iceballSD4.jpeg";
    texturesPaths[TexturesEnumeration::FIREBALL_PROJECTILE_TEXTURE] = "../data/assets/fireballs/fireballSD1.jpeg";
    texturesPaths[TexturesEnumeration::BASIC_GRID_TILE_TEXTURE] = "../data/assets/groundTiles/groundTileSD5.jpeg";
    texturesPaths[TexturesEnumeration::PORTAL_TEXTURE] = "../data/assets/portal.jpg";
    texturesPaths[TexturesEnumeration::BASE_TEXTURE] = "../data/assets/base.jpg";
    texturesPaths[TexturesEnumeration::TEST_TEXTURE] = "../data/assets/test.jpeg";
    texturesPaths[TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE] = "../data/assets/white_square.jpg";
    texturesPaths[TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE] = "../data/assets/light_grey_square.jpg";
    texturesPaths[TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE] = "../data/assets/dark_grey_square.png";
    texturesPaths[TexturesEnumeration::WHITE_CIRCLE] = "../data/assets/white_circle.png";
    // add new paths here


    // if something was not loaded
    if (DEBUG_CONSOLE_OUTPUT_ON)
        for (const auto textureNum: TexturesEnumeration())
            if (texturesPaths.find(textureNum) == texturesPaths.end())
                cout << CoutTextColors::YELLOW << "No path was added for texture " << textureNum << CoutTextColors::RESET << endl;
        
  
    // load textures
    for (const auto textureNum: TexturesEnumeration()){
        textures[textureNum] = IMG_LoadTexture(renderer, texturesPaths[textureNum]);

        if (DEBUG_CONSOLE_OUTPUT_ON)
            if (textures[textureNum] == nullptr)
                cout << CoutTextColors::RED << "Wrong path for texture " << textureNum << CoutTextColors::RESET << endl;


        if (DEBUG_CONSOLE_OUTPUT_ON)
            cout << CoutTextColors::GREEN << "Texture loaded: " << textureNum << CoutTextColors::RESET;
    }

    if (DEBUG_CONSOLE_OUTPUT_ON)
        cout << endl << endl;
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

    if (freeSans24 != nullptr){
        TTF_CloseFont(freeSans24);
        freeSans24 = nullptr;
    }
    if (freeSans48 != nullptr){
        TTF_CloseFont(freeSans48);
        freeSans48 = nullptr;
    }
    if (freeSans64 != nullptr){
        TTF_CloseFont(freeSans64);
        freeSans64 = nullptr;
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

void Renderer::renderFilledCircle(Coords center, int radius, SDL_Color& fillColor){

    SDL_SetTextureColorMod(textures[TexturesEnumeration::WHITE_CIRCLE], fillColor.r, fillColor.g, fillColor.b);
    SDL_SetTextureAlphaMod(textures[TexturesEnumeration::WHITE_CIRCLE], fillColor.a);

    int diameter = (int)(2 * radius);
    int x = (int)(center.x - radius);
    int y = (int)(center.y - radius);

    SDL_Rect rect = {x, y, diameter, diameter};
    renderTexture(TexturesEnumeration::WHITE_CIRCLE, &rect); 
}

void Renderer::renderText(const char* text, const SDL_Rect* rect, SDL_Color& color, TextSizes textSize){
    
    SDL_Surface* messageSurface = nullptr; 
    messageSurface = createTextSurface(text, color, textSize);

    SDL_Texture* messageTexture = SDL_CreateTextureFromSurface(renderer, messageSurface);
    
    SDL_RenderCopy(renderer, messageTexture, 0, rect);

    SDL_DestroyTexture(messageTexture);
    SDL_FreeSurface(messageSurface);
}

void Renderer::renderText(string& str, const SDL_Rect* rect, SDL_Color& color, TextSizes textSize){
    renderText(str.c_str(), rect, color, textSize);
}

void Renderer::renderPresent(){
    SDL_RenderPresent(renderer);
}

SDL_Surface* Renderer::createTextSurface(const char* text, SDL_Color& color, TextSizes textSize){

    SDL_Surface* textSurface = nullptr; 
    switch (textSize)
    {
    case TextSizes::s24:
        textSurface = TTF_RenderText_Blended(freeSans24, text, color);
        break;
    case TextSizes::s48:
        textSurface = TTF_RenderText_Blended(freeSans48, text, color);
        break;
    case TextSizes::s64:
        textSurface = TTF_RenderText_Blended(freeSans64, text, color);
        break;
    
    default:
        if (DEBUG_CONSOLE_OUTPUT_ON)
            cout << CoutTextColors::RED << "No loaded font with size " <<  (int)textSize << CoutTextColors::RESET << endl;
            return nullptr;
        break;
    }
    return textSurface;
}
