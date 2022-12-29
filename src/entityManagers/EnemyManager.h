#pragma once

#include <sstream>
#include <iomanip>
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

    //TODO add type of enemies
    Enemy* findFirstEnemyForTower(Coords towerCoords, double radius);
    //TODO add type of enemies
    Enemy* findNearestEnemyForTower(Coords towerCoords, double radius);
    //TODO add type of enemies
    list<Enemy*> findAllEnemiesForTower(Coords towerCoords, double radius);
        
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
    PeriodicTimer* enemyInWaveSpawnTimer = nullptr;
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