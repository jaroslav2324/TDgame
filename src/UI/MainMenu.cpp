#include "MainMenu.h"

MainMenu::MainMenu(PeriodicTimer* fpsTimer){
    this->fpsTimer = fpsTimer;
    
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

    return handleButtonClicks();
}

void MainMenu::render(Renderer* renderer){

    SDL_Color color = {150, 150, 100, 255};
    SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    renderer->renderFilledRect(&rect, color);

    startGameBtn->render(renderer);
    settingsBtn->render(renderer);
    quitBtn->render(renderer);
}

void MainMenu::saveMouseClickCoords(Coords coords){
    savedMouseClicks.push(coords);
}

MenuOptionsCode MainMenu::handleButtonClicks(){


    // check howering over buttons
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    Coords mouseCoords(mouseX, mouseY);

    // start game button
    if (startGameBtn->isPointInRect(mouseCoords))
        startGameBtn->setModeHoveredOver();
    else
        startGameBtn->setModeNoCursorInteraction();

    // settings button
    if (settingsBtn->isPointInRect(mouseCoords))
        settingsBtn->setModeHoveredOver();
    else
        settingsBtn->setModeNoCursorInteraction();

    // quit button
    if (quitBtn->isPointInRect(mouseCoords))
        quitBtn->setModeHoveredOver();
    else
        quitBtn->setModeNoCursorInteraction();


    MenuOptionsCode code = NO_CHANGES;
    // check pressing on buttons
    while(!savedMouseClicks.empty()){
        Coords mouseCoords = savedMouseClicks.front();
        savedMouseClicks.pop();

        if (startGameBtn->isPointInRect(mouseCoords)){
            startGameBtn->setModePressedOn();
            code = START_GAME;

            if (DEBUG_CONSOLE_OUTPUT_ON)
                cout << "Start game button pressed" << endl;
        }
        else if (settingsBtn->isPointInRect(mouseCoords)){
            // TODO add settings on flag
            settingsBtn->setModePressedOn();

            if (DEBUG_CONSOLE_OUTPUT_ON)
                cout << "Options button pressed" << endl;

        }
        else if (quitBtn->isPointInRect(mouseCoords)){
            quitBtn->setModePressedOn();
            code = QUIT_TO_DESKTOP;

            if (DEBUG_CONSOLE_OUTPUT_ON)
                cout << "Quit button pressed" << endl;
        }
    }

    return code;
}
