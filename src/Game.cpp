#include "Game.h"

Game::Game(SDL_Renderer* renderer){

    enemiesWay = new EnemiesWay();

    auto baseCoords = enemiesWay->getFirstCoords();
    base = new Base(renderer, baseCoords);

    enemyManager = new EnemyManager(base, enemiesWay);
    towerManager = new TowerManager(enemyManager);

    fpsTimer = new PeriodicTimer(1 / FPS);

    grid = new Grid(renderer);

    //TODO delete test
    towerManager->buildTower(renderer, BASIC_TOWER, std::make_pair(250, 250));
    enemyManager->spawnEnemy(renderer, BASIC_ENEMY, std::make_pair(450, 450));

    testBtn = new Button(renderer,     TEST_BTN_BASIC_TEXTURE_PATH, 
                                       TEST_BTN_PRESSED_TEXTURE_PATH,
                                       TEST_BTN_HOVERED_TEXTURE_PATH,
                                       std::make_pair(300, 500));
                                       
    testBtn->setModeHovered();
    testBtn->setModePressed();
}

Game::~Game(){

    delete towerManager;
    delete enemyManager;

    delete fpsTimer;

    delete grid;

    delete base;

    delete enemiesWay;

    //TODO delete this
    delete testBtn;
}

void Game::renderAll(SDL_Renderer* renderer){

    //TODO render

    grid->renderGrid(renderer);
    towerManager->renderAllTowers(renderer);
    enemyManager->renderAllEnemies(renderer);
    towerManager->renderAllProjectiles(renderer);

    //TODO delete
    testBtn->render(renderer);

    //TODO render UI

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
