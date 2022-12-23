#include "EnemyManager.h"

EnemyManager::EnemyManager(Base* base, Portal* portal, EnemiesWay* enemiesWay){

    sortingTimer = new PeriodicTimer(500);

    EnemyManager::base = base;
    EnemyManager::portal = portal;

    EnemyManager::enemiesWay = enemiesWay;
}

EnemyManager::~EnemyManager(){
    
    // delete enemies
    int size = enemyList.size();
    for (int i = size - 1; i >= 0; i--){
        if (enemyList[i] != nullptr)
            delete enemyList[i];
        enemyList.pop_back();
    }

    if (sortingTimer != nullptr){
        delete sortingTimer;
        sortingTimer = nullptr;
    }

    if (countdownBeforeWaveTimer != nullptr){
        delete countdownBeforeWaveTimer;
        countdownBeforeWaveTimer = nullptr;
    }
}


void EnemyManager::spawnEnemyWithCoords(int enemyType, Coords coords){
    createAndAddEnemy(enemyType, coords);
}

void EnemyManager::spawnEnemyAtPortal(int enemyType){
    Coords coords = portal->getCoords();
    createAndAddEnemy(enemyType, coords);
}

void EnemyManager::createAndAddEnemy(int enemyType, Coords coords){
    Enemy* enemy = nullptr;

    switch (enemyType){
    //TODO add types of enemies
    case BASIC_ENEMY:
        enemy = new class BasicEnemy(enemiesWay, base, portal, coords);
        break;
    case ORC_ENEMY:
        enemy = new class OrcEnemy(enemiesWay, base, portal, coords);
        break;

    default:
        cout << "No such enemy type!(spawn enemy in EnemyManager)" << endl;
    }

    if (enemy != nullptr)
        enemyList.push_back(enemy);
}

void EnemyManager::addSpawnedEnemy(Enemy* enemy){
    enemyList.push_back(enemy);
}

void EnemyManager::killEnemy(Enemy* enemy){

    /*offset to delete enemy from vector*/ 
    int offset = 0;
    for (auto elm = enemyList.front(); elm != enemyList.back(); elm++){
        if (elm == enemy)
            enemyList.erase(enemyList.begin() + offset);
        offset++;
    }
}

Enemy* EnemyManager::findFirstEnemyForTower(Coords towerCoords, float radius){

    float diffX, diffY;
    float squareDistance, squareRadius;

    sortEnemiesWithSortingTimer();

    Coords enemyCoords;
    for (auto enemy: enemyList){
        enemyCoords = enemy->getCoords();
        diffX = abs(enemyCoords.x - towerCoords.x);
        diffY = abs(enemyCoords.y - towerCoords.y);

        squareDistance = pow(diffX, 2) + pow(diffY, 2); //between tower and enemy
        squareRadius = pow(radius, 2);

        if (squareDistance < squareRadius)
            return enemy;
    }

    return nullptr;
}

Enemy* EnemyManager::findNearestEnemyForTower(Coords towerCoords, float radius){

    float diffX, diffY;
    float minDiffX, minDiffY;
    float squareDistance, squareRadius;

    Enemy* returnEnemy = nullptr;

    Coords enemyCoords;
    // TODO rewrite this(why?)
    for (auto enemy: enemyList){
        enemyCoords = enemy->getCoords();
        diffX = abs(enemyCoords.x - towerCoords.x);
        diffY = abs(enemyCoords.y - towerCoords.y);
        
        squareDistance = pow(diffX, 2) + pow(diffY, 2); //between tower and enemy
        squareRadius = pow(radius, 2);

        if (returnEnemy == nullptr)
            if (squareDistance < squareRadius){
                minDiffX = diffX;
                minDiffY = diffY;
                returnEnemy = enemy;
                continue;
            }

        else{
            float minSquareDistance = pow(minDiffX, 2) + pow(minDiffY, 2);
            if (squareDistance < squareRadius && squareDistance < minSquareDistance){
                minDiffX = diffX;
                minDiffY = diffY;
                returnEnemy = enemy;
            }
        }
    }

    return returnEnemy;
}

void EnemyManager::findAndDeleteKilledEnemies(){

    int offset = 0;
    for (auto enemy: enemyList){
        if (enemy->isDead()){
            enemyList.erase(enemyList.begin() + offset);
            continue;
        }
        offset++;
    }
}

void EnemyManager::allEnemiesMove(){
    for (auto enemy: enemyList)
        enemy->move();
}

void EnemyManager::renderAllEnemies(Renderer* renderer){
    
    for (auto enemyPtr: enemyList)
        enemyPtr->render(renderer);
}

void EnemyManager::setWave(Wave wave){
    currentWave = wave;
}

void EnemyManager::spawnEnemiesInWave(){
    
    if (currentWave.listEnemiesTypes.size() <= 0){

        if (enemyInWaveSpawnTimer != nullptr){
            delete enemyInWaveSpawnTimer;
            enemyInWaveSpawnTimer = nullptr;
        }

        // if (DEBUG_CONSOLE_OUTPUT_ON)
        //     cout << "List of spawn enemies is empty. Use setWave to set new wave of enemies." << endl;
        return;
    }

    if (enemyInWaveSpawnTimer == nullptr){
        enemyInWaveSpawnTimer = new PeriodicTimer(currentWave.spawnPeriod);
        // to start wave just after setting the wave
        enemyInWaveSpawnTimer->setFrameTime(currentWave.spawnPeriod);
        //cout << enemyInWaveSpawnTimer;
    }

    //cout << enemyInWaveSpawnTimer;
    if (enemyInWaveSpawnTimer->tickIfNeeded()){

        int enemyType = currentWave.listEnemiesTypes.front();
        currentWave.listEnemiesTypes.pop_front();
        spawnEnemyAtPortal(enemyType);
        
        if(DEBUG_CONSOLE_OUTPUT_ON)
            cout << "Enemy has been spawned" << endl;
    }
}

void EnemyManager::startSpawning(){

    if (startedSpawning){
        if (DEBUG_CONSOLE_OUTPUT_ON)
            cout << "Spawning enemies has been started already" << endl;
        return;
    }

    // TODO replace if needed
    listOfSpawningWaves = getListWaves1();

    startedSpawning = true;
    currentWave = listOfSpawningWaves.front();
    listOfSpawningWaves.pop_front();
    countdownBeforeWaveTimer = new CountdownTimer(currentWave.countdownBeforeWave);

}

void EnemyManager::spawnEnemiesIfStarted(){

    if (!startedSpawning)
        return;

    // wave has ended
    if (countdownBeforeWaveTimer->isCountdownEnd() && currentWave.size() <= 0){

        if (listOfSpawningWaves.size() > 0){
            currentWave = listOfSpawningWaves.front();
            listOfSpawningWaves.pop_front();

            delete countdownBeforeWaveTimer;
            countdownBeforeWaveTimer = new CountdownTimer(currentWave.countdownBeforeWave);

            if (enemyInWaveSpawnTimer != nullptr){
                delete enemyInWaveSpawnTimer;
                enemyInWaveSpawnTimer = nullptr;
            }
        }
        else
            return;
    }

    // spawn enemy
    if (countdownBeforeWaveTimer->isCountdownEnd()){

        if (enemyInWaveSpawnTimer == nullptr)
            enemyInWaveSpawnTimer = new PeriodicTimer(currentWave.spawnPeriod);

        if (enemyInWaveSpawnTimer->tickIfNeeded()){

            int enemyType = currentWave.listEnemiesTypes.front();
            currentWave.listEnemiesTypes.pop_front();
            spawnEnemyAtPortal(enemyType);
            
            if(DEBUG_CONSOLE_OUTPUT_ON)
                cout << "Enemy has been spawned" << endl;
        }
    }

}

void EnemyManager::sortEnemiesWithSortingTimer(){

    int sizeVector = enemyList.size();

    if(sortingTimer->tickIfNeeded()){
        // bubble sort
        for (int i = 0; i < sizeVector - 1; i++)
            for (int j = 0; j < sizeVector - 1; j++){
                
                int numNextWaypoint1 = enemyList[i]->getNumNextWaypoint();
                int numNextWaypoint2 = enemyList[j]->getNumNextWaypoint();

                if (numNextWaypoint1 > numNextWaypoint2)
                    swap(enemyList[i], enemyList[j]);
                

                if (numNextWaypoint1 == numNextWaypoint2){

                    Coords coords1 = enemyList[i]->getCoords();
                    Coords coords2 = enemyList[j]->getCoords();
                    Coords coordsNextWaypoint = enemiesWay->getWaypointCoords(numNextWaypoint1);

                    if (distance(coords1, coordsNextWaypoint) < distance(coords2, coordsNextWaypoint))
                        swap(enemyList[i], enemyList[j]);
                }
            }
        }
}
