#include "Interface.h"

Interface::Interface(){

}

Interface::~Interface(){

}

void Interface::saveMouseClickCoords(Coords coords){
    savedMouseClicks.push(coords);
}



