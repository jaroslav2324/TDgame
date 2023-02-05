#pragma once

#include "../../engine/Engine.h"

#include "../abstractClasses/Interface.h"
#include "Button.h"

class LevelsMenu: public Interface{

    public:
    LevelsMenu(Renderer* renderer, SoundPlayer* soundPlayer, SystemEventsHandler* sysEventsHandler);
    ~LevelsMenu();

    MenuOptionsCode makeFrameTurn();

    void render();

    private:

    Button* toMainMenuBtn = nullptr;
    Button* chooseLvl1Btn = nullptr;
    Button* chooseLvl2Btn = nullptr;
    Button* chooseLvl3Btn = nullptr;
    Button* chooseLvl4Btn = nullptr;

    PeriodicTimer* fpsTimer = nullptr;

    // implement if you want to iterate over buttons
    virtual void createButtonsVec();
    // implement if you want to return different options codes while iterating over buttons
    virtual void createButtonsReturnCodesVec();

    // void handleHoveringOverButtons();
    // MenuOptionsCode handlePressingOnButtons();
};