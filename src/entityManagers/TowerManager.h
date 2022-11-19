#pragma once

#include <vector>

#include "../TowerTypes.h"
#include "../towers/BasicTower.h"

class TowerManager{
    public:
    TowerManager(EnemyManager* enemyManager);

    void buildTower(int towerType);
    void addBuiltTower(Tower*);
    void destroyTower(Tower*);

    void findAndDeleteDestroyedTowers();

    void allTowersAttack();

    void renderAllTowers(SDL_Renderer* renderer);

    private:
    std::vector<Tower*> towerList;
    EnemyManager* enemyManager = nullptr;
};