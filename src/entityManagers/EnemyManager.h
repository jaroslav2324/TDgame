#pragma once

#include <vector>
#include <string>

#include "../EnemyTypes.h"
#include "../enemies/BasicEnemy.h"

using std::string;

class EnemyManager{
    public:
    EnemyManager();
    ~EnemyManager();

    Enemy* findFirstEnemyForTower(std::pair<float, float> towerCoords, float radius);
    Enemy* findNearestEnemyForTower(std::pair<float, float> towerCoords, float radius);
        
    void spawnEnemy(int enemyType);
    //TODO spawnEnemies
    void addSpawnedEnemy(Enemy*);
    void killEnemy(Enemy*);
    void findAndDeleteKilledEnemies();

    void allEnemiesMove();

    private:
    std::vector<Enemy*> enemyList;
};