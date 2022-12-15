#include "MainMenu.h"

MainMenu::MainMenu(SDL_Renderer* renderer, PeriodicTimer* fpsTimer){
    this->fpsTimer = fpsTimer;
    
    //TODO change button textures
    // TODO change button centers(height)
    startGameBtn = new Button(renderer, TEST_BTN_BASIC_TEXTURE_PATH, 
                                            TEST_BTN_PRESSED_TEXTURE_PATH,
                                            TEST_BTN_HOVERED_TEXTURE_PATH,
                                            Coords(SCREEN_WIDTH / 2, 150));
    startGameBtn->setWidthHeight(500, 200);
                                    

    settingsBtn = new Button(renderer, TEST_BTN_BASIC_TEXTURE_PATH, 
                                            TEST_BTN_PRESSED_TEXTURE_PATH,
                                            TEST_BTN_HOVERED_TEXTURE_PATH,
                                            Coords(SCREEN_WIDTH / 2, 450));
    settingsBtn->setWidthHeight(500, 200);

    quitBtn = new Button(renderer, TEST_BTN_BASIC_TEXTURE_PATH, 
                                            TEST_BTN_PRESSED_TEXTURE_PATH,
                                            TEST_BTN_HOVERED_TEXTURE_PATH,
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

void MainMenu::render(SDL_Renderer* renderer){

    SDL_SetRenderDrawColor(renderer, 150, 150, 100, 255);
    SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderFillRect(renderer, &rect);

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
        startGameBtn->setModeHovered();
    else
        startGameBtn->setModeBasic();

    // settings button
    if (settingsBtn->isPointInRect(mouseCoords))
        settingsBtn->setModeHovered();
    else
        settingsBtn->setModeBasic();

    // quit button
    if (quitBtn->isPointInRect(mouseCoords))
        quitBtn->setModeHovered();
    else
        quitBtn->setModeBasic();


    MenuOptionsCode code = NO_CHANGES;
    // check pressing on buttons
    while(!savedMouseClicks.empty()){
        Coords mouseCoords = savedMouseClicks.front();
        savedMouseClicks.pop();

        if (startGameBtn->isPointInRect(mouseCoords)){
            startGameBtn->setModePressed();
            code = START_GAME;

            if (DEBUG_CONSOLE_OUTPUT_ON)
                cout << "Start game button pressed" << endl;
        }
        else if (settingsBtn->isPointInRect(mouseCoords)){
            // TODO add settings on flag
            settingsBtn->setModePressed();

            if (DEBUG_CONSOLE_OUTPUT_ON)
                cout << "Options button pressed" << endl;

        }
        else if (quitBtn->isPointInRect(mouseCoords)){
            quitBtn->setModePressed();
            code = QUIT_TO_DESKTOP;

            if (DEBUG_CONSOLE_OUTPUT_ON)
                cout << "Quit button pressed" << endl;
        }
    }

    return code;
}
