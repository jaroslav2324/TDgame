#include "Game.h"

Game::Game(SDL_Renderer* renderer){

    enemiesWay = new EnemiesWay();

    auto baseCoords = enemiesWay->getFirstCoords();
    base = new Base(renderer, baseCoords);

    enemyManager = new EnemyManager(base, enemiesWay);
    towerManager = new TowerManager(enemyManager);

    fpsTimer = new PeriodicTimer(1 / FPS * 1000);

    grid = new Grid(renderer);

    interface = new Interface(renderer, towerManager, enemyManager);

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

    bool quit = false;
    
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

        //int cnt = 0;
        if (fpsTimer->tickIfNeeded()){
            //cout << cnt << endl;
            //cnt++;

            }

            //FIXME seg fault
            //towerManager->allTowersAttack(renderer);

            //enemyManager->allEnemiesMove();

            //TODO spawn enemies if needed 

            //if base destroyed
            //if(base->noHitPoitsLeft()){
                //TODO end game
            //}
        }

        renderAll(renderer);
	}

}
