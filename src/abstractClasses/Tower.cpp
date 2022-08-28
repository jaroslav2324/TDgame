#pragma once

#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include "settings.h"
#include "Timers.h"
#include "Enemy.cpp"
#include "Projectile.cpp"
#include "./EnemyManager.cpp"

using std::string;


/*Basic class for all towers*/
class Tower{
public:
    Tower(EnemyManager* enemyManager);
    Tower(EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level);

    virtual void setAttackTimer() = 0;

    //TODO change exp in derived classes
    void setExpForDamage(float exp);
    void setExpForKill(float exp);
    
    float getDamage();
    float getRadius();
    //int getLevel();

    void attack();

    bool isDestroyed();
    void setDestroyed();

    // TODO void loadSprite() = 0;
    //TODO render
    float getExpForNextLvl(int currentLevel);

protected:
    float damage = 0;
    double freezeMultyplyer = 0;
    double freezeTime = 0;
    float radius = 0;

    int level = 0;
    float experience = 0;
    float expForNextLvl = 0;

    float expForDamage = 0;
    float expForKill = 0;

    //in milliseconds
    float attackSpeed = 0;
    
    //TODO set coords
    std::pair<float, float> towerCoords;

    //TODO grid coords getters and setters
    int gridCoordX = 0;
    int gridCoordY = 0;

    //TODO add UI to destroy tower
    bool destroyed = false;

    PeriodicTimer* attackTimer = nullptr;

    EnemyManager* enemyManager = nullptr;
    Enemy* aimedEnemy = nullptr;

    SDL_Texture* towerSprite = nullptr;

    //FIXME [] for vector?
    std::vector<float> listExpForLvls[MAXLEVEL + 1];

    std::vector<Projectile*> projectileList;

    void findFirstEnemyInRadius();
    void findNearestEnemyInRadius();

    void addExperience(float exp);
    void checkAndLevelUp();

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

Tower::Tower(EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level){

    Tower::enemyManager = enemyManager;
    Tower::damage = damage;
    Tower::radius = radius;
    Tower::attackSpeed = attackSpeed;
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

void Tower::setExpForDamage(float exp){
    expForDamage = exp;
}

void Tower::setExpForKill(float exp){
    expForKill = exp;
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
    aimedEnemy = enemyManager->findFirstEnemyForTower(towerCoords, radius);
}

void Tower::findNearestEnemyInRadius(){
    aimedEnemy = enemyManager->findNearestEnemyForTower(towerCoords, radius);
}

void Tower::attack(){

    //TODO move projectile

    if(attackTimer->tickIfNeeded()){

        findFirstEnemyInRadius();

        /*spawn projectile and add it to the list*/
        Projectile* projectile = new Projectile(this, aimedEnemy, towerCoords);
        projectileList.push_back(projectile);

        /*move all projectiles and delete if they hit enemy*/
        int offset = 0;
        for (auto proj: projectileList){
            proj->attack();
            if(proj->hasDamagedEnemy()){
                delete proj;
                projectileList.erase(projectileList.begin() + offset);
            }
            offset++;
        }

        
        /*add experience for tower*/
        if (aimedEnemy->isDead()){
            aimedEnemy = nullptr;
            addExperience(expForKill);
        }
        else
            addExperience(expForDamage);

        checkAndLevelUp(); 
    }
}

void Tower::setDestroyed(){
    destroyed = true;
}

bool Tower::isDestroyed(){
    if (destroyed)
        return true;
    return false;
}