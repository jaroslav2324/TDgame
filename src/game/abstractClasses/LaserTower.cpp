#include "LaserTower.h"

LaserTower::LaserTower(EnemyManager* enemyManager, Coords coords): Tower(enemyManager, coords){
    aimedEnemiesType = EnemyTypes::ANY_TYPE_ENEMY;
}

LaserTower::LaserTower(EnemyManager* enemyManager, double damage, double radius, double attackSpeed, int level, Coords coords):
Tower(enemyManager, damage, radius, attackSpeed, level, coords){
    aimedEnemiesType = EnemyTypes::ANY_TYPE_ENEMY;
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

void LaserTower::renderLaser(Renderer* renderer){
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
