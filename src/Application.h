#pragma once

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "settings.h"
#include "game/Game.h"
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
    SDL_Renderer* renderer = nullptr;
    SDL_Window* window = nullptr;

    bool mainMenuOn = true;
    MainMenu* mainMenu = nullptr;
    Game* game = nullptr;

    PeriodicTimer* fpsTimer =nullptr;
};
