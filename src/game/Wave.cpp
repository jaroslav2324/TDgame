#include "Wave.h"

Wave getBasicTestWave(){
    Wave wave;
    int waveLen = 5;

    for (int i = 0; i < waveLen; i ++)
        wave.listEnemiesTypes.push_back(ORC_ENEMY);

    wave.spawnPeriod = 2000;

    return wave;
}

void Wave::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving enemy wave stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    
    // save spawnning period
    outpustStream.write((char*)&spawnPeriod, sizeof(spawnPeriod));

    // save list of enemies types
    for (auto enemyType: listEnemiesTypes)
        outpustStream.write((char*)&enemyType, sizeof(enemyType));
}

void Wave::loadFromBinaryFile(istream& inputStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !LOADING_LEVELS_ON)
        cout << "Loading levels is turned off. Loading enemy wave stopped." << endl;

    if (!LOADING_LEVELS_ON)
        return;

    // load spawnning period
    inputStream.read((char*)&spawnPeriod, sizeof(spawnPeriod));

    EnemyTypes type;
    // load list of enemies types
    for (auto enemyType: listEnemiesTypes){
        inputStream.read((char*)&type, sizeof(type));
        listEnemiesTypes.push_back(type);
    }
}
