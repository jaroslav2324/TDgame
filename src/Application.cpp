#include "Application.h"

Application::Application(){

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        cout << "SDL error" << endl;

    if (IMG_Init(IMG_INIT_JPG) == 0)
        cout << "SDL_image error" << endl;

    renderer = new Renderer();

    fpsTimer = new PeriodicTimer(1 / FPS * 1000);
    mainMenu = new MainMenu(fpsTimer);
    game = new Game();
}

Application::~Application(){

    if (game != nullptr){
        delete game;
        game = nullptr;
    }

    if (mainMenu != nullptr){
        delete mainMenu;
        mainMenu = nullptr;
    }

    if (fpsTimer != nullptr){
        delete fpsTimer;
        fpsTimer = nullptr;
    }

    if (renderer != nullptr){
        delete renderer;
        renderer = nullptr;
    }

	IMG_Quit();
    SDL_Quit();
}

void Application::loop(){

    

    bool quit = false;

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
                        Coords mouseCoords(x, y);

                        if (DEBUG_CONSOLE_OUTPUT_ON)
                            cout << "Mouse click registered at " << mouseCoords;
                        
                        if (mainMenuOn)
                            mainMenu->saveMouseClickCoords(mouseCoords);
                        else
                            game->saveMouseClickCoords(mouseCoords);
                    }      
            }
        }

        if (fpsTimer->tickIfNeeded()){

            if (mainMenuOn){

                MenuOptionsCode code;
                code = mainMenu->makeFrameTurn();
                mainMenu->render(renderer);

                switch (code){

                case START_GAME:
                    mainMenuOn = false;
                    break;

                case QUIT_TO_DESKTOP:
                    quit = true;
                    break;

                default:
                    break;
                }
            }

            else{  
                MenuOptionsCode code;
                code  = game->makeFrameTurn();
                game->renderAll(renderer);
                
                // switch (code)
                
            }

            renderer->renderPresent();
        }
	}
}
