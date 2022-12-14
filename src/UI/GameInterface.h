#include <vector>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <random>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../settings.h"
#include "../entityManagers/TowerManager.h"
#include "../entityManagers/EnemyManager.h"
#include "Button.h"
#include "../Wave.h"

using std::queue;

class GameInterface{
    public:
    GameInterface(SDL_Renderer* renderer, TowerManager* towerManager, EnemyManager* enemyManager);
    ~GameInterface();
    void render(SDL_Renderer* renderer);
    void saveMouseClickCoords(Coords coords);
    private:   
    
    Button* buildTowerBtn = nullptr;
    Button* spawnEnemyBtn = nullptr;

    TowerManager * towerManager = nullptr;
    EnemyManager* enemyManager = nullptr;

    queue<Coords> savedMouseClicks;
};
