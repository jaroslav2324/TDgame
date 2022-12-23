#include "Wave.h"

int Wave::size(){
    return listEnemiesTypes.size();
}

Wave getBasicWave(uint amount, double msSpawnPeriod, double countdownBeforeWave){

    Wave wave;
    wave.countdownBeforeWave = countdownBeforeWave;

    int waveLen = amount;


    for (int i = 0; i < waveLen; i ++)
        wave.listEnemiesTypes.push_back(BASIC_ENEMY);

    wave.spawnPeriod = msSpawnPeriod;

    return wave;
}

Wave getOrcWave(uint amount, double msSpawnPeriod, double countdownBeforeWave){

    Wave wave;
    wave.countdownBeforeWave = countdownBeforeWave;

    int waveLen = amount;

    for (int i = 0; i < waveLen; i ++)
        wave.listEnemiesTypes.push_back(ORC_ENEMY);

    wave.spawnPeriod = msSpawnPeriod;

    return wave;
}

Wave getBasicOrcWave(uint amount, double msSpawnPeriod, double countdownBeforeWave){

    Wave wave;
    wave.countdownBeforeWave = countdownBeforeWave;

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

list<Wave> getListWaves1(){
    
    list<Wave> listOfWaves;

    listOfWaves.push_back(getBasicWave(5, 1500, 5000));
    listOfWaves.push_back(getOrcWave(5, 1500, 8000));
    listOfWaves.push_back(getBasicOrcWave(8, 1500, 10000));
    listOfWaves.push_back(getBasicWave(12, 1000, 12000));
    listOfWaves.push_back(getOrcWave(12, 1000, 12000));

    return listOfWaves;
}

list<Wave> getListWaves2(){
    // TODO implement
}

list<Wave> getListWaves3(){
    // TODO implement
}

void Wave::saveToBinaryFile(ostream& outpustStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !SAVING_LEVELS_ON)
        cout << "Saving levels is turned off. Saving enemy wave stopped." << endl;

    if (!SAVING_LEVELS_ON)
        return;
    //TODO add countdownBeforeWave
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
    //TODO add countdownBeforeWave
    // load spawnning period
    inputStream.read((char*)&spawnPeriod, sizeof(spawnPeriod));

    EnemyTypes type;
    // load list of enemies types
    for (auto enemyType: listEnemiesTypes){
        inputStream.read((char*)&type, sizeof(type));
        listEnemiesTypes.push_back(type);
    }
}
