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

    interface = new GameInterface(towerManager, enemyManager);

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

void Game::renderAll(SDL_Renderer* renderer, TexturesHolder* texturesHolder){

    grid->renderGrid(texturesHolder);
    enemiesWay->render(renderer);
    portal->render(texturesHolder);
    base->render(texturesHolder);
    towerManager->renderAllTowers(renderer, texturesHolder);
    enemyManager->renderAllEnemies(texturesHolder);
    towerManager->renderAllProjectiles(renderer, texturesHolder);

    interface->render(renderer, texturesHolder);

    // SDL_RenderPresent(renderer);
}

MenuOptionsCode Game::makeFrameTurn(SDL_Renderer* renderer){

    //if base destroyed
    //if(base->noHitPoitsLeft()){
        //TODO end game
    //}

    MenuOptionsCode code = NO_CHANGES;

    enemyManager->spawnEnemiesInWave();
    enemyManager->allEnemiesMove();
    //cout << base->getHitPoits() << endl;

    towerManager->allTowersAttack(renderer);
    enemyManager->findAndDeleteKilledEnemies();

    return code;
}

void Game::saveMouseClickCoords(Coords coords){
    interface->saveMouseClickCoords(coords);
}
