#pragma once

#include <vector>
#include <string>

#include "../EnemyTypes.h"
#include "../enemies/BasicEnemy.h"
#include "../Portal.h"

using std::string;

class EnemyManager{
    public:
    EnemyManager(Base* base, EnemiesWay* enemiesWay);
    ~EnemyManager();

    Enemy* findFirstEnemyForTower(std::pair<float, float> towerCoords, float radius);
    Enemy* findNearestEnemyForTower(std::pair<float, float> towerCoords, float radius);
        
    void spawnEnemy(int enemyType);
    //TODO spawnEnemies
    void addSpawnedEnemy(Enemy*);
    void killEnemy(Enemy*);
    void findAndDeleteKilledEnemies();

    void allEnemiesMove();

    void renderAllEnemies(SDL_Renderer* renderer);

    private:
    std::vector<Enemy*> enemyList;

    //TODO initialise portal
    Portal* portal = nullptr;
    Base* base = nullptr;

    EnemiesWay* enemiesWay = nullptr;

    //TODO create class spawner
};