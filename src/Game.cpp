#include "Game.h"

Game::Game(){

    enemyManager = new EnemyManager();
    towerManager = new TowerManager(enemyManager);

    fpsTimer = new PeriodicTimer(1 / FPS);
}

Game::~Game(){

    delete towerManager;
    delete enemyManager;

    delete fpsTimer;
}

void Game::renderAll(){

    //TODO render

    //render grid

    //render towers
    //render enemies  
    //render projectiles

    //render UI
}

void Game::loop(){

    //TODO game loop
}
