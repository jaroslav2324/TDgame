#pragma once

#include <vector>

#include "../../maths/maths.h"

#include "../towers/TowerTypes.h"
#include "../towers/BasicTower.h"
#include "../towers/IceTower.h"
#include "../towers/FireTower.h"

class TowerManager{
    public:
    TowerManager(EnemyManager* enemyManager);
    ~TowerManager();

    void buildTower(TowerTypes towerType, Coords coords);
    void addBuiltTower(Tower*);
    void destroyTower(Tower*);

    void findAndDeleteDestroyedTowers();

    void allTowersAttack();

    void renderAllTowers(Renderer* renderer);
    void renderAllAttacks(Renderer* renderer);

    void activateBuildMode(TowerTypes buildingTowerType);
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
    void renderBuildingTower(Renderer* renderer);

    // adds tower to towers list
    void createAndAddTower(TowerTypes towerType, Coords coords);
    Tower* createTower(TowerTypes towerType, Coords coords);

};