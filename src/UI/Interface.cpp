#include "Interface.h"

Interface::Interface(SDL_Renderer* renderer){

    //TODO change button textures
    buildTowerBtn = new Button(renderer, TEST_BTN_BASIC_TEXTURE_PATH, 
                                         TEST_BTN_PRESSED_TEXTURE_PATH,
                                         TEST_BTN_HOVERED_TEXTURE_PATH,
                                         std::make_pair(300, 500));
    spawnEnemyBtn = new Button(renderer, TEST_BTN_BASIC_TEXTURE_PATH, 
                                         TEST_BTN_PRESSED_TEXTURE_PATH,
                                         TEST_BTN_HOVERED_TEXTURE_PATH,
                                         std::make_pair(600, 500));
}

Interface::~Interface(){
    
    if (buildTowerBtn != nullptr)
        delete buildTowerBtn;

    if (spawnEnemyBtn != nullptr)
        delete spawnEnemyBtn;
}

void Interface::render(SDL_Renderer* renderer){

    //TODO render back interface textures

    // check howering ower btns
    int x, y;

    SDL_GetMouseState(&x, &y);

    if (buildTowerBtn->isPointInRect(std::make_pair(x, y)))
        buildTowerBtn->setModeHovered();
    else
        buildTowerBtn->setModeBasic();

    if (spawnEnemyBtn->isPointInRect(std::make_pair(x, y)))
        spawnEnemyBtn->setModeHovered();
    else
        spawnEnemyBtn->setModeBasic();

    // then render buttons
    buildTowerBtn->render(renderer);
    spawnEnemyBtn->render(renderer);

}