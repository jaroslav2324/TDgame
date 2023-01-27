#pragma once

#include <sstream>
#include <iomanip>
#include <vector>
#include <list>
#include <string>
#include <utility>

#include "../enemies/EnemyKinds.h"
#include "../enemies/BasicEnemy.h"
#include "../enemies/OrcEnemy.h"
#include "../grid/Portal.h"
#include "../Wave.h"

using std::list;
using std::string;
using std::swap;

class EnemyManager{
    public:
    EnemyManager(Base* base, Portal* portal, EnemiesWay* enemiesWay);
    ~EnemyManager();

    Enemy* findFirstEnemyForTower(Coords towerCoords, double radius, EnemyTypes enemyType = EnemyTypes::ANY_TYPE_ENEMY);
    // not used
    Enemy* findNearestEnemyForTower(Coords towerCoords, double radius, EnemyTypes enemyType = EnemyTypes::ANY_TYPE_ENEMY);
    
    list<Enemy*> findAllEnemiesForTower(Coords towerCoords, double radius, EnemyTypes enemyType = EnemyTypes::ANY_TYPE_ENEMY);
        
    /*use for custom spawning. For wave spawning use */
    void spawnEnemyWithCoords(int enemyType, Coords coords);
    void spawnEnemyAtPortal(int enemyType);

    /*Set wave of enemies. spawnPeriod in milliseconds*/
    void setWave(Wave wave);
    void startSpawning();
    void spawnEnemiesIfStarted();

    void addSpawnedEnemy(Enemy*);
    void killEnemy(Enemy*);
    void findAndDeleteKilledEnemies();

    void allEnemiesMove();

    void renderAll(Renderer* renderer);

    private:
    std::vector<Enemy*> enemyList;

    Portal* portal = nullptr;
    Base* base = nullptr;

    EnemiesWay* enemiesWay = nullptr;

    Wave currentWave;
    list<Wave> listOfSpawningWaves;
    bool startedSpawning = false;

    // Controls frequency of spawning
    CountdownTimer* enemyInWaveSpawnTimer = nullptr;
    //timer before wave start
    CountdownTimer* countdownBeforeWaveTimer = nullptr;
    // used for sorting enemies by distance to the base
    PeriodicTimer* sortingTimer = nullptr;

    void createAndAddEnemy(int enemyType, Coords coords);

    void sortEnemiesWithSortingTimer();
    
    /* use for test if needed
    Spawn enemies with spawn period until there are enemies to spawn (at portal position)*/
    void spawnEnemiesInWave();
};