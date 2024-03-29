#include "ProjectileTower.h"

ProjectileTower::ProjectileTower(EnemyManager* enemyManager, Coords coords): Tower(enemyManager, coords){
    aimedEnemiesType = EnemyTypes::GROUND_ENEMY;
    towerType = TowerType::PROJECTILE_TOWER;
}

ProjectileTower::ProjectileTower(EnemyManager* enemyManager, double damage, double radius, double attackSpeed, int level, Coords coords):
Tower(enemyManager, damage, radius, attackSpeed, level, coords){
    aimedEnemiesType = EnemyTypes::GROUND_ENEMY;
    towerType = TowerType::PROJECTILE_TOWER;
}

ProjectileTower::~ProjectileTower(){
    if (attackTimer != nullptr){
        delete attackTimer;
        attackTimer = nullptr;
    }
}


void ProjectileTower::attack(){

/*move all projectiles and delete if they hit enemy*/
    moveAllProjectiles();

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

        /*spawn projectile and add it to the list*/
        Projectile* projectile = newProjectile();
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

void ProjectileTower::moveAllProjectiles(){

    int offset = 0;
    for (auto projectile: projectileList){
        projectile->attack();
        if (projectile->hasDamagedEnemy()){
            delete projectile;
            projectileList.erase(projectileList.begin() + offset);
            continue;
        }
        offset++;
    }   
   
    //cout << projectileList.size() << endl;
}

void ProjectileTower::renderAllProjectiles(Renderer* renderer){
    for (auto projectilePtr: projectileList)
        projectilePtr->render(renderer);
}
