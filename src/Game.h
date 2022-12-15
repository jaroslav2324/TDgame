
#include <fstream>

#include "Timers.h"
#include "entityManagers/EnemyManager.h"
#include "entityManagers/TowerManager.h"
#include "EnemiesWay.h"
#include "Grid.h"
#include "Portal.h"
#include "Base.h"
#include "UI/GameInterface.h"

using std::cout;
using std::endl;

/*main class for game*/
class Game{
    public:
    Game(SDL_Renderer* renderer);
    ~Game();

    MenuOptionsCode makeFrameTurn(SDL_Renderer* renderer);
    void renderAll(SDL_Renderer* renderer);
    void saveMouseClickCoords(Coords coords);

    private:

    GameInterface* interface = nullptr;
    
    EnemyManager* enemyManager = nullptr;
    TowerManager* towerManager = nullptr;

    PeriodicTimer* fpsTimer = nullptr;

    EnemiesWay* enemiesWay = nullptr;

    Base* base = nullptr;
    Portal* portal = nullptr;

    Grid* grid = nullptr;
};