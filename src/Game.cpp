#include "Game.h"

Game::Game(){

    enemiesWay = new EnemiesWay();

    auto baseCoords = enemiesWay->getFirstCoords();
    base = new Base(baseCoords);

    enemyManager = new EnemyManager(base, enemiesWay);
    towerManager = new TowerManager(enemyManager);

    fpsTimer = new PeriodicTimer(1 / FPS);

    grid = new Grid();

}

Game::~Game(){

    delete towerManager;
    delete enemyManager;

    delete fpsTimer;

    delete grid;

    delete base;

    delete enemiesWay;
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
    if (fpsTimer->tickIfNeeded()){

        towerManager->allTowersAttack();

        enemyManager->allEnemiesMove();

        //spawn enemies if needed 

        //if base destroyed
        if(base->noHitPoitsLeft()){
            //TODO end game
        }
    }
}
