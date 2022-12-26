#include "Application.h"

Application::Application(){

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        cout << "SDL error" << endl;

    if (IMG_Init(IMG_INIT_JPG) == 0)
        cout << "SDL_image error" << endl;

    if (TTF_Init() != 0)
        cout << "SDL_ttf error" << endl;

    renderer = new Renderer();

    fpsTimer = new PeriodicTimer(1 / FPS * 1000);
    mainMenu = new MainMenu(fpsTimer);
}

Application::~Application(){

    if (gameLevel != nullptr){
        delete gameLevel;
        gameLevel = nullptr;
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

    TTF_Quit();
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
                            gameLevel->saveMouseClickCoords(mouseCoords);
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
                {
                    mainMenuOn = false;

                    string levelsFolderPath = "../data/levels/";
                    string levelPath;

                    switch (numChosenLevel){
                    case FIRST_LEVEL:
                        levelPath = levelsFolderPath + "level1.bin";
                        break;
                    
                    default:
                        if (DEBUG_CONSOLE_OUTPUT_ON)
                            cout << "There is no level with such number" << endl;
                        levelPath = levelsFolderPath + "level1.bin";
                        break;
                    }

                    std::ifstream levelFile;
                    levelFile.open(levelPath, std::ios::binary);
                    if (!levelFile){
                        //TODO handle
                        if (DEBUG_CONSOLE_OUTPUT_ON)
                            cout << "file with path " << levelPath << " does not exist" << endl;
                    }

                    gameLevel = new GameLevel();
                    gameLevel->loadFromBinaryFile(levelFile);

                    break;
                }

                case QUIT_TO_DESKTOP:
                {
                    quit = true;
                    break;
                }

                default:
                    break;
                }
            }

            else{  
                MenuOptionsCode code;
                code  = gameLevel->makeFrameTurn();
                gameLevel->renderAll(renderer);
                
                switch (code)
                {
                case QUIT_TO_MAIN_MENU:
                    mainMenuOn = true;
                    if (gameLevel != nullptr){
                        delete gameLevel;
                        gameLevel = nullptr;
                    }
                    
                    break;
                
                default:
                    break;
                }
                
            }

            renderer->renderPresent();
        }
	}
}
