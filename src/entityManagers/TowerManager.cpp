#include "TowerManager.h"

TowerManager::TowerManager(EnemyManager* enemyManager){
    TowerManager::enemyManager = enemyManager;
}

void TowerManager::buildTower(SDL_Renderer* renderer, int towerType, std::pair<float, float> coords){
    //TODO add types of towers
    Tower* tower = nullptr;
    if (towerType == BASIC_TOWER)
        tower = new class BasicTower(renderer, enemyManager, coords);

    towerList.push_back(tower);
}

void TowerManager::addBuiltTower(Tower* tower){
    towerList.push_back(tower);
}

void TowerManager::destroyTower(Tower* tower){

    /*offset to delete tower from vector*/ 
    int offset = 0;
    for (auto elm = towerList.front(); elm != towerList.back(); elm++){
        if (elm == tower)
            towerList.erase(towerList.begin() + offset);
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
    for (auto tower: towerList)
        tower->attack(renderer);
}

void TowerManager::renderAllTowers(SDL_Renderer* renderer){
    
    for (auto towerPtr: towerList)
        towerPtr->render(renderer);
}

void TowerManager::renderAllProjectiles(SDL_Renderer* renderer){
    
    for (auto towerPtr: towerList)
        towerPtr->renderAllProjectiles(renderer);
}