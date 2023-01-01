#pragma once

#include "../abstractClasses/Interface.h"
#include "../Timers.h"
#include "Button.h"

class OptionsMenu: public Interface{

    public:
    OptionsMenu();
    ~OptionsMenu();

    MenuOptionsCode makeFrameTurn();

    void render(Renderer* renderer);

    private:

    Button* toMainMenuBtn = nullptr;

    PeriodicTimer* fpsTimer = nullptr;

    // implement if you want to iterate over buttons
    virtual void createButtonsVec();
    // implement if you want to return different options codes while iterating over buttons
    virtual void createButtonsReturnCodesVec();

    // void handleHoveringOverButtons();
    // MenuOptionsCode handlePressingOnButtons();
};
