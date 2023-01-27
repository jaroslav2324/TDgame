#include "Wave.h"

int Wave::size(){
    return listEnemiesTypes.size();
}

Wave getBasicWave(uint amount, double countdownBeforeWave, int countdownBeforeEachEnemy){

    vector<int> vectorCountdownsBeforeEachEnemy;

    for (int i = 0; i < amount; i++)
        vectorCountdownsBeforeEachEnemy.push_back(countdownBeforeEachEnemy);

    return getBasicWave(amount, countdownBeforeWave, vectorCountdownsBeforeEachEnemy);
}

Wave getBasicWave(uint amount, double countdownBeforeWave, vector<int> vectorCountdownsBeforeEachEnemy){

    Wave wave;
    wave.countdownBeforeWave = countdownBeforeWave;

    int waveLen = amount;

    for (int i = 0; i < waveLen; i ++){
        wave.listEnemiesTypes.push_back(BASIC_ENEMY);
        wave.listCountdownBeforeEnemies.push_back(vectorCountdownsBeforeEachEnemy[i]);
    }

    return wave;
}

Wave getOrcWave(uint amount, double countdownBeforeWave, int countdownBeforeEachEnemy){

    vector<int> vectorCountdownsBeforeEachEnemy;

    for (int i = 0; i < amount; i++)
        vectorCountdownsBeforeEachEnemy.push_back(countdownBeforeEachEnemy);

    return getOrcWave(amount, countdownBeforeWave, vectorCountdownsBeforeEachEnemy);
}

Wave getOrcWave(uint amount, double countdownBeforeWave, vector<int> vectorCountdownsBeforeEachEnemy){

    Wave wave;
    wave.countdownBeforeWave = countdownBeforeWave;

    int waveLen = amount;

    for (int i = 0; i < waveLen; i ++){
        wave.listEnemiesTypes.push_back(ORC_ENEMY);
        wave.listCountdownBeforeEnemies.push_back(vectorCountdownsBeforeEachEnemy[i]);
    }

    return wave;
}

Wave getBasicOrcWave(uint amount, double countdownBeforeWave, int countdownBeforeEachEnemy){

    vector<int> vectorCountdownsBeforeEachEnemy;

    for (int i = 0; i < amount; i++)
        vectorCountdownsBeforeEachEnemy.push_back(countdownBeforeEachEnemy);

    return getBasicOrcWave(amount, countdownBeforeWave, vectorCountdownsBeforeEachEnemy);
}

Wave getBasicOrcWave(uint amount, double countdownBeforeWave, vector<int> vectorCountdownsBeforeEachEnemy){

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
        wave.listCountdownBeforeEnemies.push_back(vectorCountdownsBeforeEachEnemy[i]);
    }

    return wave;
}

list<Wave> getListWaves1(){
    
    list<Wave> listOfWaves;

    listOfWaves.push_back(getBasicWave(5, 5000, 1000));
    listOfWaves.push_back(getOrcWave(5, 8000, 1500));
    listOfWaves.push_back(getBasicOrcWave(8, 10000, 500));
    listOfWaves.push_back(getBasicWave(12, 12000, 300));
    listOfWaves.push_back(getOrcWave(12, 12000, 1000));

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
    //TODO add countdownBeforeWave, each enemy

    // save list of enemies types
    for (auto enemyType: listEnemiesTypes)
        outpustStream.write((char*)&enemyType, sizeof(enemyType));
}

void Wave::loadFromBinaryFile(istream& inputStream){

    if (DEBUG_CONSOLE_OUTPUT_ON && !LOADING_LEVELS_ON)
        cout << "Loading levels is turned off. Loading enemy wave stopped." << endl;

    if (!LOADING_LEVELS_ON)
        return;
    //TODO add countdownBeforeWave, each enemy

    EnemyKinds type;
    // load list of enemies types
    for (auto enemyType: listEnemiesTypes){
        inputStream.read((char*)&type, sizeof(type));
        listEnemiesTypes.push_back(type);
    }
}
