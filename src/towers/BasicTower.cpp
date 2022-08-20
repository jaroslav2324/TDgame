#include "abstractClasses/Tower.cpp"

class BasicTower: public Tower{
    public:
    BasicTower(EnemyManager* enemyManager): Tower(enemyManager){};
};


