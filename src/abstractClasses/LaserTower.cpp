#include "LaserTower.h"

LaserTower::LaserTower(EnemyManager* enemyManager, Coords coords): Tower(enemyManager, coords){

    this->enemyManager = enemyManager;
    this->towerCoords = coords;

    float exp = 0;
    for (int i = 0; i <= MAX_TOWER_LEVEL; i++){
        listExpForLvls.push_back(exp);
        exp += 100;
    }

    setAttackTimer();
}

LaserTower::LaserTower(EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords):
Tower(enemyManager, damage, radius, attackSpeed, level, coords){

    this->enemyManager = enemyManager;
    this->damage = damage;
    this->radius = radius;
    this->attackSpeed = attackSpeed;
    this->level = level;
    this->towerCoords = coords;

    float exp = 0;
    for (int i = 0; i <= MAX_TOWER_LEVEL; i++){
        listExpForLvls.push_back(exp);
        exp += 100;
    }
}

LaserTower::~LaserTower(){
    if (attackTimer != nullptr){
        delete attackTimer;
        attackTimer = nullptr;
    }
}


void LaserTower::attack(){

    findFirstEnemyInRadius();

    if (aimedEnemy == nullptr && attackTimer == nullptr)
        return;

    if (aimedEnemy == nullptr && attackTimer != nullptr){
        if (attackTimer->tickIfNeeded()){
            delete attackTimer;
            attackTimer = nullptr;
        }
        return;
    }

    if (aimedEnemy != nullptr && attackTimer == nullptr){
        attackTimer = new PeriodicTimer(attackSpeed);
        attackTimer->setFrameTime(attackSpeed);
    }

    if(attackTimer->tickIfNeeded()){

        aimedEnemy->applyDamage(damage * attackTimer->getCountPeriod() / 1000);

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


void LaserTower::render(Renderer* renderer){

    if (towerCursorInteractionMode == HOVERED_OVER)
        renderRadiusCircle(renderer);

    int x = towerCoords.x - TOWER_SPRITE_SIZE / 2;
    int y = towerCoords.y - TOWER_SPRITE_SIZE / 2;
    SDL_Rect towerRect = {x, y, TOWER_SPRITE_SIZE, TOWER_SPRITE_SIZE};
    renderer->renderTexture(towerTextureType, &towerRect);
}

void LaserTower::renderLaser(Renderer* renderer){
    //TODO implement animation in renderer
    if (aimedEnemy != nullptr){
        Coords enemyCoords = aimedEnemy->getCoords();
        renderer->renderLine(towerCoords, enemyCoords, laserColor, laserWidth);
    }
}

void LaserTower::setLaserColor(SDL_Color color){
    laserColor = color;
}

void LaserTower::setLaserWidth(int width){
    laserWidth = width;
}

void LaserTower::setAttackTimer(){
    if (attackTimer != nullptr)
        delete attackTimer;
    attackTimer = new PeriodicTimer(100);
}