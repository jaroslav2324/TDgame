#include "OptionsMenu.h"

OptionsMenu::OptionsMenu(Renderer* renderer, SoundPlayer* soundPlayer){

    this->renderer = renderer;
    this->soundPlayer = soundPlayer;
    
    //TODO change button textures
    // TODO change button centers(height)

    toMainMenuBtn = new Button(Coords(SCREEN_WIDTH / 2, 250), renderer, soundPlayer);
    toMainMenuBtn->setWidthHeight(500, 200);

    createButtonsVec();
    createButtonsReturnCodesVec();    
}

OptionsMenu::~OptionsMenu(){

    if (toMainMenuBtn != nullptr){
        delete toMainMenuBtn;
        toMainMenuBtn = nullptr;
    }
}

MenuOptionsCode OptionsMenu::makeFrameTurn(){

    handleHoveringOverButtons();
    return handlePressingOnButtons();
}

void OptionsMenu::render(){

    SDL_Color color = {150, 150, 150, 255};
    SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    renderer->renderFilledRect(&rect, color);

    renderButtons(renderer);
}

void OptionsMenu::createButtonsVec(){
    buttonsVec.push_back(toMainMenuBtn);
}

void OptionsMenu::createButtonsReturnCodesVec(){
    buttonsReturnCodesVec.push_back(MenuOptionsCode::QUIT_TO_MAIN_MENU);
}

