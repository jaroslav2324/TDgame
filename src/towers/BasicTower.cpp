#include "BasicTower.h"

BasicTower::~BasicTower(){
}

Projectile* BasicTower::newProjectile(){
    return new BasicProjectile(aimedEnemy, towerCoords);
}

