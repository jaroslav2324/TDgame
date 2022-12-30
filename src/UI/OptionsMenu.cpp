#include "OptionsMenu.h"

OptionsMenu::OptionsMenu(){
    
    //TODO change button textures
    // TODO change button centers(height)

    toMainMenuBtn = new Button(TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE, 
                                         TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE,
                                         TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE,
                                            Coords(SCREEN_WIDTH / 2, 250));
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

void OptionsMenu::render(Renderer* renderer){

    SDL_Color color = {150, 150, 150, 255};
    SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    renderer->renderFilledRect(&rect, color);

    toMainMenuBtn->render(renderer);
}

void OptionsMenu::createButtonsVec(){
    buttonsVec.push_back(toMainMenuBtn);
}

void OptionsMenu::createButtonsReturnCodesVec(){
    buttonsReturnCodesVec.push_back(MenuOptionsCode::QUIT_TO_MAIN_MENU);
}

void OptionsMenu::saveToBinaryFile(ostream& outpustStream){
    //TODO implement
}

void OptionsMenu::loadFromBinaryFile(istream& inputStream){
    //TODO implement
}
