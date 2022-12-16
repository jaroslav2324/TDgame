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
void TowerManager::buildTower(SDL_Renderer* renderer, int towerType, Coords coords){

    int x, y;
    x = (int)coords.x - (int)coords.x % TILESIZE + TILESIZE / 2;
    y = (int)coords.y - (int)coords.y % TILESIZE + TILESIZE / 2;
    
    //TODO add types of towers
    Tower* tower = nullptr;
    switch(towerType){

        case BASIC_TOWER:
            tower = new class BasicTower(renderer, enemyManager, Coords(x, y));
            break;

            case ICE_TOWER:
            tower = new class IceTower(renderer, enemyManager, Coords(x, y));
            break;

            case FIRE_TOWER:
            tower = new class FireTower(renderer, enemyManager, Coords(x, y));
            break;

        default:
        if (DEBUG_CONSOLE_OUTPUT_ON)
            cout << "NO TOWER WAS BUILT. ADD MORE TYPES TO TOWER MANAGER." << endl;
    }

    towerList.push_back(tower);
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

void TowerManager::allTowersAttack(SDL_Renderer* renderer){
    //TODO remove SDL_Renderer
    for (auto tower: towerList){
        tower->attack(renderer);
        //tower->moveAllProjectiles();
    }
}

void TowerManager::renderAllTowers(SDL_Renderer* renderer){

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

void TowerManager::renderBuildingTower(SDL_Renderer* renderer){

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


void TowerManager::renderAllProjectiles(SDL_Renderer* renderer){
    
    for (auto towerPtr: towerList)
        towerPtr->renderAllProjectiles(renderer);
}

void TowerManager::activateBuildMode(SDL_Renderer* renderer, TowerTypes buildingTowerType){

    buildModeOn = true;

    if (buildingTower != nullptr)
        delete buildingTower;

    int x, y;
    SDL_GetMouseState(&x, &y);
    // TODO change renderer(remove)
    switch (buildingTowerType)
    {
    case BASIC_TOWER:
        buildingTower = new BasicTower(renderer, enemyManager, Coords(x, y));
        break;
    case ICE_TOWER:
        buildingTower = new IceTower(renderer, enemyManager, Coords(x, y));
        break;
    case FIRE_TOWER:
        buildingTower = new FireTower(renderer, enemyManager, Coords(x, y));
        break;
    default:
        break;
    }
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
