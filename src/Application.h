#pragma once

#include <iostream>
#include <fstream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "settings.h"
#include "Renderer.h"
#include "LevelsEnum.h"
#include "game/GameLevel.h"
#include "UI/MainMenu.h"
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
    Renderer* renderer = nullptr;

    ActiveScenesCodes activeSceneCode = ActiveScenesCodes::MAIN_MENU;

    MainMenu* mainMenu = nullptr;
    GameLevel* gameLevel = nullptr;

    PeriodicTimer* fpsTimer = nullptr;

    LevelsEnum numChosenLevel = FIRST_LEVEL;
};
