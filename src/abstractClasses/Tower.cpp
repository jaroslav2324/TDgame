#include "Tower.h"

Tower::Tower(EnemyManager* enemyManager){

    Tower::enemyManager = enemyManager;

    float exp = 0;
    for (int i = 0; i <= MAX_TOWER_LEVEL; i++){
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
    for (int i = 0; i <= MAX_TOWER_LEVEL; i++){
        listExpForLvls.push_back(exp);
        exp += 100;
    }
}

Tower::~Tower(){
    if (towerSprite != nullptr)
        SDL_DestroyTexture(towerSprite);
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

void Tower::setCoords(std::pair<float, float> coords){
    Tower::towerCoords = coords;
}

void Tower::setGridCoords(std::pair<int, int> gridCoords){
    Tower::gridCoords = gridCoords;
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

void Tower::loadSprite(SDL_Renderer* renderer){

    towerSprite = IMG_LoadTexture(renderer, TEST_SPRITE_PATH);    
}

void Tower::render(SDL_Renderer* renderer){

    //TODO move to constructor
    if(towerSprite == nullptr)
        loadSprite(renderer);

    int x = towerCoords.first - TOWER_SPRITE_SIZE / 2;
    int y = towerCoords.second - TOWER_SPRITE_SIZE / 2;
    SDL_Rect towerRect = {x, y, TOWER_SPRITE_SIZE, TOWER_SPRITE_SIZE};
    SDL_RenderCopy(renderer, towerSprite, 0, &towerRect);
}
    