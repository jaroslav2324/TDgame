#include "BasicInterface.h"

BasicInterface::BasicInterface(TowerManager* towerManager, EnemyManager* enemyManager, Renderer* renderer, SoundPlayer* soundPlayer){

    this->renderer = renderer;
    this->soundPlayer = soundPlayer;

    this->towerManager = towerManager;
    this->enemyManager = enemyManager;

    //TODO change button textures
    exitToMainMenuBtn = new Button(Coords(50, 25), renderer, soundPlayer);
    buildBasicTowerBtn = new Button(Coords(50, 300), renderer, soundPlayer);
    buildIceTowerBtn = new Button(Coords(50, 450), renderer, soundPlayer);
    buildFireTowerBtn = new Button(Coords(50, 600), renderer, soundPlayer);                                   
    spawnEnemyBtn = new Button(Coords(600, 40), renderer, soundPlayer);

    createButtonsVec();
    createButtonsReturnCodesVec();    
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

    if (exitToMainMenuBtn != nullptr){
        delete exitToMainMenuBtn;
        exitToMainMenuBtn = nullptr;
    }
}

MenuOptionsCode BasicInterface::handleCursorInteraction(){
    handleHoveringOverButtons();
    return handlePressingOnButtons();
}

void BasicInterface::render(){

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

    // then render buttons
    renderButtons(renderer);
}

MenuOptionsCode BasicInterface::handlePressingOnButtons(){
    
    MenuOptionsCode code = NO_CHANGES;
    // check pressing on buttons
    while(!savedMouseClicks.empty()){
        Coords mouseCoords = savedMouseClicks.front();
        savedMouseClicks.pop();

        if (buildBasicTowerBtn->isPointInRect(mouseCoords)){
            buildBasicTowerBtn->setModeAndPlaySound(ObjectCursorInteractionsModes::PRESSED_ON);
            buildTowerType = BASIC_TOWER;

            if (!towerManager->isBuildModeActive())
                towerManager->activateBuildMode(BASIC_TOWER);
            else
                towerManager->deactivateBuildMode();
            
        }
        else if (buildIceTowerBtn->isPointInRect(mouseCoords)){
            buildIceTowerBtn->setModeAndPlaySound(ObjectCursorInteractionsModes::PRESSED_ON);
            buildTowerType = ICE_TOWER;

            if (!towerManager->isBuildModeActive())
                towerManager->activateBuildMode(ICE_TOWER);
            else
                towerManager->deactivateBuildMode();
        }
        else if (buildFireTowerBtn->isPointInRect(mouseCoords)){
            buildFireTowerBtn->setModeAndPlaySound(ObjectCursorInteractionsModes::PRESSED_ON);
            buildTowerType = FIRE_TOWER;

            if (!towerManager->isBuildModeActive())
                towerManager->activateBuildMode(FIRE_TOWER);
            else
                towerManager->deactivateBuildMode();
        }
        else if (spawnEnemyBtn->isPointInRect(mouseCoords)){

            spawnEnemyBtn->setModeAndPlaySound(ObjectCursorInteractionsModes::PRESSED_ON);

            enemyManager->startSpawning();
        }
        else if (exitToMainMenuBtn->isPointInRect(mouseCoords)){
            exitToMainMenuBtn->setModeAndPlaySound(ObjectCursorInteractionsModes::PRESSED_ON);
            code = QUIT_TO_MAIN_MENU;
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

    return code;
}

void BasicInterface::createButtonsVec(){
    buttonsVec.push_back(exitToMainMenuBtn);
    buttonsVec.push_back(buildBasicTowerBtn);
    buttonsVec.push_back(buildIceTowerBtn);
    buttonsVec.push_back(buildFireTowerBtn);
    buttonsVec.push_back(spawnEnemyBtn);
}

void BasicInterface::createButtonsReturnCodesVec(){
    buttonsReturnCodesVec.push_back(MenuOptionsCode::QUIT_TO_MAIN_MENU);
    buttonsReturnCodesVec.push_back(MenuOptionsCode::NO_CHANGES);
    buttonsReturnCodesVec.push_back(MenuOptionsCode::NO_CHANGES);
    buttonsReturnCodesVec.push_back(MenuOptionsCode::NO_CHANGES);
    buttonsReturnCodesVec.push_back(MenuOptionsCode::NO_CHANGES);
}

// file must be opened in binary mode. Using with other streams is not recommended(unknown result).
void BasicInterface::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving interface stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    
    //TODO add something?
    // save buttons
    exitToMainMenuBtn->saveToBinaryFile(outpustStream);
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
    exitToMainMenuBtn->loadFromBinaryFile(inputStream);
    buildBasicTowerBtn->loadFromBinaryFile(inputStream);
    buildIceTowerBtn->loadFromBinaryFile(inputStream);
    buildFireTowerBtn->loadFromBinaryFile(inputStream);
    spawnEnemyBtn->loadFromBinaryFile(inputStream);   
}
