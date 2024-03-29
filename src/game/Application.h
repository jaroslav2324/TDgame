#pragma once

#include <iostream>
#include <fstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#include "../settings.h"
#include "../engine/Engine.h"
#include "LevelsEnum.h"
#include "GameLevel.h"
#include "UI/MainMenu.h"
#include "UI/OptionsMenu.h"
#include "UI/LevelsMenu.h"
#include "UI/MenuOptionsCodes.h"
#include "UI/ActiveScenesCodes.h"

using std::cout;
using std::endl;

class Application{
    public:
    Application();
    ~Application();

    void loop();

    private:

    bool quitApp = false;

    Renderer* renderer = nullptr;
    SoundPlayer* soundPlayer = nullptr;
    // (SDL_Events)
    SystemEventsHandler* systemEventsHandler = nullptr;

    ActiveScenesCodes activeSceneCode = ActiveScenesCodes::MAIN_MENU;

    MainMenu* mainMenu = nullptr;
    OptionsMenu* optionsMenu = nullptr;
    GameLevel* gameLevel = nullptr;
    LevelsMenu* levelsMenu = nullptr;

    PeriodicTimer* fpsTimer = nullptr;

    LevelsEnum numChosenLevel = LEVEL_1;

    void handleEvents();

    void setChosenLevel(MenuOptionsCode code);
    void loadChosenLevel();
    void unloadLevel();
};
