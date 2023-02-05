#include "LevelsMenu.h"

LevelsMenu::LevelsMenu(Renderer* renderer, SoundPlayer* soundPlayer, SystemEventsHandler* sysEventsHandler):
Interface(renderer, soundPlayer, sysEventsHandler){
    
    //TODO change button textures
    // TODO change button centers(height)

    toMainMenuBtn = new Button(Coords(150, 100), renderer, soundPlayer);
    toMainMenuBtn->setWidthHeight(200, 100);

    chooseLvl1Btn = new Button(Coords(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3), renderer, soundPlayer);
    chooseLvl1Btn->setWidthHeight(100, 100);

    chooseLvl2Btn = new Button(Coords((SCREEN_WIDTH * 2) / 3, SCREEN_HEIGHT / 3), renderer, soundPlayer);
    chooseLvl2Btn->setWidthHeight(100, 100);

    chooseLvl3Btn = new Button(Coords(SCREEN_WIDTH / 3, ((SCREEN_HEIGHT * 2) / 3)), renderer, soundPlayer);
    chooseLvl3Btn->setWidthHeight(100, 100);

    chooseLvl4Btn = new Button(Coords((SCREEN_WIDTH * 2) / 3, (SCREEN_HEIGHT * 2) / 3), renderer, soundPlayer);
    chooseLvl4Btn->setWidthHeight(100, 100);

    createButtonsVec();
    createButtonsReturnCodesVec();    
}

LevelsMenu::~LevelsMenu(){

    if (toMainMenuBtn != nullptr){
        delete toMainMenuBtn;
        toMainMenuBtn = nullptr;
    }

    if (chooseLvl1Btn != nullptr){
        delete chooseLvl1Btn;
        chooseLvl1Btn = nullptr;
    }

    if (chooseLvl2Btn != nullptr){
        delete chooseLvl2Btn;
        chooseLvl2Btn = nullptr;
    }

    if (chooseLvl3Btn != nullptr){
        delete chooseLvl3Btn;
        chooseLvl3Btn = nullptr;
    }

    if (chooseLvl4Btn != nullptr){
        delete chooseLvl4Btn;
        chooseLvl4Btn = nullptr;
    }
}

MenuOptionsCode LevelsMenu::makeFrameTurn(){

    handleHoveringOverButtons();
    return handlePressingOnButtons();
}

void LevelsMenu::render(){

    SDL_Color color = {120, 120, 150, 255};
    SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    renderer->renderFilledRect(&rect, color);

    renderButtons(renderer);
}

void LevelsMenu::createButtonsVec(){
    buttonsVec.push_back(toMainMenuBtn);
    buttonsVec.push_back(chooseLvl1Btn);
    buttonsVec.push_back(chooseLvl2Btn);
    buttonsVec.push_back(chooseLvl3Btn);
    buttonsVec.push_back(chooseLvl4Btn);
}

void LevelsMenu::createButtonsReturnCodesVec(){
    buttonsReturnCodesVec.push_back(MenuOptionsCode::QUIT_TO_MAIN_MENU);
    buttonsReturnCodesVec.push_back(MenuOptionsCode::CHOOSE_LVL1);
    buttonsReturnCodesVec.push_back(MenuOptionsCode::CHOOSE_LVL2);
    buttonsReturnCodesVec.push_back(MenuOptionsCode::CHOOSE_LVL3);
    buttonsReturnCodesVec.push_back(MenuOptionsCode::CHOOSE_LVL4);
}

