
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
    Game(SDL_Renderer* renderer);
    ~Game();

    /*main game function*/
    void loop(SDL_Renderer* renderer);
    //TODO change
    void renderAll(SDL_Renderer* renderer);

    private:
    
    EnemyManager* enemyManager = nullptr;
    TowerManager* towerManager = nullptr;

    PeriodicTimer* fpsTimer = nullptr;

    EnemiesWay* enemiesWay = nullptr;

    Base* base = nullptr;

    Grid* grid = nullptr;
};