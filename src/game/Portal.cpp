
#include "Portal.h"

Portal::Portal(Coords coords){
    Portal::coords = coords;
}

Portal::~Portal(){

}

void Portal::render(Renderer* renderer){

    int x = coords.x - TILESIZE / 2;
    int y = coords.y - TILESIZE / 2;
    SDL_Rect portalRect = {x, y, TILESIZE, TILESIZE};
    renderer->renderTexture(TexturesEnumeration::PORTAL_TEXTURE, &portalRect);
}

Coords Portal::getCoords(){
    return coords;
}

void Portal::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving portal stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    
    // save portal coords
    coords.saveToBinaryFile(outpustStream);
}

void Portal::loadFromBinaryFile(istream& inputStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !LOADING_LEVELS_ON)
        cout << "Loading levels is turned off. Loading portal stopped." << endl;

    if (!LOADING_LEVELS_ON)
        return;

    // load portal coords
    coords.loadFromBinaryFile(inputStream);
    
}
