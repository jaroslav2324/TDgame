#include "Game.h"

Game::Game(){

    enemiesWay = new EnemiesWay();

    auto baseCoords = enemiesWay->getLastCoords();
    base = new Base(baseCoords);
    auto portalCoords = enemiesWay->getFirstCoords();
    // cout << portalCoords;
    portal = new Portal(portalCoords);


    enemyManager = new EnemyManager(base, portal, enemiesWay);
    towerManager = new TowerManager(enemyManager);

    fpsTimer = new PeriodicTimer(1 / FPS * 1000);

    grid = new Grid();

    interface = new BasicInterface(towerManager, enemyManager);

}

Game::~Game(){

    if (towerManager != nullptr){
        delete towerManager;
        towerManager = nullptr;
    }
    if (enemyManager != nullptr){
        delete enemyManager;
        enemyManager = nullptr;
    }

    if (fpsTimer != nullptr){
        delete fpsTimer;
        fpsTimer = nullptr;
    }

    if (grid != nullptr){
        delete grid;
        grid = nullptr;
    }

    if (base != nullptr){
        delete base;
        base = nullptr;
    }

    if (enemiesWay != nullptr){
        delete enemiesWay;
        enemiesWay = nullptr;
    }

    if (interface != nullptr){
        delete interface;
        interface = nullptr;
    }
}

void Game::renderAll(Renderer* renderer){

    grid->renderGrid(renderer);
    enemiesWay->render(renderer);
    portal->render(renderer);
    base->render(renderer);
    towerManager->renderAllTowers(renderer);
    enemyManager->renderAllEnemies(renderer);
    towerManager->renderAllProjectiles(renderer);

    interface->render(renderer);

    // SDL_RenderPresent(renderer);
}

MenuOptionsCode Game::makeFrameTurn(){

    //if base destroyed
    //if(base->noHitPoitsLeft()){
        //TODO end game
    //}

    MenuOptionsCode code = NO_CHANGES;

    enemyManager->spawnEnemiesInWave();
    enemyManager->allEnemiesMove();
    //cout << base->getHitPoits() << endl;

    towerManager->allTowersAttack();
    enemyManager->findAndDeleteKilledEnemies();

    return code;
}

void Game::saveMouseClickCoords(Coords coords){
    interface->saveMouseClickCoords(coords);
}
