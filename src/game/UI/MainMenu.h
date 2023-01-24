#pragma once

#include <iostream>
#include <queue>

#include "../../settings.h"

#include "../abstractClasses/Interface.h"
#include "MenuOptionsCodes.h"
#include "Button.h"

using std::queue;
using std::cout;
using std::endl;


class MainMenu: public Interface{

    public:
    MainMenu(Renderer* renderer,SoundPlayer* soundPlayer);
    ~MainMenu();

    MenuOptionsCode makeFrameTurn();

    void render();

    private:

    Button* startGameBtn = nullptr;
    Button* settingsBtn = nullptr;
    Button* quitBtn = nullptr;

    PeriodicTimer* fpsTimer = nullptr;

    // implement if you want to iterate over buttons
    virtual void createButtonsVec();
    // implement if you want to return different options codes while iterating over buttons
    virtual void createButtonsReturnCodesVec();

    //void handleHoveringOverButtons();
    //MenuOptionsCode handlePressingOnButtons();
};
