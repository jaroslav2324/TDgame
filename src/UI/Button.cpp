#include "Button.h"

Button::Button(SDL_Renderer* renderer, string& btnImgPath, string& btnPressedImgPath, string& btnHoveredImgPath, std::pair<float, float> coords){

    Button::coords = coords;

    loadTextures(renderer, btnImgPath, btnPressedImgPath, btnHoveredImgPath);
}

Button::Button(SDL_Renderer* renderer, const char* btnImgPath, const char* btnPressedImgPath, const char* btnHoveredImgPath, std::pair<float, float> coords){

    Button::coords = coords;

    loadTextures(renderer, btnImgPath, btnPressedImgPath, btnHoveredImgPath);
}

Button::~Button(){
    
    if (btnTexture != nullptr)
        SDL_DestroyTexture(btnTexture);

    if (pressedBtnTexture != nullptr)
        SDL_DestroyTexture(pressedBtnTexture);

    if (hoveredBtnTexture != nullptr)
        SDL_DestroyTexture(hoveredBtnTexture);
}

void Button::loadTextures(SDL_Renderer* renderer, string& btnImgPath, string& btnPressedImgPath, string& btnHoveredImgPath){

        if (btnTexture == nullptr)
        btnTexture = IMG_LoadTexture(renderer, btnImgPath.c_str());
    else{
        SDL_DestroyTexture(btnTexture);
        btnTexture = IMG_LoadTexture(renderer, btnImgPath.c_str());
    }  
        if (pressedBtnTexture == nullptr)
        pressedBtnTexture = IMG_LoadTexture(renderer, btnPressedImgPath.c_str());
    else{
        SDL_DestroyTexture(pressedBtnTexture);
        pressedBtnTexture = IMG_LoadTexture(renderer, btnPressedImgPath.c_str());
    }  
        if (hoveredBtnTexture == nullptr)
        hoveredBtnTexture = IMG_LoadTexture(renderer, btnHoveredImgPath.c_str());
    else{
        SDL_DestroyTexture(hoveredBtnTexture);
        hoveredBtnTexture = IMG_LoadTexture(renderer, btnHoveredImgPath.c_str());
    }  
}

void Button::loadTextures(SDL_Renderer* renderer, const char* btnImgPath, const char* btnPressedImgPath, const char* btnHoveredImgPath){

        if (btnTexture == nullptr)
        btnTexture = IMG_LoadTexture(renderer, btnImgPath);
    else{
        SDL_DestroyTexture(btnTexture);
        btnTexture = IMG_LoadTexture(renderer, btnImgPath);
    }  
        if (pressedBtnTexture == nullptr)
        pressedBtnTexture = IMG_LoadTexture(renderer, btnPressedImgPath);
    else{
        SDL_DestroyTexture(pressedBtnTexture);
        pressedBtnTexture = IMG_LoadTexture(renderer, btnPressedImgPath);
    }  
        if (hoveredBtnTexture == nullptr)
        hoveredBtnTexture = IMG_LoadTexture(renderer, btnHoveredImgPath);
    else{
        SDL_DestroyTexture(hoveredBtnTexture);
        hoveredBtnTexture = IMG_LoadTexture(renderer, btnHoveredImgPath);
    }  
}

void Button::render(SDL_Renderer* renderer){

    int x = coords.first - BTN_WIDTH / 2;
    int y = coords.second - BTN_HEIGHT / 2;
    SDL_Rect btnRect = {x, y, BTN_WIDTH, BTN_HEIGHT};

    switch (currentBtnMode)
    {
    case BASIC:
        SDL_RenderCopy(renderer, btnTexture, 0, &btnRect);
        break;
    case PRESSED:
        SDL_RenderCopy(renderer, pressedBtnTexture, 0, &btnRect);
        break;
    case HOVERED:
        SDL_RenderCopy(renderer, hoveredBtnTexture, 0, &btnRect);
        break;
    default:
        break;
    }
}

void Button::setModeBasic(){
    currentBtnMode = BASIC;
}

void Button::setModePressed(){
    currentBtnMode = PRESSED;
}

void Button::setModeHovered(){
    currentBtnMode = HOVERED;
}

void Button::setRecentlyPressedFlag(){
    buttonRecentlyPressed = true;
}

bool Button::isPointInRect(std::pair<int, int> point){
    
    int x1 = coords.first - BTN_WIDTH / 2;
    int y1 = coords.second - BTN_HEIGHT / 2;

    int x2 = coords.first + BTN_WIDTH / 2;
    int y2 = coords.second + BTN_HEIGHT / 2;

    if (point.first < x1 || point.second < y1 || point.first >= x2 || point.second >= y2)
        return false;
    return true;
}

