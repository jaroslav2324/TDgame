#include "Base.h"

Base::Base(std::pair<float, float> spawnCoords){
    coords = spawnCoords;
    //TODO load sprite
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