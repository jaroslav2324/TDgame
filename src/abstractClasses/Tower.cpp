#include "Tower.h"

Tower::Tower(SDL_Renderer* renderer, EnemyManager* enemyManager, Coords coords){
    //TODO delete SDL_Renderer from constructor or move to fields of the class?

    Tower::enemyManager = enemyManager;
    Tower::towerCoords = coords;

    loadTexture(renderer);

    float exp = 0;
    for (int i = 0; i <= MAX_TOWER_LEVEL; i++){
        listExpForLvls.push_back(exp);
        exp += 100;
    }
}

Tower::Tower(SDL_Renderer* renderer,EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords){
    //TODO delete SDL_Renderer from constructor or move to fields of the class?

    Tower::enemyManager = enemyManager;
    Tower::damage = damage;
    Tower::radius = radius;
    Tower::attackSpeed = attackSpeed;
    Tower::level = level;
    Tower::towerCoords = coords;

    loadTexture(renderer);

    float exp = 0;
    for (int i = 0; i <= MAX_TOWER_LEVEL; i++){
        listExpForLvls.push_back(exp);
        exp += 100;
    }
}

Tower::~Tower(){
    if (towerTexture != nullptr){
        SDL_DestroyTexture(towerTexture);
        towerTexture = nullptr;
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

void Tower::setCoords(Coords coords){
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

void Tower::attack(SDL_Renderer* renderer){

/*move all projectiles and delete if they hit enemy*/
    moveAllProjectiles();

    if(attackTimer->tickIfNeeded()){

        findFirstEnemyInRadius();

        // if enemy found
        if (aimedEnemy != nullptr){

            /*spawn projectile and add it to the list*/
            //TODO change BasicProjectile
            Projectile* projectile = newProjectile(renderer);
            projectileList.push_back(projectile);

            /*add experience for tower*/
            if (aimedEnemy->isDead()){
                aimedEnemy = nullptr;
                int size = projectileList.size();
                for (int i = size - 1; i >= 0; i--){
                    delete projectileList[i];
                    projectileList.pop_back();
                }
                    

                addExperience(expForKill);
            }
            else
                addExperience(expForDamage);

            checkAndLevelUp(); 
        }

    }
    //cout << projectileList.size() << endl;
}

void Tower::moveAllProjectiles(){

    int offset = 0;
    for (auto projectile: projectileList){
        projectile->attack();
        if (projectile->hasDamagedEnemy()){
            delete projectile;
            projectileList.erase(projectileList.begin() + offset);
        }
        offset++;
    }   
   
    //cout << projectileList.size() << endl;
}

void Tower::setDestroyed(){
    destroyed = true;
}

bool Tower::isDestroyed(){
    if (destroyed)
        return true;
    return false;
}

void Tower::loadTexture(SDL_Renderer* renderer){

    if (towerTexture == nullptr)
        towerTexture = IMG_LoadTexture(renderer, BASIC_TOWER_SPRITE_PATH);
    else{
        SDL_DestroyTexture(towerTexture);
        towerTexture = IMG_LoadTexture(renderer, BASIC_TOWER_SPRITE_PATH);
    }    
}

void Tower::render(SDL_Renderer* renderer){

    int x = towerCoords.x - TOWER_SPRITE_SIZE / 2;
    int y = towerCoords.y - TOWER_SPRITE_SIZE / 2;
    SDL_Rect towerRect = {x, y, TOWER_SPRITE_SIZE, TOWER_SPRITE_SIZE};
    SDL_RenderCopy(renderer, towerTexture, 0, &towerRect);
}

void Tower::renderAllProjectiles(SDL_Renderer* renderer){
    for (auto projectilePtr: projectileList)
        projectilePtr->render(renderer);
}

Coords Tower::getCoords(){
    return towerCoords;
}
    