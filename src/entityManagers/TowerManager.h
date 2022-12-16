#pragma once

#include <vector>

#include "../towers/TowerTypes.h"
#include "../towers/BasicTower.h"
#include "../towers/IceTower.h"
#include "../towers/FireTower.h"
#include "../approximateComparison.h"

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

    void activateBuildMode(SDL_Renderer* renderer, TowerTypes buildingTowerType);
    void deactivateBuildMode();
    bool isBuildModeActive();

    // pass coords in the tile, function returns if tower exists in this tile
    bool isTowerExistsInTile(Coords coords);

    private:
    std::vector<Tower*> towerList;
    EnemyManager* enemyManager = nullptr;

    bool buildModeOn = false;
    // tower sprite in build mode
    Tower* buildingTower = nullptr;
    // render on grid
    void renderBuildingTower(SDL_Renderer* renderer);

};