#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "settings.h"
#include "Renderer.h"
#include "game/GameLevel.h"
#include "UI/MainMenu.h"
#include "UI/MenuOptionsCodes.h"

using std::cout;
using std::endl;

class Application{
    public:
    Application();
    ~Application();

    void loop();

    private:
    Renderer* renderer = nullptr;

    bool mainMenuOn = true;
    MainMenu* mainMenu = nullptr;
    GameLevel* gameLevel = nullptr;

    PeriodicTimer* fpsTimer =nullptr;
};
