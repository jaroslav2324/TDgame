#include "Interface.h"

Interface::Interface(){

}

Interface::~Interface(){

}

void Interface::saveMouseClickCoords(Coords coords){
    savedMouseClicks.push(coords);
}

void Interface::seteftMousePressed(){
    leftMousePressed = true;
}

void Interface::setLeftMouseReleased(){
    leftMousePressed = false;
}


void Interface::handleHoveringOverButtons(){

    int x, y;
    SDL_GetMouseState(&x, &y);
    Coords mouseCoords(x, y);

    for (auto btn: buttonsVec)
        if (btn->isPointInRect(mouseCoords))
            btn->setModeAndPlaySound(ObjectCursorInteractionsModes::HOVERED_OVER);
        else
            btn->setModeAndPlaySound(ObjectCursorInteractionsModes::NO_INTERACTION);
    
}

MenuOptionsCode Interface::handlePressingOnButtons(){
    
    Coords mouseCoords;
    MenuOptionsCode returnCode = MenuOptionsCode::NO_CHANGES;

    while (!savedMouseClicks.empty()){

        mouseCoords = savedMouseClicks.front();
        savedMouseClicks.pop();

        for (int i = 0 ; i < buttonsVec.size(); i++)
            if (buttonsVec[i]->isPointInRect(mouseCoords)){
                buttonsVec[i]->setModeAndPlaySound(ObjectCursorInteractionsModes::PRESSED_ON);
                returnCode = buttonsReturnCodesVec[i];
        }
    }

    return returnCode;
}

void Interface::renderButtons(Renderer* renderer){

    for (auto button: buttonsVec)
        button->render();
}


void Interface::saveToBinaryFile(ostream& outpustStream){
    if (DEBUG_CONSOLE_OUTPUT_ON){
        cout << CoutTextColors::YELLOW;
        cout << "Warning! Virtual function saveToBinaryFile not implemented but called from basic Interface class.";
        cout << CoutTextColors::RESET;
    }
}

void Interface::loadFromBinaryFile(istream& inputStream){
    if (DEBUG_CONSOLE_OUTPUT_ON){
        cout << CoutTextColors::YELLOW;
        cout << "Warning! Virtual function loadFromBinaryFile not implemented but called from basic Interface class.";
        cout << CoutTextColors::RESET;
    }
}
