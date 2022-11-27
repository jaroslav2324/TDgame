#include "Game.h"

Game::Game(SDL_Renderer* renderer){

    enemiesWay = new EnemiesWay();

    auto baseCoords = enemiesWay->getFirstCoords();
    base = new Base(renderer, baseCoords);

    enemyManager = new EnemyManager(base, enemiesWay);
    towerManager = new TowerManager(enemyManager);

    fpsTimer = new PeriodicTimer(1 / FPS);

    grid = new Grid(renderer);

    interface = new Interface(renderer);

    //TODO delete test
    towerManager->buildTower(renderer, BASIC_TOWER, std::make_pair(250, 250));
    enemyManager->spawnEnemy(renderer, BASIC_ENEMY, std::make_pair(450, 450));
}

Game::~Game(){

    delete towerManager;
    delete enemyManager;

    delete fpsTimer;

    delete grid;

    delete base;

    delete enemiesWay;

    delete interface;
}

void Game::renderAll(SDL_Renderer* renderer){

    //TODO render

    grid->renderGrid(renderer);
    towerManager->renderAllTowers(renderer);
    enemyManager->renderAllEnemies(renderer);
    towerManager->renderAllProjectiles(renderer);

    //TODO render UI
    interface->render(renderer);

    SDL_RenderPresent(renderer);
}

void Game::loop(SDL_Renderer* renderer){

    //TODO game loop
    if (fpsTimer->tickIfNeeded()){

        towerManager->allTowersAttack(renderer);

        enemyManager->allEnemiesMove();

        //TODO spawn enemies if needed 

        //if base destroyed
        if(base->noHitPoitsLeft()){
            //TODO end game
        }
    }

    renderAll(renderer);
}
