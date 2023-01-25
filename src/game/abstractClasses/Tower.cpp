#include "ProjectileTower.h"

Tower::Tower(EnemyManager* enemyManager, Coords coords){

    this->enemyManager = enemyManager;
    this->towerCoords = coords;

    double exp = 0;
    for (int i = 0; i <= MAX_TOWER_LEVEL; i++){
        listExpForLvls.push_back(exp);
        exp += 100;
    }
}

Tower::Tower(EnemyManager* enemyManager, double damage, double radius, double attackSpeed, int level, Coords coords){

    this->enemyManager = enemyManager;
    this->damage = damage;
    this->radius = radius;
    this->attackSpeed = attackSpeed;
    this->level = level;
    this->towerCoords = coords;

    double exp = 0;
    for (int i = 0; i <= MAX_TOWER_LEVEL; i++){
        listExpForLvls.push_back(exp);
        exp += 100;
    }
}

Tower::~Tower(){
    if (attackTimer != nullptr){
        delete attackTimer;
        attackTimer = nullptr;
    }
}

double Tower::getDamage(){
    return damage;
}

double Tower::getRadius(){
    return radius;
}

TowerType Tower::getTowerType(){
    return towerType;
}

void Tower::setDamage(double damage){
    Tower::damage = damage;
}

void Tower::setRadius(double radius){
    Tower::radius = radius;
}

void Tower::setLevel(int level){
    Tower::level = level;
}

void Tower::setExpForDamage(double exp){
    expForDamage = exp;
}

void Tower::setExpForKill(double exp){
    expForKill = exp;
}

void Tower::setCoords(Coords coords){
    Tower::towerCoords = coords;
}

void Tower::addExperience(double exp){
    experience += exp;
}

double Tower::getExpForNextLvl(int level){
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
    aimedEnemy = enemyManager->findFirstEnemyForTower(towerCoords, radius, aimedEnemiesType);
}

void Tower::findNearestEnemyInRadius(){
    aimedEnemy = enemyManager->findNearestEnemyForTower(towerCoords, radius, aimedEnemiesType);
}

void Tower::setDestroyed(){
    destroyed = true;
}

bool Tower::isDestroyed(){
    if (destroyed)
        return true;
    return false;
}

void Tower::render(Renderer* renderer){

    if (towerCursorInteractionMode == HOVERED_OVER)
        renderRadiusCircle(renderer);

    int x = towerCoords.x - TOWER_SPRITE_SIZE / 2;
    int y = towerCoords.y - TOWER_SPRITE_SIZE / 2;
    SDL_Rect towerRect = {x, y, TOWER_SPRITE_SIZE, TOWER_SPRITE_SIZE};
    renderer->renderTexture(towerTextureType, &towerRect);
}

Coords Tower::getCoords(){
    return towerCoords;
}

void Tower::renderRadiusCircle(Renderer* renderer){
    
    Coords coords = towerCoords;
    renderer->renderFilledCircle(coords, radius, radiusAreaFillColor);
    renderer->renderCircle(coords, radius, radiusColor, 3);
}

void Tower::setModeNoCursorInteraction(){
    towerCursorInteractionMode = NO_INTERACTION;
}

void Tower::setModePressedOn(){
    towerCursorInteractionMode = PRESSED_ON;
    //pressingCooldownTimer->replaceTime(pressingCooldownTime);
}

void Tower::setModeHoveredOver(){
    towerCursorInteractionMode = HOVERED_OVER;
}

bool Tower::isPointInRect(Coords point){
    
    int x1 = towerCoords.x - TOWER_SPRITE_SIZE / 2;
    int y1 = towerCoords.y - TOWER_SPRITE_SIZE / 2;

    int x2 = towerCoords.x + TOWER_SPRITE_SIZE / 2;
    int y2 = towerCoords.y + TOWER_SPRITE_SIZE / 2;

    if (point.x < x1 || point.y < y1 || point.x >= x2 || point.y >= y2)
        return false;
    return true;
}

void Tower::setAttackTimer(){
    if (attackTimer == nullptr)
        attackTimer = new PeriodicTimer(attackSpeed);
    else{
        delete attackTimer;
        attackTimer = new PeriodicTimer(attackSpeed);
    }
}
    