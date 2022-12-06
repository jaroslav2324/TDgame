#include "Button.h"

Button::Button(SDL_Renderer* renderer, string& btnImgPath, string& btnPressedImgPath, string& btnHoveredImgPath, Coords coords){

    Button::coords = coords;

    loadTextures(renderer, btnImgPath, btnPressedImgPath, btnHoveredImgPath);

    showPressedButtonTimer = new CountdownTimer(0);
}

Button::Button(SDL_Renderer* renderer, const char* btnImgPath, const char* btnPressedImgPath, const char* btnHoveredImgPath, Coords coords){

    Button::coords = coords;

    loadTextures(renderer, btnImgPath, btnPressedImgPath, btnHoveredImgPath);

    showPressedButtonTimer = new CountdownTimer(0);
}

Button::~Button(){
    
    if (btnTexture != nullptr)
        SDL_DestroyTexture(btnTexture);

    if (pressedBtnTexture != nullptr)
        SDL_DestroyTexture(pressedBtnTexture);

    if (hoveredBtnTexture != nullptr)
        SDL_DestroyTexture(hoveredBtnTexture);

    if (showPressedButtonTimer != nullptr)
        delete showPressedButtonTimer;
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

    int x = coords.x - BTN_WIDTH / 2;
    int y = coords.y - BTN_HEIGHT / 2;
    SDL_Rect btnRect = {x, y, BTN_WIDTH, BTN_HEIGHT};

    if (!showPressedButtonTimer->isCountdownEnd()){
        SDL_RenderCopy(renderer, pressedBtnTexture, 0, &btnRect);
        return;
    }

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
    showPressedButtonTimer->addTime(showPressedButtonTime);
}

void Button::setModeHovered(){
    currentBtnMode = HOVERED;
}

bool Button::isPointInRect(Coords point){
    
    int x1 = coords.x - BTN_WIDTH / 2;
    int y1 = coords.y - BTN_HEIGHT / 2;

    int x2 = coords.x + BTN_WIDTH / 2;
    int y2 = coords.y + BTN_HEIGHT / 2;

    if (point.x < x1 || point.y < y1 || point.x >= x2 || point.y >= y2)
        return false;
    return true;
}