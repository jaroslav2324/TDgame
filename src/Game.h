
#include "Timers.h"
#include "entityManagers/EnemyManager.h"
#include "entityManagers/TowerManager.h"
#include "EnemiesWay.h"
#include "Grid.h"
#include "Portal.h"
#include "Base.h"
#include "UI/Interface.h"

/*main class for game*/
class Game{
    public:
    //TODO add UI
    Game(SDL_Renderer* renderer);
    ~Game();

    /*main game function*/
    void loop(SDL_Renderer* renderer);
    void renderAll(SDL_Renderer* renderer);

    private:

    Interface* interface = nullptr;
    
    EnemyManager* enemyManager = nullptr;
    TowerManager* towerManager = nullptr;

    PeriodicTimer* fpsTimer = nullptr;

    EnemiesWay* enemiesWay = nullptr;

    Base* base = nullptr;

    Grid* grid = nullptr;
};