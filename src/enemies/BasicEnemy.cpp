#include "BasicEnemy.h"

BasicEnemy::~BasicEnemy(){
    deleteMovementTimer();
}


void BasicEnemy::setMovementTimer(){
    movementTimer = new PeriodicTimer(1 / FPS);
}

void BasicEnemy::deleteMovementTimer(){
    delete movementTimer;
}