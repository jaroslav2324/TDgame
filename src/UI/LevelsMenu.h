#pragma once

#include "../abstractClasses/Interface.h"
#include "../Timers.h"
#include "Button.h"

class LevelsMenu: public Interface{

    public:
    LevelsMenu();
    ~LevelsMenu();

    MenuOptionsCode makeFrameTurn();

    void render(Renderer* renderer);

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

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