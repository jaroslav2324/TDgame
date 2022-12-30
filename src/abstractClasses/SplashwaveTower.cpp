#include "SplashwaveTower.h"

SplashwaveTower::SplashwaveTower(EnemyManager* enemyManager, Coords coords): Tower(enemyManager, coords){
    aimedEnemiesType = EnemyTypes::FLYING_ENEMY;
}

SplashwaveTower::SplashwaveTower(EnemyManager* enemyManager, double damage, double radius, double attackSpeed, int level, Coords coords):
Tower(enemyManager, damage, radius, attackSpeed, level, coords){
    aimedEnemiesType = EnemyTypes::FLYING_ENEMY;
}

SplashwaveTower::~SplashwaveTower(){
    if (attackTimer != nullptr){
        delete attackTimer;
        attackTimer = nullptr;
    }
}


void SplashwaveTower::attack(){

    findAllEnemiesInRadius();

    int amountEnemies = listOfAimedEnemies.size();

    if (amountEnemies == 0 && attackTimer == nullptr)
        return;

    if (amountEnemies == 0 && attackTimer != nullptr){
        if (attackTimer->tickIfNeeded()){
            delete attackTimer;
            attackTimer = nullptr;
        }
        return;
    }

    if (amountEnemies != 0 && attackTimer == nullptr){
        attackTimer = new PeriodicTimer(attackSpeed);
        attackTimer->setFrameTime(attackSpeed);
    }

    if(attackTimer->tickIfNeeded()){

        for (auto aimedEnemy: listOfAimedEnemies){

            aimedEnemy->applyDamage(damage);

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
}

void SplashwaveTower::render(Renderer* renderer){

    if (towerCursorInteractionMode == HOVERED_OVER)
        renderRadiusCircle(renderer);

    int x = towerCoords.x - TOWER_SPRITE_SIZE / 2;
    int y = towerCoords.y - TOWER_SPRITE_SIZE / 2;
    SDL_Rect towerRect = {x, y, TOWER_SPRITE_SIZE, TOWER_SPRITE_SIZE};
    renderer->renderTexture(towerTextureType, &towerRect);
}

void SplashwaveTower::findAllEnemiesInRadius(){
    listOfAimedEnemies = enemyManager->findAllEnemiesForTower(towerCoords, radius, aimedEnemiesType);
}

void SplashwaveTower::renderSplashWave(Renderer* renderer){

    if (attackTimer == nullptr)
        return;

    double timerTime = attackTimer->getTime();
    double timerPeriod = attackTimer->getCountPeriod();
    int frontPosition = (int)((fmod(timerTime, timerPeriod) /  timerPeriod) * radius);

    //TODO refactor
    if (frontPosition > 0)
        renderer->renderCircle(towerCoords, frontPosition, frontWaveColor);

    if (frontPosition - 1 > 0){
        Uint8 r = (frontWaveColor.r + endWaveColor.r) / 2;
        Uint8 g = (frontWaveColor.g + endWaveColor.g) / 2;
        Uint8 b = (frontWaveColor.b + endWaveColor.b) / 2;
        Uint8 a = (frontWaveColor.a + endWaveColor.a) / 2;
        SDL_Color middleColor = {r, g, b, a};
        renderer->renderCircle(towerCoords, frontPosition - 1, middleColor);
    }
    if (frontPosition - 2 > 0)
        renderer->renderCircle(towerCoords, frontPosition - 2, endWaveColor);

}

