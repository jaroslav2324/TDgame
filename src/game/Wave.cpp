#include "Wave.h"

Wave getBasicWave(uint amount, double msSpawnPeriod){
    Wave wave;
    int waveLen = amount;

    for (int i = 0; i < waveLen; i ++)
        wave.listEnemiesTypes.push_back(BASIC_ENEMY);

    wave.spawnPeriod = msSpawnPeriod;

    return wave;
}

Wave getOrcWave(uint amount, double msSpawnPeriod){
    Wave wave;
    int waveLen = amount;

    for (int i = 0; i < waveLen; i ++)
        wave.listEnemiesTypes.push_back(ORC_ENEMY);

    wave.spawnPeriod = msSpawnPeriod;

    return wave;
}

Wave getBasicOrcWave(uint amount, double msSpawnPeriod){

    Wave wave;
    int waveLen = amount;
    bool isOrc = false;

    for (int i = 0; i < waveLen; i ++){

        if (isOrc){
            wave.listEnemiesTypes.push_back(ORC_ENEMY);
            isOrc = false;
        }
        else{
            wave.listEnemiesTypes.push_back(BASIC_ENEMY);
            isOrc = true; 
        }
    }

    wave.spawnPeriod = msSpawnPeriod;

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
