#pragma once

#include <iostream>
#include <queue>

#include "../settings.h"
#include "MenuOptionsCodes.h"
#include "Button.h"

using std::queue;
using std::cout;
using std::endl;


class MainMenu{

    public:
    MainMenu(PeriodicTimer* fpsTimer);
    ~MainMenu();

    MenuOptionsCode makeFrameTurn();

    void render(SDL_Renderer* renderer, TexturesHolder* texturesHolder);

    void saveMouseClickCoords(Coords coords);

    private:

    Button* startGameBtn = nullptr;
    Button* settingsBtn = nullptr;
    Button* quitBtn = nullptr;

    PeriodicTimer* fpsTimer = nullptr;

    queue<Coords> savedMouseClicks;

    MenuOptionsCode handleButtonClicks();
};
