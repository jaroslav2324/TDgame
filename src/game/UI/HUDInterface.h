#include <vector>
#include <queue>
#include <iostream>
#include <cstdlib>
#include <random>

#include <SDL2/SDL.h>

#include "../../engine/Engine.h"
#include "../../settings.h"
#include "../abstractClasses/Interface.h"
#include "../entityManagers/TowerManager.h"
#include "../entityManagers/EnemyManager.h"
#include "../grid/Grid.h"
#include "Button.h"
#include "../Wave.h"
#include "MenuOptionsCodes.h"

using std::queue;

class HUDInterface:  public Interface{
    public:
    HUDInterface(TowerManager* towerManager, EnemyManager* enemyManager, Grid* grid, Renderer* renderer, SoundPlayer* soundPlayer);
    ~HUDInterface();

    MenuOptionsCode handleCursorInteraction();
    void render();

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    private:   
    
    TowerKinds buildTowerType = BASIC_TOWER;
    Button* exitToMainMenuBtn = nullptr;
    Button* buildBasicTowerBtn = nullptr;
    Button* buildIceTowerBtn = nullptr;
    Button* buildFireTowerBtn = nullptr;
    Button* spawnEnemyBtn = nullptr;

    TowerManager * towerManager = nullptr;
    EnemyManager* enemyManager = nullptr;
    Grid* grid = nullptr;

    // implement if you want to iterate over buttons
    virtual void createButtonsVec();
    // implement if you want to return different options codes while iterating over buttons
    virtual void createButtonsReturnCodesVec();

    //void handleHoveringOverButtons();
    MenuOptionsCode handlePressingOnButtons();
};
