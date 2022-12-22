#include "BasicInterface.h"

BasicInterface::BasicInterface(TowerManager* towerManager, EnemyManager* enemyManager){

    this->towerManager = towerManager;
    this->enemyManager = enemyManager;

    //TODO change button textures
    buildBasicTowerBtn = new Button(TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE, 
                                         TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE,
                                         TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE,
                                         Coords(50, 300));

    buildIceTowerBtn = new Button(TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE, 
                                         TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE,
                                         TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE,
                                         Coords(50, 450));

    buildFireTowerBtn = new Button(TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE, 
                                         TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE,
                                         TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE,
                                         Coords(50, 600));                                   

    spawnEnemyBtn = new Button(TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE, 
                                         TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE,
                                         TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE,
                                         Coords(600, 40));

    
}

BasicInterface::~BasicInterface(){
    
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

void BasicInterface::render(Renderer* renderer){

    SDL_Color color = {150, 150, 100, 255};
    
    SDL_Rect rect = {0, 0, 100, SCREEN_HEIGHT};
    const SDL_Rect* rectPtr = &rect;

    renderer->renderFilledRect(rectPtr, color);

    rect = {0, 0, SCREEN_WIDTH, 100};
    renderer->renderFilledRect(rectPtr, color);

    rect = {0, SCREEN_HEIGHT - 10, SCREEN_WIDTH, 10};
    renderer->renderFilledRect(rectPtr, color);

    rect = {SCREEN_WIDTH - 10, 0, 10, SCREEN_HEIGHT};
    renderer->renderFilledRect(rectPtr, color);

    handleHoveringOverButtons();
    handlePressingOnButtons();

    // then render buttons
    buildBasicTowerBtn->render(renderer);
    buildIceTowerBtn->render(renderer);
    buildFireTowerBtn->render(renderer);
    spawnEnemyBtn->render(renderer);

}

void BasicInterface::handleHoveringOverButtons(){
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
}

void BasicInterface::handlePressingOnButtons(){
    
    // check pressing on buttons
    while(!savedMouseClicks.empty()){
        Coords mouseCoords = savedMouseClicks.front();
        savedMouseClicks.pop();

        if (buildBasicTowerBtn->isPointInRect(mouseCoords)){
            buildBasicTowerBtn->setModePressedOn();
            buildTowerType = BASIC_TOWER;

            if (!towerManager->isBuildModeActive())
                towerManager->activateBuildMode(BASIC_TOWER);
            else
                towerManager->deactivateBuildMode();
            
        }
        else if (buildIceTowerBtn->isPointInRect(mouseCoords)){
            buildIceTowerBtn->setModePressedOn();
            buildTowerType = ICE_TOWER;

            if (!towerManager->isBuildModeActive())
                towerManager->activateBuildMode(ICE_TOWER);
            else
                towerManager->deactivateBuildMode();
        }
        else if (buildFireTowerBtn->isPointInRect(mouseCoords)){
            buildFireTowerBtn->setModePressedOn();
            buildTowerType = FIRE_TOWER;

            if (!towerManager->isBuildModeActive())
                towerManager->activateBuildMode(FIRE_TOWER);
            else
                towerManager->deactivateBuildMode();
        }
        else if (spawnEnemyBtn->isPointInRect(mouseCoords)){

            spawnEnemyBtn->setModePressedOn();
            //TODO change wave
            Wave newWave = getBasicOrcWave(10, 2000);
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
                    towerManager->buildTower(buildTowerType, Coords(mouseCoords.x, mouseCoords.y));
                    towerManager->deactivateBuildMode();
                }
            }
        }
    }
}

// file must be opened in binary mode. Using with other streams is not recommended(unknown result).
void BasicInterface::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving interface stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    
    //TODO add something?
    // save buttons
    buildBasicTowerBtn->saveToBinaryFile(outpustStream);
    buildIceTowerBtn->saveToBinaryFile(outpustStream);
    buildFireTowerBtn->saveToBinaryFile(outpustStream);
    spawnEnemyBtn->saveToBinaryFile(outpustStream);    
}

// file must be opened in binary mode. Using with other streams is not recommended(unknown result).
void BasicInterface::loadFromBinaryFile(istream& inputStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !LOADING_LEVELS_ON)
        cout << "Loading levels is turned off. Loading interface stopped." << endl;

    if (!LOADING_LEVELS_ON)
        return;

    //TODO add something?
    // load buttons
    buildBasicTowerBtn->loadFromBinaryFile(inputStream);
    buildIceTowerBtn->loadFromBinaryFile(inputStream);
    buildFireTowerBtn->loadFromBinaryFile(inputStream);
    spawnEnemyBtn->loadFromBinaryFile(inputStream);   
}
