#pragma once

#include <iostream>
#include <queue>

#include "../settings.h"
#include "Button.h"

using std::queue;
using std::cout;
using std::endl;

class MainMenu{

    public:
    MainMenu(SDL_Renderer* renderer, PeriodicTimer* fpsTimer);
    ~MainMenu();

    void loop(SDL_Renderer* renderer);

    void saveMouseClickCoords(Coords coords);

    private:

    Button* startGameBtn = nullptr;
    Button* settingsBtn = nullptr;
    Button* quitBtn = nullptr;

    PeriodicTimer* fpsTimer = nullptr;

    queue<Coords> savedMouseClicks;

    void render(SDL_Renderer* renderer);
};
