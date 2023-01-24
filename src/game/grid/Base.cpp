#include "Base.h"

Base::Base(Coords spawnCoords){
    coords = spawnCoords;
}

Base::~Base(){

}

int Base::getHitPoits(){
    return hitPoints;
}

void Base::setHitPoints(int hitPoints){
    Base::hitPoints = hitPoints;
}

void Base::applyDamage(int damage){
    int currentHitPoints = hitPoints; // cout in debug mode

    hitPoints -= damage;
    
    if (DEBUG_CONSOLE_OUTPUT_ON)
        cout << "Base hit points changed " << currentHitPoints << " => " << hitPoints << endl;
}

bool Base::noHitPoitsLeft(){
    if (hitPoints <= 0)
        return true;
    return false;
}

void Base::render(Renderer* renderer){

    int x = coords.x - TILESIZE / 2;
    int y = coords.y - TILESIZE / 2;
    SDL_Rect baseRect = {x, y, TILESIZE, TILESIZE};
    renderer->renderTexture(TexturesEnumeration::BASE_TEXTURE, &baseRect);
}

void Base::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving base stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    
    // save hitpoints
    outpustStream.write((char*)&hitPoints, sizeof(hitPoints));

    // save coords
    coords.saveToBinaryFile(outpustStream);

}

void Base::loadFromBinaryFile(istream& inputStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !LOADING_LEVELS_ON)
        cout << "Loading levels is turned off. Loading base stopped." << endl;

    if (!LOADING_LEVELS_ON)
        return;

    // load hitpoints
    inputStream.read((char*)&hitPoints, sizeof(hitPoints));

    // load coords
    coords.loadFromBinaryFile(inputStream);
}
