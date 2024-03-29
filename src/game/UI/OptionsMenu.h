#pragma once

#include "../../engine/Engine.h"

#include "../abstractClasses/Interface.h"
#include "Button.h"
#include "Slider.h"

class OptionsMenu: public Interface{

    public:
    OptionsMenu(Renderer* renderer, SoundPlayer* soundPlayer, SystemEventsHandler* sysEventsHandler);
    ~OptionsMenu();

    MenuOptionsCode makeFrameTurn();

    void render();

    private:

    Button* toMainMenuBtn = nullptr;
    Slider* musicVolumeSlider = nullptr;

    PeriodicTimer* fpsTimer = nullptr;

    // implement if you want to iterate over buttons
    virtual void createButtonsVec();
    // implement if you want to return different options codes while iterating over buttons
    virtual void createButtonsReturnCodesVec();

    // void handleHoveringOverButtons();
    // MenuOptionsCode handlePressingOnButtons();
};
