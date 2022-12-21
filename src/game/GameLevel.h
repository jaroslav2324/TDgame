
#include <fstream>

#include "../Timers.h"
#include "../entityManagers/EnemyManager.h"
#include "../entityManagers/TowerManager.h"
#include "EnemiesWay.h"
#include "Grid.h"
#include "Portal.h"
#include "Base.h"
#include "../UI/BasicInterface.h"

using std::cout;
using std::endl;

class GameLevel{
    public:
    GameLevel();
    ~GameLevel();

    MenuOptionsCode makeFrameTurn();
    void renderAll(Renderer* renderer);
    void saveMouseClickCoords(Coords coords);

    private:

    BasicInterface* interface = nullptr;
    
    EnemyManager* enemyManager = nullptr;
    TowerManager* towerManager = nullptr;


    PeriodicTimer* fpsTimer = nullptr;

    EnemiesWay* enemiesWay = nullptr;

    Base* base = nullptr;
    Portal* portal = nullptr;

    Grid* grid = nullptr;
};