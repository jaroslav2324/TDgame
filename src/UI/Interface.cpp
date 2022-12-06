#include "Interface.h"

Interface::Interface(SDL_Renderer* renderer){

    //TODO change button textures
    buildTowerBtn = new Button(renderer, TEST_BTN_BASIC_TEXTURE_PATH, 
                                         TEST_BTN_PRESSED_TEXTURE_PATH,
                                         TEST_BTN_HOVERED_TEXTURE_PATH,
                                         Coords(300, 40));

    spawnEnemyBtn = new Button(renderer, TEST_BTN_BASIC_TEXTURE_PATH, 
                                         TEST_BTN_PRESSED_TEXTURE_PATH,
                                         TEST_BTN_HOVERED_TEXTURE_PATH,
                                         Coords(600, 40));
}

Interface::~Interface(){
    
    if (buildTowerBtn != nullptr)
        delete buildTowerBtn;

    if (spawnEnemyBtn != nullptr)
        delete spawnEnemyBtn;
}

void Interface::render(SDL_Renderer* renderer){

    SDL_SetRenderDrawColor(renderer, 150, 150, 100, 255);
    SDL_Rect rect = {0, 0, 100, SCREEN_HEIGHT};
    SDL_RenderFillRect(renderer, &rect);

    rect = {0, 0, SCREEN_WIDTH, 80};
    SDL_RenderFillRect(renderer, &rect);

    rect = {0, SCREEN_HEIGHT - 10, SCREEN_WIDTH, 10};
    SDL_RenderFillRect(renderer, &rect);

    rect = {SCREEN_WIDTH - 10, 0, 10, SCREEN_HEIGHT};
    SDL_RenderFillRect(renderer, &rect);

    // check howering ower btns
    int x, y;

    //TODO check pressing buttons

    SDL_GetMouseState(&x, &y);

    if (buildTowerBtn->isPointInRect(Coords(x, y)))
        buildTowerBtn->setModeHovered();
    else
        buildTowerBtn->setModeBasic();

    if (spawnEnemyBtn->isPointInRect(Coords(x, y)))
        spawnEnemyBtn->setModeHovered();
    else
        spawnEnemyBtn->setModeBasic();

    while(!savedMouseClicks.empty()){
        Coords mouseCoords = savedMouseClicks.front();
        savedMouseClicks.pop();
        
        if (buildTowerBtn->isPointInRect(mouseCoords))
            buildTowerBtn->setModePressed();
        if (spawnEnemyBtn->isPointInRect(mouseCoords))
            spawnEnemyBtn->setModePressed();
    }

    // then render buttons
    buildTowerBtn->render(renderer);
    spawnEnemyBtn->render(renderer);

}

void Interface::saveMouseClickCoords(Coords coords){
    savedMouseClicks.push(coords);
}