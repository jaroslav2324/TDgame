#include "GameLevel.h"

GameLevel::GameLevel(){

    enemiesWay = new EnemiesWay();

    auto baseCoords = enemiesWay->getLastCoords();
    base = new Base(baseCoords);
    auto portalCoords = enemiesWay->getFirstCoords();
    // cout << portalCoords;
    portal = new Portal(portalCoords);


    enemyManager = new EnemyManager(base, portal, enemiesWay);
    towerManager = new TowerManager(enemyManager);

    fpsTimer = new PeriodicTimer(1 / FPS * 1000);

    grid = new Grid(Coords(100, 100), Coords(SCREEN_WIDTH, SCREEN_HEIGHT), TILESIZE, TILESIZE, GAME_LEVEL_WIDTH, GAME_LEVEL_HEIGHT
    );

    interface = new BasicInterface(towerManager, enemyManager);

}

GameLevel::~GameLevel(){

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

void GameLevel::renderAll(Renderer* renderer){

    grid->renderGrid(renderer);
    enemiesWay->render(renderer);
    portal->render(renderer);
    base->render(renderer);
    towerManager->renderAllTowers(renderer);
    enemyManager->renderAll(renderer);
    towerManager->renderAllAttacks(renderer);

    interface->render(renderer);

    // SDL_RenderPresent(renderer);
}

MenuOptionsCode GameLevel::makeFrameTurn(){

    //if base destroyed
    //if(base->noHitPoitsLeft()){
        //TODO end gameLevel
    //}

    enemyManager->spawnEnemiesIfStarted();
    enemyManager->allEnemiesMove();
    //cout << base->getHitPoits() << endl;

    towerManager->allTowersAttack();
    enemyManager->findAndDeleteKilledEnemies();

    returntoAppCode = interface->handleCursorInteraction();

    return returntoAppCode;
}

void GameLevel::saveMouseClickCoords(Coords coords){
    interface->saveMouseClickCoords(coords);
}

void GameLevel::setReturnToAppCode(MenuOptionsCode code){
    returntoAppCode = code; 
}

void GameLevel::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving level stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    
    // save level
    enemiesWay->saveToBinaryFile(outpustStream);
    base->saveToBinaryFile(outpustStream);
    portal->saveToBinaryFile(outpustStream);
    grid->saveToBinaryFile(outpustStream);
    interface->saveToBinaryFile(outpustStream);

}

void GameLevel::loadFromBinaryFile(istream& inputStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !LOADING_LEVELS_ON)
        cout << "Loading levels is turned off. Loading level stopped." << endl;

    if (!LOADING_LEVELS_ON)
        return;

    // load level
    enemiesWay->loadFromBinaryFile(inputStream);
    base->loadFromBinaryFile(inputStream);
    portal->loadFromBinaryFile(inputStream);
    grid->loadFromBinaryFile(inputStream);
    interface->loadFromBinaryFile(inputStream);
}
