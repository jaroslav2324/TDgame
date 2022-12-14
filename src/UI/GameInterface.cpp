#include "GameInterface.h"

GameInterface::GameInterface(SDL_Renderer* renderer, TowerManager* towerManager, EnemyManager* enemyManager){

    this->towerManager = towerManager;
    this->enemyManager = enemyManager;

    //TODO change button textures
    buildTowerBtn = new Button(renderer, TEST_BTN_BASIC_TEXTURE_PATH, 
                                         TEST_BTN_PRESSED_TEXTURE_PATH,
                                         TEST_BTN_HOVERED_TEXTURE_PATH,
                                         Coords(300, 40));

    spawnEnemyBtn = new Button(renderer, TEST_BTN_BASIC_TEXTURE_PATH, 
                                         TEST_BTN_PRESSED_TEXTURE_PATH,
                                         TEST_BTN_HOVERED_TEXTURE_PATH,
                                         Coords(600, 40));

    
}

GameInterface::~GameInterface(){
    
    if (buildTowerBtn != nullptr){
        delete buildTowerBtn;
        buildTowerBtn = nullptr;
    }

    if (spawnEnemyBtn != nullptr){
        delete spawnEnemyBtn;
        spawnEnemyBtn = nullptr;
    }
}

void GameInterface::render(SDL_Renderer* renderer){

    
    SDL_SetRenderDrawColor(renderer, 150, 150, 100, 255);
    SDL_Rect rect = {0, 0, 100, SCREEN_HEIGHT};
    SDL_RenderFillRect(renderer, &rect);

    rect = {0, 0, SCREEN_WIDTH, 100};
    SDL_RenderFillRect(renderer, &rect);

    rect = {0, SCREEN_HEIGHT - 10, SCREEN_WIDTH, 10};
    SDL_RenderFillRect(renderer, &rect);

    rect = {SCREEN_WIDTH - 10, 0, 10, SCREEN_HEIGHT};
    SDL_RenderFillRect(renderer, &rect);

    // check howering ower btns
    int x, y;

    SDL_GetMouseState(&x, &y);

    if (buildTowerBtn->isPointInRect(Coords(x, y)))
        buildTowerBtn->setModeHovered();
    else
        buildTowerBtn->setModeBasic();

    if (spawnEnemyBtn->isPointInRect(Coords(x, y)))
        spawnEnemyBtn->setModeHovered();
    else
        spawnEnemyBtn->setModeBasic();

    // check pressing on buttons
    while(!savedMouseClicks.empty()){
        Coords mouseCoords = savedMouseClicks.front();
        savedMouseClicks.pop();

        if (buildTowerBtn->isPointInRect(mouseCoords)){
            buildTowerBtn->setModePressed();

            if (!towerManager->isBuildModeActive())
                towerManager->activateBuildMode(renderer);
            
        }
        else if (spawnEnemyBtn->isPointInRect(mouseCoords)){

            spawnEnemyBtn->setModePressed();
            //TODO change wave
            Wave newWave = getBasicTestWave();
            enemyManager->setWave(newWave);
            // enemyManager->spawnEnemyAtPortal(renderer, BASIC_ENEMY);
        }

        else{
            if (towerManager->isBuildModeActive()){
                if (towerManager->isTowerExistsInTile(mouseCoords)){
                    //TODO warn player
                    cout << "Tower already exists, coords: " << mouseCoords.x << " " << mouseCoords.y << endl;
                }
                else{
                    towerManager->buildTower(renderer, BASIC_TOWER, Coords(mouseCoords.x, mouseCoords.y));
                    towerManager->deactivateBuildMode();
                }
            }
        }
    }

    // then render buttons
    buildTowerBtn->render(renderer);
    spawnEnemyBtn->render(renderer);

}

void GameInterface::saveMouseClickCoords(Coords coords){
    savedMouseClicks.push(coords);
}