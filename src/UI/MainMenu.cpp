#include "MainMenu.h"

MainMenu::MainMenu(){
    
    //TODO change button textures
    // TODO change button centers(height)
    startGameBtn = new Button(TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE, 
                                         TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE,
                                         TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE,
                                            Coords(SCREEN_WIDTH / 2, 150));
    startGameBtn->setWidthHeight(500, 200);
                                    

    settingsBtn = new Button(TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE, 
                                         TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE,
                                         TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE,
                                            Coords(SCREEN_WIDTH / 2, 450));
    settingsBtn->setWidthHeight(500, 200);

    quitBtn = new Button(TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE, 
                                         TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE,
                                         TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE,
                                            Coords(SCREEN_WIDTH / 2, 750));
    quitBtn->setWidthHeight(500, 200);

    createButtonsVec();
    createButtonsReturnCodesVec();    
}

    MainMenu::~MainMenu(){

        if (startGameBtn != nullptr){
            delete startGameBtn;
            startGameBtn = nullptr;
        }

        if (settingsBtn != nullptr){
            delete settingsBtn;
            settingsBtn = nullptr;
        }

        if (quitBtn != nullptr){
            delete quitBtn;
            quitBtn = nullptr;
        }
    }

MenuOptionsCode MainMenu::makeFrameTurn(){

    handleHoveringOverButtons();
    return handlePressingOnButtons();
}

void MainMenu::render(Renderer* renderer){

    SDL_Color color = {150, 150, 100, 255};
    SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    renderer->renderFilledRect(&rect, color);

    renderButtons(renderer);
}

void MainMenu::createButtonsVec(){
    buttonsVec.push_back(startGameBtn);
    buttonsVec.push_back(settingsBtn);
    buttonsVec.push_back(quitBtn);
}

void MainMenu::createButtonsReturnCodesVec(){
    buttonsReturnCodesVec.push_back(MenuOptionsCode::OPEN_CHOOSE_LEVEL_MENU);
    buttonsReturnCodesVec.push_back(MenuOptionsCode::OPEN_OPTIONS);
    buttonsReturnCodesVec.push_back(MenuOptionsCode::QUIT_TO_DESKTOP);
}

void MainMenu::saveToBinaryFile(ostream& outpustStream){
    //TODO implement
}

void MainMenu::loadFromBinaryFile(istream& inputStream){
    //TODO implement
}
