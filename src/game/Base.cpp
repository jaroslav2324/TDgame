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
    hitPoints -= damage;
}

bool Base::noHitPoitsLeft(){
    if (hitPoints <= 0)
        return true;
    return false;
}

void Base::render(TexturesHolder* texturesHolder){

    int x = coords.x - TILESIZE / 2;
    int y = coords.y - TILESIZE / 2;
    SDL_Rect baseRect = {x, y, TILESIZE, TILESIZE};
    texturesHolder->renderTexture(TexturesEnumeration::BASE_TEXTURE, &baseRect);
}
