#include "GameInterface.h"

GameInterface::GameInterface(SDL_Renderer* renderer, TowerManager* towerManager, EnemyManager* enemyManager){

    this->towerManager = towerManager;
    this->enemyManager = enemyManager;

    //TODO change button textures
    buildBasicTowerBtn = new Button(renderer, TEST_BTN_BASIC_TEXTURE_PATH, 
                                         TEST_BTN_PRESSED_TEXTURE_PATH,
                                         TEST_BTN_HOVERED_TEXTURE_PATH,
                                         Coords(50, 300));

    buildIceTowerBtn = new Button(renderer, TEST_BTN_BASIC_TEXTURE_PATH, 
                                         TEST_BTN_PRESSED_TEXTURE_PATH,
                                         TEST_BTN_HOVERED_TEXTURE_PATH,
                                         Coords(50, 450));

    buildFireTowerBtn = new Button(renderer, TEST_BTN_BASIC_TEXTURE_PATH, 
                                         TEST_BTN_PRESSED_TEXTURE_PATH,
                                         TEST_BTN_HOVERED_TEXTURE_PATH,
                                         Coords(50, 600));                                   

    spawnEnemyBtn = new Button(renderer, TEST_BTN_BASIC_TEXTURE_PATH, 
                                         TEST_BTN_PRESSED_TEXTURE_PATH,
                                         TEST_BTN_HOVERED_TEXTURE_PATH,
                                         Coords(600, 40));

    
}

GameInterface::~GameInterface(){
    
    if (buildBasicTowerBtn != nullptr){
        delete buildBasicTowerBtn;
        buildBasicTowerBtn = nullptr;
    }

    if (buildIceTowerBtn != nullptr){
        delete buildIceTowerBtn;
        buildIceTowerBtn = nullptr;
    }

    if (buildFireTowerBtn != nullptr){
        delete buildFireTowerBtn;
        buildFireTowerBtn = nullptr;
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

    // TODO move from render
    // check howering ower btns
    int x, y;

    SDL_GetMouseState(&x, &y);

    if (buildBasicTowerBtn->isPointInRect(Coords(x, y)))
        buildBasicTowerBtn->setModeHoveredOver();
    else
        buildBasicTowerBtn->setModeNoCursorInteraction();

    if (buildIceTowerBtn->isPointInRect(Coords(x, y)))
        buildIceTowerBtn->setModeHoveredOver();
    else
        buildIceTowerBtn->setModeNoCursorInteraction();

    if (buildFireTowerBtn->isPointInRect(Coords(x, y)))
        buildFireTowerBtn->setModeHoveredOver();
    else
        buildFireTowerBtn->setModeNoCursorInteraction();

    if (spawnEnemyBtn->isPointInRect(Coords(x, y)))
        spawnEnemyBtn->setModeHoveredOver();
    else
        spawnEnemyBtn->setModeNoCursorInteraction();

    // TODO move button actions from render method?

    // check pressing on buttons
    while(!savedMouseClicks.empty()){
        Coords mouseCoords = savedMouseClicks.front();
        savedMouseClicks.pop();

        if (buildBasicTowerBtn->isPointInRect(mouseCoords)){
            buildBasicTowerBtn->setModePressedOn();
            buildTowerType = BASIC_TOWER;

            if (!towerManager->isBuildModeActive())
                towerManager->activateBuildMode(renderer, BASIC_TOWER);
            else
                towerManager->deactivateBuildMode();
            
        }
        else if (buildIceTowerBtn->isPointInRect(mouseCoords)){
            buildIceTowerBtn->setModePressedOn();
            buildTowerType = ICE_TOWER;

            if (!towerManager->isBuildModeActive())
                towerManager->activateBuildMode(renderer, ICE_TOWER);
            else
                towerManager->deactivateBuildMode();
        }
        else if (buildFireTowerBtn->isPointInRect(mouseCoords)){
            buildFireTowerBtn->setModePressedOn();
            buildTowerType = FIRE_TOWER;

            if (!towerManager->isBuildModeActive())
                towerManager->activateBuildMode(renderer, FIRE_TOWER);
            else
                towerManager->deactivateBuildMode();
        }
        else if (spawnEnemyBtn->isPointInRect(mouseCoords)){

            spawnEnemyBtn->setModePressedOn();
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
                    towerManager->buildTower(renderer, buildTowerType, Coords(mouseCoords.x, mouseCoords.y));
                    towerManager->deactivateBuildMode();
                }
            }
        }
    }

    // then render buttons
    buildBasicTowerBtn->render(renderer);
    buildIceTowerBtn->render(renderer);
    buildFireTowerBtn->render(renderer);
    spawnEnemyBtn->render(renderer);

}

void GameInterface::saveMouseClickCoords(Coords coords){
    savedMouseClicks.push(coords);
}