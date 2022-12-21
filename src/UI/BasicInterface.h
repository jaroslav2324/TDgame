#include <vector>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <random>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../settings.h"
#include "../abstractClasses/Interface.h"
#include "../entityManagers/TowerManager.h"
#include "../entityManagers/EnemyManager.h"
#include "Button.h"
#include "../game/Wave.h"
#include "MenuOptionsCodes.h"

using std::queue;

class BasicInterface:  public Interface{
    public:
    BasicInterface(TowerManager* towerManager, EnemyManager* enemyManager);
    ~BasicInterface();
    void render(Renderer* renderer);
    //void saveMouseClickCoords(Coords coords);

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    private:   
    
    TowerTypes buildTowerType = BASIC_TOWER;
    Button* buildBasicTowerBtn = nullptr;
    Button* buildIceTowerBtn = nullptr;
    Button* buildFireTowerBtn = nullptr;
    Button* spawnEnemyBtn = nullptr;

    TowerManager * towerManager = nullptr;
    EnemyManager* enemyManager = nullptr;

    //queue<Coords> savedMouseClicks;

    void handleHoveringOverButtons();
    void handlePressingOnButtons();
};
