#pragma once

#include <vector>
#include <list>
#include <string>
#include <utility>

#include "../enemies/EnemyTypes.h"
#include "../enemies/BasicEnemy.h"
#include "../enemies/OrcEnemy.h"
#include "../game/Portal.h"
#include "../game/Wave.h"

using std::list;
using std::string;
using std::swap;

class EnemyManager{
    public:
    EnemyManager(Base* base, Portal* portal, EnemiesWay* enemiesWay);
    ~EnemyManager();

    Enemy* findFirstEnemyForTower(Coords towerCoords, float radius);
    Enemy* findNearestEnemyForTower(Coords towerCoords, float radius);
        
    /*use for custom spawning. For wave spawning use */
    void spawnEnemyWithCoords(int enemyType, Coords coords);
    void spawnEnemyAtPortal(int enemyType);

    /*Set wave of enemies. spawnPeriod in milliseconds*/
    void setWave(Wave wave);
    /*Spawn enemies with spawn period until there are enemies to spawn (at portal position)*/
    void spawnEnemiesInWave();

    void addSpawnedEnemy(Enemy*);
    void killEnemy(Enemy*);
    void findAndDeleteKilledEnemies();

    void allEnemiesMove();

    void renderAllEnemies(Renderer* renderer);

    private:
    std::vector<Enemy*> enemyList;

    Portal* portal = nullptr;
    Base* base = nullptr;

    EnemiesWay* enemiesWay = nullptr;

    Wave currentWave;

    // Controls frequency of spawning
    PeriodicTimer* enemyInWaveSpawnTimer = nullptr;
    // TODO add timer before wave start
    // used for sorting enemies by distance to the base
    PeriodicTimer* sortingTimer = nullptr;

    void createAndAddEnemy(int enemyType, Coords coords);

    void sortEnemiesWithSortingTimer();
};