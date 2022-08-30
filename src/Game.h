
#include "Timers.h"
#include "entityManagers/EnemyManager.h"
#include "entityManagers/TowerManager.h"

/*class for game*/
class Game{
    public:
    //TODO add UI
    Game();
    ~Game();

    /*main game function*/
    void loop();
    void renderAll();

    private:

    //TODO grid
    //TODO enemies way
    //TODO Portal
    //TODO Base
    
    EnemyManager* enemyManager = nullptr;
    TowerManager* towerManager = nullptr;

    PeriodicTimer* fpsTimer = nullptr;

};