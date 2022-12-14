#include "Game.h"

Game::Game(SDL_Renderer* renderer){

    enemiesWay = new EnemiesWay();

    auto baseCoords = enemiesWay->getLastCoords();
    base = new Base(renderer, baseCoords);
    auto portalCoords = enemiesWay->getFirstCoords();
    // cout << portalCoords;
    portal = new Portal(renderer, portalCoords);


    enemyManager = new EnemyManager(base, portal, enemiesWay);
    towerManager = new TowerManager(enemyManager);

    fpsTimer = new PeriodicTimer(1 / FPS * 1000);

    grid = new Grid(renderer);

    interface = new Interface(renderer, towerManager, enemyManager);

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

void Game::renderAll(SDL_Renderer* renderer){

    grid->renderGrid(renderer);
    enemiesWay->render(renderer);
    portal->render(renderer);
    base->render(renderer);
    towerManager->renderAllTowers(renderer);
    enemyManager->renderAllEnemies(renderer);
    towerManager->renderAllProjectiles(renderer);

    interface->render(renderer);

    SDL_RenderPresent(renderer);
}

void Game::loop(SDL_Renderer* renderer){

    bool quit = false;
    // int cnt = 0;

    while (!quit){

        // handle events
        SDL_Event event;
        while(SDL_PollEvent(&event)){
            switch (event.type) {
                case SDL_QUIT:    
                    quit = true;        
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    if (event.button.button == SDL_BUTTON_LEFT){
                        int x, y;
                        SDL_GetMouseState(&x, &y);
                        interface->saveMouseClickCoords(Coords(x, y));
                    }      
            }

        


            

            //TODO spawn enemies if needed 

            //if base destroyed
            //if(base->noHitPoitsLeft()){
                //TODO end game
            //}
        }

        if (fpsTimer->tickIfNeeded()){
        // cout << cnt << endl;
        // cnt++;
        enemyManager->allEnemiesMove();
        //cout << base->getHitPoits() << endl;

        towerManager->allTowersAttack(renderer);
        enemyManager->findAndDeleteKilledEnemies();
        
        }

        renderAll(renderer);
	}

}
