
#include "Portal.h"

Portal::Portal(Coords coords){
    Portal::coords = coords;
}

Portal::~Portal(){

}

void Portal::render(TexturesHolder* texturesHolder){

    int x = coords.x - TILESIZE / 2;
    int y = coords.y - TILESIZE / 2;
    SDL_Rect portalRect = {x, y, TILESIZE, TILESIZE};
    texturesHolder->renderTexture(TexturesEnumeration::PORTAL_TEXTURE, &portalRect);
}

Coords Portal::getCoords(){
    return coords;
}
