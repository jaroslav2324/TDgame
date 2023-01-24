#include "TowerManager.h"

TowerManager::TowerManager(EnemyManager* enemyManager){
    TowerManager::enemyManager = enemyManager;
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
void TowerManager::buildTower(TowerTypes towerType, Coords mouseCoords){

    int x, y;
    x = (int)mouseCoords.x - (int)mouseCoords.x % TILESIZE + TILESIZE / 2;
    y = (int)mouseCoords.y - (int)mouseCoords.y % TILESIZE + TILESIZE / 2;
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

void TowerManager::renderAllTowers(Renderer* renderer){

    // check cursor hovering over towers
    int x, y;
    SDL_GetMouseState(&x, &y);
    Coords mouseCoords(x, y);

    // render towers
    for (auto towerPtr: towerList){

        if (towerPtr->isPointInRect(mouseCoords))
            towerPtr->setModeHoveredOver();
        else
            towerPtr->setModeNoCursorInteraction();

        towerPtr->render(renderer);

    }

    if (buildModeOn)
        renderBuildingTower(renderer);
}

void TowerManager::renderBuildingTower(Renderer* renderer){

    if (buildingTower == nullptr)
        return;

    int mouseX, mouseY;
    int x, y;

    SDL_GetMouseState(&mouseX, &mouseY);
    x = mouseX - mouseX % TILESIZE + TILESIZE / 2;
    y = mouseY - mouseY % TILESIZE + TILESIZE / 2;

    buildingTower->setCoords(Coords(x, y));
    buildingTower->render(renderer);
}


void TowerManager::renderAllAttacks(Renderer* renderer){

    ProjectileTower* projPtr = nullptr;
    LaserTower* laserPtr = nullptr;
    SplashwaveTower* splashPtr = nullptr;
    
    //TODO add towers
    for (auto towerPtr: towerList){
        //TODO rewrite?

        projPtr = dynamic_cast<ProjectileTower*>(towerPtr);
        if (projPtr != nullptr){
            projPtr->renderAllProjectiles(renderer);
            continue;
        }

        laserPtr = dynamic_cast<LaserTower*>(towerPtr);
        if (laserPtr != nullptr){
            laserPtr->renderLaser(renderer);
            continue;
        }

        splashPtr = dynamic_cast<SplashwaveTower*>(towerPtr);
        if (splashPtr != nullptr){
            splashPtr->renderSplashWave(renderer);
            continue;
        }

        if (DEBUG_CONSOLE_OUTPUT_ON)
            cout << "No dynamic cast " << endl;
    }
}

void TowerManager::activateBuildMode(TowerTypes buildingTowerType){

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

void TowerManager::createAndAddTower(TowerTypes towerType, Coords coords){

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

Tower* TowerManager::createTower(TowerTypes towerType, Coords coords){

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
