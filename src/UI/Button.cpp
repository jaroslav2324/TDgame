#include "Button.h"

Button::Button(TexturesEnumeration textureNoInteraction, TexturesEnumeration textureHoveredOver, TexturesEnumeration texturePressedOn, Coords coords){

    Button::coords = coords;

    this->textureNoInteraction = textureNoInteraction;
    this->textureHoveredOver = textureHoveredOver;
    this->texturePressedOn = texturePressedOn;

    pressingCooldownTimer = new CountdownTimer(0);
}

Button::~Button(){

    if (pressingCooldownTimer != nullptr){
        delete pressingCooldownTimer;
        pressingCooldownTimer = nullptr;
    }
}

void Button::render(TexturesHolder* texturesHolder){

    int x = coords.x - btn_width / 2;
    int y = coords.y - btn_height / 2;
    SDL_Rect btnRect = {x, y, btn_width, btn_height};

    if (!pressingCooldownTimer->isCountdownEnd()){
        texturesHolder->renderTexture(texturePressedOn, &btnRect);
        return;
    }

    switch (btnCursorInteractionMode)
    {
    case NO_INTERACTION:
        texturesHolder->renderTexture(textureNoInteraction, &btnRect);
        break;
    case PRESSED_ON:
        texturesHolder->renderTexture(texturePressedOn, &btnRect);
        break;
    case HOVERED_OVER:
    texturesHolder->renderTexture(textureHoveredOver, &btnRect);
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
