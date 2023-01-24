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
#include "Button.h"
#include "../Wave.h"
#include "MenuOptionsCodes.h"

using std::queue;

//TODO rename
class BasicInterface:  public Interface{
    public:
    BasicInterface(TowerManager* towerManager, EnemyManager* enemyManager, Renderer* renderer, SoundPlayer* soundPlayer);
    ~BasicInterface();

    MenuOptionsCode handleCursorInteraction();
    void render();

    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void saveToBinaryFile(ostream& outpustStream);
    // file must be opened in binary mode. Using with other streams is not recommended(unknown result).
    void loadFromBinaryFile(istream& inputStream);

    private:   
    
    TowerTypes buildTowerType = BASIC_TOWER;
    Button* exitToMainMenuBtn = nullptr;
    Button* buildBasicTowerBtn = nullptr;
    Button* buildIceTowerBtn = nullptr;
    Button* buildFireTowerBtn = nullptr;
    Button* spawnEnemyBtn = nullptr;

    TowerManager * towerManager = nullptr;
    EnemyManager* enemyManager = nullptr;

    // implement if you want to iterate over buttons
    virtual void createButtonsVec();
    // implement if you want to return different options codes while iterating over buttons
    virtual void createButtonsReturnCodesVec();

    //void handleHoveringOverButtons();
    MenuOptionsCode handlePressingOnButtons();
};
