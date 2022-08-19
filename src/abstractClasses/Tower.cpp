#pragma once

#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include "settings.h"
#include "Enemy.cpp"
#include "./EnemyManager.cpp"

using std::string;


/*Basic class for all towers*/
class Tower{
public:
    Tower(EnemyManager* enemyManager);
    Tower(EnemyManager* enemyManager, float damage, float radius, int level);
    
    float getDamage();
    float getRadius();
    //int getLevel();

    void addExperience(float exp);
    void checkAndLevelUp();

    void findFirstEnemyInRadius();
    void findNearestEnemyInRadius();
    void hitEnemy();

    // TODO void loadSprite() = 0;
    float getExpForNextLvl(int currentLevel);

protected:
    float damage = 0;
    float radius = 0;
    int level = 0;
    float experience = 0;
    float expForNextLvl = 0;
    
    //TODO grid coords getters and setters
    float coordX = 0;
    float coordY = 0;
    int gridCoordX = 0;
    int gridCoordY = 0;

    EnemyManager* enemyManager = nullptr;
    Enemy* aimedEnemy = nullptr;

    SDL_Texture* towerSprite = nullptr;

    std::vector<float> listExpForLvls[MAXLEVEL + 1];

    void setDamage(float damage);
    void setRadius(float radius);
    void setLevel(int level);
};



Tower::Tower(EnemyManager* enemyManager){

    Tower::enemyManager = enemyManager;

    float e = 0;
    for (auto expForLvl = listExpForLvls->front(); expForLvl != listExpForLvls->back(); expForLvl++){
        expForLvl = e;
        e += 100;
    }
}

Tower::Tower(EnemyManager* enemyManager, float damage, float radius, int level){

    Tower::enemyManager = enemyManager;
    Tower::damage = damage;
    Tower::radius = radius;
    Tower::level = level;

    float e = 0;
    for (auto expForLvl = listExpForLvls->front(); expForLvl != listExpForLvls->back(); expForLvl++){
        expForLvl = e;
        e += 100;
    }
}

float Tower::getDamage(){
    return damage;
}

float Tower::getRadius(){
    return radius;
}

void Tower::setDamage(float damage){
    Tower::damage = damage;
}

void Tower::setRadius(float radius){
    Tower::radius = radius;
}

void Tower::setLevel(int level){
    Tower::level = level;
}

void Tower::addExperience(float exp){
    experience += exp;
}

void Tower::checkAndLevelUp(){
    if (experience > expForNextLvl){
        experience -= expForNextLvl;
        level++;
        expForNextLvl = getExpForNextLvl(level);
    }
}


void Tower::findFirstEnemyInRadius(){
    aimedEnemy = enemyManager->findFirstEnemyForTower(coordX, coordY, radius);
}

void Tower::findNearestEnemyInRadius(){
    aimedEnemy = enemyManager->findNearestEnemyForTower(coordX, coordY, radius);
}

void Tower::hitEnemy(){

    if (aimedEnemy != nullptr){
        aimedEnemy->applyDamage(damage);

        if (aimedEnemy->isDead())
            aimedEnemy = nullptr;
        
    } 
}
