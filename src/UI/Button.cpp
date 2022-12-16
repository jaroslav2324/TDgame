#include "Button.h"

Button::Button(SDL_Renderer* renderer, string& btnImgPath, string& btnPressedImgPath, string& btnHoveredImgPath, Coords coords){

    Button::coords = coords;

    loadTextures(renderer, btnImgPath, btnPressedImgPath, btnHoveredImgPath);

    pressingCooldownTimer = new CountdownTimer(0);
}

Button::Button(SDL_Renderer* renderer, const char* btnImgPath, const char* btnPressedImgPath, const char* btnHoveredImgPath, Coords coords){

    Button::coords = coords;

    loadTextures(renderer, btnImgPath, btnPressedImgPath, btnHoveredImgPath);

    pressingCooldownTimer = new CountdownTimer(0);
}

Button::~Button(){
    
    if (btnTexture != nullptr){
        SDL_DestroyTexture(btnTexture);
        btnTexture = nullptr;
    }

    if (pressedBtnTexture != nullptr){
        SDL_DestroyTexture(pressedBtnTexture);
        pressedBtnTexture = nullptr;
    }

    if (hoveredBtnTexture != nullptr){
        SDL_DestroyTexture(hoveredBtnTexture);
        hoveredBtnTexture = nullptr;
    }

    if (pressingCooldownTimer != nullptr){
        delete pressingCooldownTimer;
        pressingCooldownTimer = nullptr;
    }
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

    int x = coords.x - btn_width / 2;
    int y = coords.y - btn_height / 2;
    SDL_Rect btnRect = {x, y, btn_width, btn_height};

    if (!pressingCooldownTimer->isCountdownEnd()){
        SDL_RenderCopy(renderer, pressedBtnTexture, 0, &btnRect);
        return;
    }

    switch (btnCursorInteractionMode)
    {
    case NO_INTERACTION:
        SDL_RenderCopy(renderer, btnTexture, 0, &btnRect);
        break;
    case PRESSED_ON:
        SDL_RenderCopy(renderer, pressedBtnTexture, 0, &btnRect);
        break;
    case HOVERED_OVER:
        SDL_RenderCopy(renderer, hoveredBtnTexture, 0, &btnRect);
        break;
    default:
        break;
    }
}

void Button::setModeNoCursorInteraction(){
    btnCursorInteractionMode = NO_INTERACTION;
}

void Button::setModePressedOn(){
    btnCursorInteractionMode = PRESSED_ON;
    pressingCooldownTimer->replaceTime(pressingCooldownTime);
}

void Button::setModeHoveredOver(){
    btnCursorInteractionMode = HOVERED_OVER;
}

bool Button::isPointInRect(Coords point){
    
    int x1 = coords.x - btn_width / 2;
    int y1 = coords.y - btn_height / 2;

    int x2 = coords.x + btn_width / 2;
    int y2 = coords.y + btn_height / 2;

    if (point.x < x1 || point.y < y1 || point.x >= x2 || point.y >= y2)
        return false;
    return true;
}

void Button::setWidthHeight(int width, int height){
    btn_width = width;
    btn_height = height;
}

bool Button::isPressingCooldownInactive(){
    return pressingCooldownTimer->isCountdownEnd();
}
