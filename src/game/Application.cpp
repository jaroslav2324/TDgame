#include "Application.h"

Application::Application(){

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
        cout << "SDL error" << endl;

    if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) == 0)
        cout << "SDL_image error" << endl;

    if (TTF_Init() != 0)
        cout << "SDL_ttf error" << endl;

    if (Mix_Init(MIX_INIT_MP3) == 0)
        cout << "SDL_mixer error" << endl;

    renderer = new Renderer();
    soundPlayer = new SoundPlayer();
    systemEventsHandler = new SystemEventsHandler();

    fpsTimer = new PeriodicTimer(1 / FPS * 1000);

    mainMenu = new MainMenu(renderer, soundPlayer);
    optionsMenu = new OptionsMenu(renderer, soundPlayer);
    levelsMenu = new LevelsMenu(renderer, soundPlayer);
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

    if (optionsMenu != nullptr){
        delete optionsMenu;
        optionsMenu = nullptr;
    }

    if (levelsMenu != nullptr){
        delete levelsMenu;
        levelsMenu = nullptr;
    }

    if (fpsTimer != nullptr){
        delete fpsTimer;
        fpsTimer = nullptr;
    }

    if (renderer != nullptr){
        delete renderer;
        renderer = nullptr;
    }

    if (soundPlayer != nullptr){
        delete soundPlayer;
        soundPlayer = nullptr;
    }

    if (systemEventsHandler != nullptr){
        delete systemEventsHandler;
        systemEventsHandler = nullptr;
    }

    Mix_CloseAudio();
    Mix_Quit();
    TTF_Quit();
	IMG_Quit();
    SDL_Quit();
}

void Application::loop(){ 

    int fpsCount = 0;
    // counts each second
    PeriodicTimer fpsCounterTimer(1000);
    MenuOptionsCode code;

    while (!quitApp){

        handleEvents();

        if (fpsTimer->tickIfNeeded()){

            fpsCount++;

            if (activeSceneCode == ActiveScenesCodes::MAIN_MENU){

                code = mainMenu->makeFrameTurn();
                mainMenu->render();

                switch (code){

                case OPEN_CHOOSE_LEVEL_MENU:
                {
                    activeSceneCode = ActiveScenesCodes::CHOOSE_LEVEL_MENU;
                    break;
                }

                case OPEN_OPTIONS:
                {
                    activeSceneCode = ActiveScenesCodes::OPTIONS_MENU;
                    break;
                }

                case QUIT_TO_DESKTOP:
                {
                    quitApp = true;
                    break;
                }

                default:
                    break;
                }
            }

            else if (activeSceneCode == ActiveScenesCodes::OPTIONS_MENU){

                code  = optionsMenu->makeFrameTurn();
                optionsMenu->render();
                
                switch (code){

                case QUIT_TO_MAIN_MENU:
                {
                    activeSceneCode = ActiveScenesCodes::MAIN_MENU;                    
                    break;
                }
                
                default:
                    break;
                }
            }

            else if (activeSceneCode == ActiveScenesCodes::GAME_LEVEL){  

                code  = gameLevel->makeFrameTurn();
                gameLevel->renderAll(renderer);
                
                switch (code){

                case QUIT_TO_MAIN_MENU:

                    activeSceneCode = ActiveScenesCodes::MAIN_MENU;
                    unloadLevel();
                    break;
                
                default:
                    break;
                }
            }

            else if (activeSceneCode == ActiveScenesCodes::CHOOSE_LEVEL_MENU){

                code = levelsMenu->makeFrameTurn();
                levelsMenu->render();

                switch (code)
                {
                case NO_CHANGES:
                    break;
                case QUIT_TO_MAIN_MENU:
                    
                    activeSceneCode = ActiveScenesCodes::MAIN_MENU;
                    break;
                
                case CHOOSE_LVL1:
                case CHOOSE_LVL2:
                case CHOOSE_LVL3:
                case CHOOSE_LVL4:
                    setChosenLevel(code);
                    loadChosenLevel();
                    activeSceneCode = ActiveScenesCodes::GAME_LEVEL;
                    break;

                default:
                    if (DEBUG_CONSOLE_OUTPUT_ON){
                        cout << CoutTextColors::RED;
                        cout << "No case for option " << code << " in choose level menu" << endl;
                        cout << CoutTextColors::RESET;
                    }
                    break;
                }
            }

            renderer->renderPresent();
        }

        if (fpsCounterTimer.tickIfNeeded()){
            if (DEBUG_CONSOLE_OUTPUT_ON && DEBUG_OUTPUT_FPS)
                cout << "FPS: " << fpsCount << endl;
            fpsCount = 0;
        }
	}
}

void Application::handleEvents(){

    systemEventsHandler->handleSystemEvents();

    GameEvent event(GameEventType::UNDEFINED_GAME_EVENT);

    while(systemEventsHandler->popGameEvent(&event)){

        switch (event.eventType)
        {
        case GameEventType::w_PRESSED:

            //TODO remove
            cout << "w pressed" << endl;
            break;

        case GameEventType::QUIT_GAME:
            quitApp = true;
            break;

        case GameEventType::MOUSE_LEFT_BTN_PRESSED:
        {
            //TODO move coords saving to systemEventsHandler
            int x, y;
            SDL_GetMouseState(&x, &y);
            Coords mouseCoords(x, y);

            if (DEBUG_CONSOLE_OUTPUT_ON && DEBUG_OUTPUT_MOUSE_CLICKS)
                cout << "Mouse click registered at " << mouseCoords;
            
            if (activeSceneCode == ActiveScenesCodes::MAIN_MENU)
                mainMenu->saveMouseClickCoords(mouseCoords);
            else if (activeSceneCode == ActiveScenesCodes::OPTIONS_MENU)
                optionsMenu->saveMouseClickCoords(mouseCoords);
            else if (activeSceneCode == ActiveScenesCodes::CHOOSE_LEVEL_MENU)
                levelsMenu->saveMouseClickCoords(mouseCoords);
            else if (activeSceneCode == ActiveScenesCodes::GAME_LEVEL)
                gameLevel->saveMouseClickCoords(mouseCoords);
        }
            break;
        default:
        
            //TODO
            cout << "Udefined game event" << endl;
            break;
        }
    }

        // SDL_Event event;
        // while(SDL_PollEvent(&event)){
        //     switch (event.type) {
        //         case SDL_QUIT:    
        //             quitApp = true;        
        //             break;
        //         case SDL_MOUSEBUTTONDOWN:
        //             if (event.button.button == SDL_BUTTON_LEFT){

        //                 int x, y;
        //                 SDL_GetMouseState(&x, &y);
        //                 Coords mouseCoords(x, y);

        //                 if (DEBUG_CONSOLE_OUTPUT_ON && DEBUG_OUTPUT_MOUSE_CLICKS)
        //                     cout << "Mouse click registered at " << mouseCoords;
                        
        //                 if (activeSceneCode == ActiveScenesCodes::MAIN_MENU)
        //                     mainMenu->saveMouseClickCoords(mouseCoords);
        //                 else if (activeSceneCode == ActiveScenesCodes::OPTIONS_MENU)
        //                     optionsMenu->saveMouseClickCoords(mouseCoords);
        //                 else if (activeSceneCode == ActiveScenesCodes::CHOOSE_LEVEL_MENU)
        //                     levelsMenu->saveMouseClickCoords(mouseCoords);
        //                 else if (activeSceneCode == ActiveScenesCodes::GAME_LEVEL)
        //                     gameLevel->saveMouseClickCoords(mouseCoords);
        //             }      
        //     }
        // }
}

void Application::loadChosenLevel(){

    string levelsFolderPath = "../data/levels/";
    string levelPath;

    switch (numChosenLevel){
    case LEVEL_1:
        levelPath = levelsFolderPath + "level1.bin";
        break;

    default:
        if (DEBUG_CONSOLE_OUTPUT_ON)
            cout << "There is no level with such number" << endl;
        levelPath = levelsFolderPath + "level1.bin";
        break;
    }

    gameLevel = new GameLevel(renderer, soundPlayer);

    std::ofstream levelFileOut;
    levelFileOut.open(levelPath, std::ios::binary);

    //TODO move
    gameLevel->saveToBinaryFile(levelFileOut);

    if (DEBUG_CONSOLE_OUTPUT_ON && SAVING_LEVELS_ON)
        cout << "Level saved with path " << levelPath << endl; 

    levelFileOut.close();

    std::ifstream levelFile;
    levelFile.open(levelPath, std::ios::binary);
    if (!levelFile){
        //TODO handle
        if (DEBUG_CONSOLE_OUTPUT_ON)
            cout << "file with path " << levelPath << " does not exist" << endl;
    }

    gameLevel->loadFromBinaryFile(levelFile);

}

void Application::unloadLevel(){

    if (gameLevel != nullptr){
        delete gameLevel;
        gameLevel = nullptr;
    }
}

void Application::setChosenLevel(MenuOptionsCode code){

    switch (code)
    {
    case CHOOSE_LVL1:
        numChosenLevel = LEVEL_1;
        return;

    case CHOOSE_LVL2:
        numChosenLevel = LEVEL_2;
        return;

    case CHOOSE_LVL3:
        numChosenLevel = LEVEL_3;
        return;
    
    case CHOOSE_LVL4:
        numChosenLevel = LEVEL_4;
        return;
    
    default:
        cout << CoutTextColors::RED;
        cout << "Warning! No conversion from options code " << code << " to level num" << endl;
        cout << CoutTextColors::RESET;
        break;
    }
}
