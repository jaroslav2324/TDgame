#pragma once

#include <vector>
#include <string>

#include "../EnemyTypes.h"
#include "../enemies/BasicEnemy.h"
#include "../Portal.h"

using std::string;

class EnemyManager{
    public:
    EnemyManager(Base* base, Portal* portal, EnemiesWay* enemiesWay);
    ~EnemyManager();

    Enemy* findFirstEnemyForTower(Coords towerCoords, float radius);
    Enemy* findNearestEnemyForTower(Coords towerCoords, float radius);
        
    void spawnEnemyWithCoords(SDL_Renderer* renderer, int enemyType, Coords coords);
    void spawnEnemyAtPortal(SDL_Renderer* renderer, int enemyType);
    //TODO spawnEnemies
    void addSpawnedEnemy(Enemy*);
    void killEnemy(Enemy*);
    void findAndDeleteKilledEnemies();

    void allEnemiesMove();

    void renderAllEnemies(SDL_Renderer* renderer);

    private:
    std::vector<Enemy*> enemyList;

    Portal* portal = nullptr;
    Base* base = nullptr;

    EnemiesWay* enemiesWay = nullptr;

    void createAndAddEnemy(SDL_Renderer* renderer, int enemyType, Coords coords);
    //TODO create class spawner
};