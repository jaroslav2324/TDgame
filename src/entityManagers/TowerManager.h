#pragma once

#include <vector>

#include "../TowerTypes.h"
#include "../towers/BasicTower.h"

class TowerManager{
    public:
    TowerManager(EnemyManager* enemyManager);
    ~TowerManager();

    void buildTower(SDL_Renderer* renderer, int towerType, Coords coords);
    void addBuiltTower(Tower*);
    void destroyTower(Tower*);

    void findAndDeleteDestroyedTowers();

    void allTowersAttack(SDL_Renderer* renderer);

    void renderAllTowers(SDL_Renderer* renderer);
    void renderAllProjectiles(SDL_Renderer* renderer);

    void activateBuildMode(SDL_Renderer* renderer);
    void deactivateBuildMode();
    bool isBuildModeActive();

    private:
    std::vector<Tower*> towerList;
    EnemyManager* enemyManager = nullptr;

    // TODO buildModeFlag, buildingTower
    bool buildModeOn = false;
    // tower sprite in build mode
    Tower* buildingTower = nullptr;
    // render on grid
    void renderBuildingTower(SDL_Renderer* renderer);

};