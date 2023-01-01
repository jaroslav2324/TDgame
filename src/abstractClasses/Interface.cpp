#include "Interface.h"

Interface::Interface(){

}

Interface::~Interface(){

}

void Interface::saveMouseClickCoords(Coords coords){
    savedMouseClicks.push(coords);
}


void Interface::handleHoveringOverButtons(){

    int x, y;
    SDL_GetMouseState(&x, &y);
    Coords mouseCoords(x, y);

    for (auto btn: buttonsVec)
        if (btn->isPointInRect(mouseCoords))
            btn->setModeHoveredOver();
        else
            btn->setModeNoCursorInteraction();
    
}

MenuOptionsCode Interface::handlePressingOnButtons(){
    
    Coords mouseCoords;
    MenuOptionsCode returnCode = MenuOptionsCode::NO_CHANGES;

    while (!savedMouseClicks.empty()){

        mouseCoords = savedMouseClicks.front();
        savedMouseClicks.pop();

        for (int i = 0 ; i < buttonsVec.size(); i++)
            if (buttonsVec[i]->isPointInRect(mouseCoords)){
                buttonsVec[i]->setModePressedOn();
                returnCode = buttonsReturnCodesVec[i];
        }
    }

    return returnCode;
}

void Interface::renderButtons(Renderer* renderer){

    for (auto button: buttonsVec)
        button->render(renderer);
}


