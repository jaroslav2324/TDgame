#pragma once

#include <vector>
#include <string>

#include "EnemyTypes.h"
#include "abstractClasses/Enemy.cpp"
#include "enemies/BasicEnemy.cpp"

using std::string;

class EnemyManager{
    public:
    EnemyManager();
    ~EnemyManager();

    Enemy* findFirstEnemyForTower(float coordX, float coordY, float radius);
    Enemy* findNearestEnemyForTower(float coordX, float coordY, float radius);
        
    void spawnEnemy(int enemyType);
    void addSpawnedEnemy(Enemy*);
    //and delete
    void killEnemy(Enemy*);
    void findAndDeleteKilledEnemies();

    void allEnemiesMove();

    private:
    std::vector<Enemy*> enemyList;
};

EnemyManager::EnemyManager(){

}

EnemyManager::~EnemyManager(){

    for (auto elm = enemyList.front(); elm != enemyList.back(); elm++)
        delete elm;
}


void EnemyManager::spawnEnemy(int enemyType){
    //TODO add types of enemies
    Enemy* enemy = nullptr;
    if (enemyType == BASIC_ENEMY)
    //TODO change sprite path
        enemy = new class BasicEnemy("");

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
Enemy* EnemyManager::findFirstEnemyForTower(float coordX, float coordY, float radius){

    float diffX, diffY;
    float squareDistance, squareRadius;

    for (auto enemy: enemyList){
        diffX = abs(enemy->getCoordX() - coordX);
        diffY = abs(enemy->getCoordY() - coordY);

        squareDistance = pow(diffX, 2) + pow(diffY, 2); //between tower and enemy
        squareRadius = pow(radius, 2);

        if (squareDistance < squareRadius)
            return enemy;
    }

    return nullptr;
}


Enemy* EnemyManager::findNearestEnemyForTower(float coordX, float coordY, float radius){

    float diffX, diffY;
    float minDiffX, minDiffY;
    float squareDistance, squareRadius;

    Enemy* returnEnemy = nullptr;

    for (auto enemy: enemyList){
        diffX = abs(enemy->getCoordX() - coordX);
        diffY = abs(enemy->getCoordY() - coordY);

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
            
    return returnEnemy;
    }
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

