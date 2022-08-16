#include <vector>
#include <string>

#include "EnemyTypes.h"
#include "abstractClasses/Enemy.cpp"
#include "enemies/BasicEnemy.cpp"

using std::string;

class EnemyManager{
    public:
    EnemyManager();
    ~EnemyManager();
        
    void spawnEnemy(int enemyType);
    void addSpawnedEnemy(Enemy*);
    void killEnemy(Enemy*);

    private:
    std::vector<Enemy*> enemiesList;
};

EnemyManager::EnemyManager(){

}

EnemyManager::~EnemyManager(){

    for (auto elm = enemiesList.front(); elm != enemiesList.back(); elm++)
        delete elm;
}


void EnemyManager::spawnEnemy(int enemyType){
    //TODO add types of enemies
    Enemy* enemy = nullptr;
    if (enemyType == BASIC)
        enemy = new class BasicEnemy;

    enemiesList.push_back(enemy);
}

void EnemyManager::addSpawnedEnemy(Enemy* enemy){
    enemiesList.push_back(enemy);
}

void EnemyManager::killEnemy(Enemy* enemy){

    /*offset to delete enemy from vector*/ 
    int offset = 0;
    for (auto elm = enemiesList.front(); elm != enemiesList.back(); elm++){
        if (elm == enemy)
            enemiesList.erase(enemiesList.begin() + offset);
        offset++;
    }
}

