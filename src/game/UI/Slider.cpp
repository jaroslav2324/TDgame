#include "Slider.h"

Slider::Slider(Renderer* renderer, SDL_Rect sliderRect, int barWidth, int barHeight){
    this->renderer = renderer;
    this->rect = sliderRect;
    this->barWidth = barWidth;
    this->barHeight = barHeight;

    titleRect = {sliderRect.x, sliderRect.y, titleWidth, titleHeight};
}

Slider::~Slider(){

}

int Slider::getBarPosition(){
    return position;
}


void Slider::setBackgroundTexture(TexturesEnumeration textureNum){
    isBackgroundTextureSet = true;
    backgroundTexture = textureNum;
}

void Slider::setBarTexture(TexturesEnumeration textureNum){
    isBarTextureSet = true;
    barTexture = textureNum;
}


void Slider::unsetBackgroundTexture(){
    isBackgroundTextureSet = false;
}

void Slider::unsetBarTexture(){
    isBarTextureSet = false;
}


void Slider::render(){

    if (isBackgroundTextureSet)
        renderer->renderTexture(backgroundTexture, &rect);
    else
        renderer->renderFilledRect(&rect, backgroundColor);

    // render line
    Coords lineStart = {(double)(rect.x + barLineStartShift), (double)(rect.y + rect.h / 2)};
    Coords lineEnd = {(double)(rect.x + rect.w - barLineEndShift), (double)(rect.y + rect.h / 2)};
    renderer->renderLine(lineStart, lineEnd, lineColor, 5);

    SDL_Rect barRect = {rect.x + (int)((double)position / MAX_POSITION * (rect.w - barLineStartShift - barLineEndShift)) - barWidth / 2 + barLineStartShift,
                        rect.y + rect.h / 2 - barHeight / 2, barWidth, barHeight};
    if (isBarTextureSet)
        renderer->renderTexture(barTexture, &barRect);
    else
        renderer->renderFilledRect(&barRect, barColor);

    renderer->renderText(title, &titleRect, titleColor);
}


bool Slider::isPointInRect(Coords point){
    
    if (point.x > rect.x && point.x < rect.x + rect.w &&
        point.y > rect.y && point.y < rect.y + rect.h)
        return true;
    return false;
}


void Slider::setRect(SDL_Rect rect){
    this->rect = rect;
}

void Slider::setWidth(int width){
    rect.w = width;
}

void Slider::setHeight(int height){
    rect.h = height;
}

void Slider::setBarWidth(int barWidth){
    this->barWidth = barWidth;
}

void Slider::setBarHeight(int barHeight){
    this->barHeight = barHeight;
}

void Slider::setBackgroundColor(SDL_Color color){
    backgroundColor = color;
}

void Slider::setBarColor(SDL_Color color){
    barColor = color;
}

void Slider::setLineColor(SDL_Color color){
    lineColor = color;
}

void Slider::setTitle(string title){
    this->title = title;
}

void Slider::setTitleWidth(int titleWidth){
    this->titleWidth = titleWidth;
    titleRect.w = titleWidth;
}

void Slider::setTitleHeight(int titleHeight){
    this->titleHeight = titleHeight;
    titleRect.h = titleHeight;
}

void Slider::setTitleRect(SDL_Rect titleRect){
    this->titleRect = titleRect;
    titleWidth = titleRect.w;
    titleHeight = titleRect.h;
}

void Slider::setPosition(int position){

    if (position < MIN_POSITION || position > MAX_POSITION)
        if (DEBUG_CONSOLE_OUTPUT_ON){
            cout << CoutTextColors::RED << "Wrong slider position used" << endl << CoutTextColors::RESET;
            this->position = 0;
            return;
        }
    //cout << "Position " << position << endl;
    this->position = position;
}

void Slider::setPosition(Coords mouseCoords){

    if (mouseCoords.x < rect.x + barLineStartShift || mouseCoords.x > rect.x + rect.w - barLineEndShift)
        return;

    int x = mouseCoords.x - rect.x - barLineStartShift;
    setPosition(x * 100 / (rect.w - barLineStartShift - barLineEndShift));
}

void Slider::setMovingAfterMouse(){
    moveAfterMouseCursor = true;
}

void Slider::unsetMovingAfterMouse(){
    moveAfterMouseCursor = false;
}

bool Slider::isMovingAfterMouse(){
    return moveAfterMouseCursor;
}
