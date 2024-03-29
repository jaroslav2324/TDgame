#pragma once

#include <map>
#include <vector>
#include <queue>

#include "../../engine/Engine.h"
#include "../../maths/maths.h"

#include "../UI/Button.h"
#include "../UI/MenuOptionsCodes.h"

using std::vector;
using std::queue;
using std::map;

class Interface{
    public:
    Interface(Renderer* renderer, SoundPlayer* soundPlayer, SystemEventsHandler* sysEventsHandler);
    ~Interface();

    virtual void render() = 0;

    //TODO remove
    void saveMouseClickCoords(Coords coords);

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    virtual void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    virtual void loadFromBinaryFile(istream& inputStream);

    protected:   

    Renderer* renderer = nullptr;
    SoundPlayer* soundPlayer = nullptr;
    SystemEventsHandler* sysEventsHandler = nullptr;

    //TODO remove
    queue<Coords> savedMouseClicks;

    // Use for iteration over buttons
    vector<Button*> buttonsVec;
    // Return codes if button is pressed. Use for iteration over buttons
    vector<MenuOptionsCode> buttonsReturnCodesVec;

    void renderButtons(Renderer* renderer);

    // implement if you want to iterate over buttons
    virtual void createButtonsVec() = 0;
    // implement if you want to return different options codes while iterating over buttons
    virtual void createButtonsReturnCodesVec() = 0;

    virtual void handleHoveringOverButtons();
    virtual MenuOptionsCode handlePressingOnButtons();
};
