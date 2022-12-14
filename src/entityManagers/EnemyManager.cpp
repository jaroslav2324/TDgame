#include "EnemyManager.h"

EnemyManager::EnemyManager(Base* base, Portal* portal, EnemiesWay* enemiesWay){

    EnemyManager::base = base;
    EnemyManager::portal = portal;

    EnemyManager::enemiesWay = enemiesWay;
}

EnemyManager::~EnemyManager(){
    
    // delete enemies
    int size = enemyList.size();
    for (int i = size - 1; i >= 0; i--){
        if (enemyList[i] != nullptr)
            delete enemyList[i];
        enemyList.pop_back();
    }
}


void EnemyManager::spawnEnemyWithCoords(SDL_Renderer* renderer, int enemyType, Coords coords){
    createAndAddEnemy(renderer, enemyType, coords);
}

void EnemyManager::spawnEnemyAtPortal(SDL_Renderer* renderer, int enemyType){
    Coords coords = portal->getCoords();
    createAndAddEnemy(renderer, enemyType, coords);
}

void EnemyManager::createAndAddEnemy(SDL_Renderer* renderer, int enemyType, Coords coords){
    Enemy* enemy = nullptr;

    switch (enemyType){
    //TODO add types of enemies
    case BASIC_ENEMY:
        enemy = new class BasicEnemy(renderer, enemiesWay, base, portal, coords);
        break;

    default:
        cout << "No such enemy type!(spawn enemy in EnemyManager)" << endl;
    }

    if (enemy != nullptr)
        enemyList.push_back(enemy);
}

void EnemyManager::addSpawnedEnemy(Enemy* enemy){
    enemyList.push_back(enemy);
}

void EnemyManager::killEnemy(Enemy* enemy){

    /*offset to delete enemy from vector*/ 
    int offset = 0;
    for (auto elm = enemyList.front(); elm != enemyList.back(); elm++){
        if (elm == enemy)
            enemyList.erase(enemyList.begin() + offset);
        offset++;
    }
}

/*
coordX, coordY - coords of the tower(not grid coords);
*/
Enemy* EnemyManager::findFirstEnemyForTower(Coords towerCoords, float radius){

    float diffX, diffY;
    float squareDistance, squareRadius;

    for (auto enemy: enemyList){
        diffX = abs(enemy->getCoordX() - towerCoords.x);
        diffY = abs(enemy->getCoordY() - towerCoords.y);

        squareDistance = pow(diffX, 2) + pow(diffY, 2); //between tower and enemy
        squareRadius = pow(radius, 2);

        if (squareDistance < squareRadius)
            return enemy;
    }

    return nullptr;
}


Enemy* EnemyManager::findNearestEnemyForTower(Coords towerCoords, float radius){

    float diffX, diffY;
    float minDiffX, minDiffY;
    float squareDistance, squareRadius;

    Enemy* returnEnemy = nullptr;

    // TODO rewrite this
    for (auto enemy: enemyList){
        diffX = abs(enemy->getCoordX() - towerCoords.x);
        diffY = abs(enemy->getCoordY() - towerCoords.y);

        squareDistance = pow(diffX, 2) + pow(diffY, 2); //between tower and enemy
        squareRadius = pow(radius, 2);

        if (returnEnemy == nullptr)
            if (squareDistance < squareRadius){
                minDiffX = diffX;
                minDiffY = diffY;
                returnEnemy = enemy;
                continue;
            }

        else{
            float minSquareDistance = pow(minDiffX, 2) + pow(minDiffY, 2);
            if (squareDistance < squareRadius && squareDistance < minSquareDistance){
                minDiffX = diffX;
                minDiffY = diffY;
                returnEnemy = enemy;
            }
        }
    }

    return returnEnemy;
}


void EnemyManager::findAndDeleteKilledEnemies(){

    int offset = 0;
    for (auto enemy: enemyList){
        if (enemy->isDead())
            enemyList.erase(enemyList.begin() + offset);
        offset++;
    }
}

void EnemyManager::allEnemiesMove(){
    for (auto enemy: enemyList)
        enemy->move();
}

void EnemyManager::renderAllEnemies(SDL_Renderer* renderer){
    
    for (auto enemyPtr: enemyList)
        enemyPtr->render(renderer);
}