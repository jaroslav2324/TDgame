#pragma once

#include <vector>

#include "../../maths/maths.h"

#include "../grid/Grid.h"
#include "../towers/TowerKinds.h"
#include "../towers/BasicTower.h"
#include "../towers/IceTower.h"
#include "../towers/FireTower.h"

class TowerManager{
    public:
    TowerManager(EnemyManager* enemyManager, Grid* grid);
    ~TowerManager();

    void buildTower(TowerKinds towerType, Coords coords);
    void addBuiltTower(Tower*);
    void destroyTower(Tower*);

    void findAndDeleteDestroyedTowers();

    void allTowersAttack();

    void renderAllTowers(Renderer* renderer);
    void renderAllAttacks(Renderer* renderer);

    void activateBuildMode(TowerKinds buildingTowerType);
    void deactivateBuildMode();
    bool isBuildModeActive();

    // pass coords in the tile, function returns if tower exists in this tile
    bool isTowerExistsInTile(Coords coords);

    private:
    
    std::vector<Tower*> towerList;

    EnemyManager* enemyManager = nullptr;
    Grid* grid = nullptr;

    bool buildModeOn = false;
    // tower sprite in build mode
    Tower* buildingTower = nullptr;
    // render on grid
    void renderBuildingTower(Renderer* renderer);

    // adds tower to towers list
    void createAndAddTower(TowerKinds towerType, Coords coords);
    Tower* createTower(TowerKinds towerType, Coords coords);

};