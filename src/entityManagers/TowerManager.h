#pragma once

#include <vector>

#include "../TowerTypes.h"
#include "../towers/BasicTower.h"

class TowerManager{
    public:
    TowerManager(EnemyManager* enemyManager);

    void buildTower(SDL_Renderer* renderer, int towerType);
    void addBuiltTower(Tower*);
    void destroyTower(Tower*);

    void findAndDeleteDestroyedTowers();

    void allTowersAttack(SDL_Renderer* renderer);

    void renderAllTowers(SDL_Renderer* renderer);
    void renderAllProjectiles(SDL_Renderer* renderer);

    private:
    std::vector<Tower*> towerList;
    EnemyManager* enemyManager = nullptr;
};