#include "TowerManager.h"

TowerManager::TowerManager(EnemyManager* enemyManager, Grid* grid){
    this->enemyManager = enemyManager;
    this->grid = grid;
}

TowerManager::~TowerManager(){

    // delete towers
    int size = towerList.size();
    for (int i = size - 1; i >= 0; i--){
        if (towerList[i] != nullptr)
            delete towerList[i];
        towerList.pop_back();
    }
    
    if (buildingTower != nullptr){
        delete buildingTower;
        buildingTower = nullptr;
    }
}

// pass any coords, these coords will be converted to right grid coords
void TowerManager::buildTower(TowerKinds towerType, Coords mouseCoords){

    int x, y;
    Coords gridStartCoords = grid->getStartCoords();

    x = mouseCoords.x - gridStartCoords.x;
    x = x / TILESIZE * TILESIZE + TILESIZE / 2;
    x += gridStartCoords.x;

    y = mouseCoords.y - gridStartCoords.y;
    y = y / TILESIZE * TILESIZE + TILESIZE / 2;
    y += gridStartCoords.y;

    Coords towerCoords(x, y);
    
    createAndAddTower(towerType, towerCoords);

}

void TowerManager::addBuiltTower(Tower* tower){
    towerList.push_back(tower);
}

void TowerManager::destroyTower(Tower* tower){

    /*offset to delete tower from vector*/ 
    int offset = 0;
    for (auto elm = towerList.front(); elm != towerList.back(); elm++){
        if (elm == tower){
            towerList.erase(towerList.begin() + offset);
            elm = nullptr;
        }
        offset++;
    }
}

void TowerManager::findAndDeleteDestroyedTowers(){

    int offset = 0;
    for (auto tower: towerList){
        if (tower->isDestroyed())
            towerList.erase(towerList.begin() + offset);
        offset++;
    }
}

void TowerManager::allTowersAttack(){

    for (auto tower: towerList){
        tower->attack();
    }
}

void TowerManager::checkTowerHoveredOver(){
    // check cursor hovering over towers
    //TODO get from SystemEventsHandler
    int x, y;
    SDL_GetMouseState(&x, &y);
    Coords mouseCoords(x, y);

    for (auto towerPtr: towerList){

        if (towerPtr->isPointInRect(mouseCoords))
            towerPtr->setModeHoveredOver();
        else
            towerPtr->setModeNoCursorInteraction();
    }
}

void TowerManager::renderAllTowers(Renderer* renderer){

    // render towers
    for (auto towerPtr: towerList)
        towerPtr->render(renderer);

    if (buildModeOn)
        renderBuildingTower(renderer);
}

void TowerManager::renderTowerRadiusIfHoveredOver(Renderer* renderer){
    for (auto towerPtr: towerList)
        towerPtr->renderRadiusZoneIfHoveredOver(renderer);
}

void TowerManager::renderBuildingTower(Renderer* renderer){

    if (buildingTower == nullptr)
        return;

    int mouseX, mouseY;
    int x, y;

    Coords gridStartCoords = grid->getStartCoords();

    SDL_GetMouseState(&mouseX, &mouseY);
    x = mouseX - gridStartCoords.x;
    x = x / TILESIZE * TILESIZE + TILESIZE / 2;
    x += gridStartCoords.x;

    y = mouseY - gridStartCoords.y;
    y = y / TILESIZE * TILESIZE + TILESIZE / 2;
    y += gridStartCoords.y;

    buildingTower->setCoords(Coords(x, y));
    buildingTower->render(renderer);
}


void TowerManager::renderAllAttacks(Renderer* renderer){

    ProjectileTower* projPtr = nullptr;
    LaserTower* laserPtr = nullptr;
    SplashwaveTower* splashPtr = nullptr;
    
    //TODO add towers
    for (auto towerPtr: towerList){

        if (towerPtr->getTowerType() == TowerType::PROJECTILE_TOWER){
            projPtr = (ProjectileTower*)towerPtr;
            projPtr->renderAllProjectiles(renderer);
            continue;
        }

        if (towerPtr->getTowerType() == TowerType::LASER_TOWER){
            laserPtr = (LaserTower*)towerPtr;
            laserPtr->renderLaser(renderer);
            continue;
        }

        if (towerPtr->getTowerType() == TowerType::SPLASHWAVE_TOWER){
            splashPtr = (SplashwaveTower*)towerPtr;
            splashPtr->renderSplashWave(renderer);
            continue;
        }

        if (towerPtr->getTowerType() == TowerType::UNDEFINED_TYPE){
            if (DEBUG_CONSOLE_OUTPUT_ON)
                cout << CoutTextColors::RED << "TOWER WITH UNDEFINED TYPE" << endl << CoutTextColors::RESET;
        }

    }
}

void TowerManager::activateBuildMode(TowerKinds buildingTowerType){

    buildModeOn = true;

    if (buildingTower != nullptr)
        delete buildingTower;

    int x, y;
    SDL_GetMouseState(&x, &y);
    Coords towerCoords(x, y);

    buildingTower = createTower(buildingTowerType, towerCoords);
    buildingTower->setDamage(0);
}

void TowerManager::deactivateBuildMode(){

    buildModeOn = false;

    if (buildingTower != nullptr){
        delete buildingTower;
        buildingTower = nullptr;
    }
}

bool TowerManager::isBuildModeActive(){
    return buildModeOn;
}

bool TowerManager::isTowerExistsInTile(Coords coords)
{
    int x, y;
    x = (int)coords.x - (int)coords.x % TILESIZE + TILESIZE / 2;
    y = (int)coords.y - (int)coords.y % TILESIZE + TILESIZE / 2;
    Coords c(x, y);

    for (auto tower: towerList)
        if(ifCoordsApprEqual(c, tower->getCoords()))
            return true;

    return false;
}

void TowerManager::createAndAddTower(TowerKinds towerType, Coords coords){

    Tower* tower = nullptr;
        //TODO add types of towers
    switch (towerType)
    {
    case BASIC_TOWER:
        tower = new BasicTower(enemyManager, coords);
        break;
    case ICE_TOWER:
        tower = new IceTower(enemyManager, coords);
        break;
    case FIRE_TOWER:
        tower = new FireTower(enemyManager, coords);
        break;
    default:
        if (DEBUG_CONSOLE_OUTPUT_ON)
            cout << "NO TOWER WAS CREATED. ADD MORE TYPES TO TOWER MANAGER." << endl;
        break;
    }
    towerList.push_back(tower);
}

Tower* TowerManager::createTower(TowerKinds towerType, Coords coords){

    Tower* tower = nullptr;
        //TODO add types of towers
    switch (towerType)
    {
    case BASIC_TOWER:
        tower = new BasicTower(enemyManager, coords);
        break;
    case ICE_TOWER:
        tower = new IceTower(enemyManager, coords);
        break;
    case FIRE_TOWER:
        tower = new FireTower(enemyManager, coords);
        break;
    default:
        if (DEBUG_CONSOLE_OUTPUT_ON)
            cout << "NO TOWER WAS CREATED. ADD MORE TYPES TO TOWER MANAGER." << endl;
        break;
    }
    return tower;
}
