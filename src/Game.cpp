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

void Game::renderAll(SDL_Renderer* renderer){

    //TODO render

    //render grid

    towerManager->renderAllTowers(renderer);
    enemyManager->renderAllEnemies(renderer);
    towerManager->renderAllProjectiles(renderer);

    //TODO render UI

    SDL_RenderPresent(renderer);
}

void Game::loop(SDL_Renderer* renderer){

    //TODO game loop
    if (fpsTimer->tickIfNeeded()){

        towerManager->allTowersAttack(renderer);

        enemyManager->allEnemiesMove();

        //spawn enemies if needed 

        //if base destroyed
        if(base->noHitPoitsLeft()){
            //TODO end game
        }
    }

    renderAll(renderer);
}
