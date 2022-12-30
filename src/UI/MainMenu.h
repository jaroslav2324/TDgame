#pragma once

#include <iostream>
#include <queue>

#include "../settings.h"
#include "../abstractClasses/Interface.h"
#include "MenuOptionsCodes.h"
#include "Button.h"

using std::queue;
using std::cout;
using std::endl;


class MainMenu: public Interface{

    public:
    MainMenu();
    ~MainMenu();

    MenuOptionsCode makeFrameTurn();

    void render(Renderer* renderer);

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

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
