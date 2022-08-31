
#include "Timers.h"
#include "entityManagers/EnemyManager.h"
#include "entityManagers/TowerManager.h"
#include "EnemiesWay.h"
#include "Grid.h"
#include "Portal.h"
#include "Base.h"

/*main class for game*/
class Game{
    public:
    //TODO add UI
    Game();
    ~Game();

    /*main game function*/
    void loop();
    //TODO change
    void renderAll();

    private:
    
    EnemyManager* enemyManager = nullptr;
    TowerManager* towerManager = nullptr;

    PeriodicTimer* fpsTimer = nullptr;

    EnemiesWay* enemiesWay = nullptr;

    Base* base = nullptr;

    Grid* grid = nullptr;
};