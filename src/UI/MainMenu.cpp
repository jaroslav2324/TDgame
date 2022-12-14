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

    void MainMenu::loop(SDL_Renderer* renderer){

        bool quit = false;
    // int cnt = 0;

    while (!quit){

        // handle events
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_QUIT:    
                    quit = true;        
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT){
                        int x, y;
                        SDL_GetMouseState(&x, &y);
                        saveMouseClickCoords(Coords(x, y));
                    }      
            }
        }

        if (fpsTimer->tickIfNeeded()){
        // cout << cnt << endl;
        // cnt++;
            render(renderer);
            SDL_RenderPresent(renderer);
        }
	}


    }

void MainMenu::render(SDL_Renderer* renderer){

    SDL_SetRenderDrawColor(renderer, 150, 150, 100, 255);
    SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderFillRect(renderer, &rect);


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


    // check pressing on buttons
    while(!savedMouseClicks.empty()){
        Coords mouseCoords = savedMouseClicks.front();
        savedMouseClicks.pop();

        if (startGameBtn->isPointInRect(mouseCoords)){
            startGameBtn->setModePressed();
            
        }
        else if (settingsBtn->isPointInRect(mouseCoords)){
            settingsBtn->setModePressed();

        }
        else if (quitBtn->isPointInRect(mouseCoords)){
            quitBtn->setModePressed();

        }
    }

    startGameBtn->render(renderer);
    settingsBtn->render(renderer);
    quitBtn->render(renderer);
}

void MainMenu::saveMouseClickCoords(Coords coords){
    savedMouseClicks.push(coords);
}
