#include "Tower.h"

Tower::Tower(EnemyManager* enemyManager){

    Tower::enemyManager = enemyManager;

    float exp = 0;
    for (int i = 0; i <= MAXLEVEL; i++){
        listExpForLvls.push_back(exp);
        exp += 100;
    }
}

Tower::Tower(EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level){

    Tower::enemyManager = enemyManager;
    Tower::damage = damage;
    Tower::radius = radius;
    Tower::attackSpeed = attackSpeed;
    Tower::level = level;

    float exp = 0;
    for (int i = 0; i <= MAXLEVEL; i++){
        listExpForLvls.push_back(exp);
        exp += 100;
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

float Tower::getExpForNextLvl(int level){
    return listExpForLvls[level];
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

    if(attackTimer->tickIfNeeded()){

        findFirstEnemyInRadius();

        /*spawn projectile and add it to the list*/
        Projectile* projectile = new Projectile(aimedEnemy, towerCoords);
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