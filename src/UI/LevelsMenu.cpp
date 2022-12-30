#include "LevelsMenu.h"

LevelsMenu::LevelsMenu(){
    
    //TODO change button textures
    // TODO change button centers(height)

    toMainMenuBtn = new Button(TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE, 
                                         TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE,
                                         TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE,
                                            Coords(150, 100));
    toMainMenuBtn->setWidthHeight(200, 100);

    chooseLvl1Btn = new Button(TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE, 
                                         TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE,
                                         TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE,
                                            Coords(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 3));
    chooseLvl1Btn->setWidthHeight(100, 100);

    chooseLvl2Btn = new Button(TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE, 
                                         TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE,
                                         TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE,
                                            Coords((SCREEN_WIDTH * 2) / 3, SCREEN_HEIGHT / 3));
    chooseLvl2Btn->setWidthHeight(100, 100);

    chooseLvl3Btn = new Button(TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE, 
                                         TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE,
                                         TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE,
                                            Coords(SCREEN_WIDTH / 3, ((SCREEN_HEIGHT * 2) / 3)));
    chooseLvl3Btn->setWidthHeight(100, 100);

    chooseLvl4Btn = new Button(TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE, 
                                         TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE,
                                         TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE,
                                            Coords((SCREEN_WIDTH * 2) / 3, (SCREEN_HEIGHT * 2) / 3));
    chooseLvl4Btn->setWidthHeight(100, 100);
}

LevelsMenu::~LevelsMenu(){

    if (toMainMenuBtn != nullptr){
        delete toMainMenuBtn;
        toMainMenuBtn = nullptr;
    }

    if (chooseLvl1Btn != nullptr){
        delete chooseLvl1Btn;
        chooseLvl1Btn = nullptr;
    }

    if (chooseLvl2Btn != nullptr){
        delete chooseLvl2Btn;
        chooseLvl2Btn = nullptr;
    }

    if (chooseLvl3Btn != nullptr){
        delete chooseLvl3Btn;
        chooseLvl3Btn = nullptr;
    }

    if (chooseLvl4Btn != nullptr){
        delete chooseLvl4Btn;
        chooseLvl4Btn = nullptr;
    }
}

MenuOptionsCode LevelsMenu::makeFrameTurn(){

    handleHoveringOverButtons();
    return handlePressingOnButtons();
}

void LevelsMenu::render(Renderer* renderer){

    SDL_Color color = {120, 120, 150, 255};
    SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    renderer->renderFilledRect(&rect, color);

    toMainMenuBtn->render(renderer);
    chooseLvl1Btn->render(renderer);
    chooseLvl2Btn->render(renderer);
    chooseLvl3Btn->render(renderer);
    chooseLvl4Btn->render(renderer);
}

void LevelsMenu::handleHoveringOverButtons(){

    // check howering over buttons
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    Coords mouseCoords(mouseX, mouseY);

    // to main menu button
    if (toMainMenuBtn->isPointInRect(mouseCoords))
        toMainMenuBtn->setModeHoveredOver();
    else
        toMainMenuBtn->setModeNoCursorInteraction();

    if (chooseLvl1Btn->isPointInRect(mouseCoords))
        chooseLvl1Btn->setModeHoveredOver();
    else
        chooseLvl1Btn->setModeNoCursorInteraction();

    if (chooseLvl2Btn->isPointInRect(mouseCoords))
        chooseLvl2Btn->setModeHoveredOver();
    else
        chooseLvl2Btn->setModeNoCursorInteraction();


    if (chooseLvl3Btn->isPointInRect(mouseCoords))
        chooseLvl3Btn->setModeHoveredOver();
    else
        chooseLvl3Btn->setModeNoCursorInteraction();

    if (chooseLvl4Btn->isPointInRect(mouseCoords))
        chooseLvl4Btn->setModeHoveredOver();
    else
        chooseLvl4Btn->setModeNoCursorInteraction();
}

MenuOptionsCode LevelsMenu::handlePressingOnButtons(){

    MenuOptionsCode code = NO_CHANGES;
    // check pressing on buttons
    while(!savedMouseClicks.empty()){
        Coords mouseCoords = savedMouseClicks.front();
        savedMouseClicks.pop();

        if (toMainMenuBtn->isPointInRect(mouseCoords)){
            toMainMenuBtn->setModePressedOn();
            code = QUIT_TO_MAIN_MENU;

            if (DEBUG_CONSOLE_OUTPUT_ON)
                cout << "return to main menu button pressed" << endl;
        }

        if (chooseLvl1Btn->isPointInRect(mouseCoords)){
            chooseLvl1Btn->setModePressedOn();
            code = CHOOSE_LVL1;
        }

        if (chooseLvl2Btn->isPointInRect(mouseCoords)){
            chooseLvl2Btn->setModePressedOn();
            code = CHOOSE_LVL2;
        }

        if (chooseLvl3Btn->isPointInRect(mouseCoords)){
            chooseLvl3Btn->setModePressedOn();
            code = CHOOSE_LVL3;
        }

        if (chooseLvl4Btn->isPointInRect(mouseCoords)){
            chooseLvl4Btn->setModePressedOn();
            code = CHOOSE_LVL4;
        }
    }

    return code;
}


void LevelsMenu::saveToBinaryFile(ostream& outpustStream){
    //TODO implement
}

void LevelsMenu::loadFromBinaryFile(istream& inputStream){
    //TODO implement
}
