#include "abstractClasses/Tower.cpp"

class BasicTower: public Tower{
    public:
    BasicTower(EnemyManager* enemyManager): Tower(enemyManager){
        // TODO attackSpeed
        setAttackTimer();
    };
    ~BasicTower();

    private:
    void setAttackTimer();
    void deleteAttackTimer();
};

BasicTower::~BasicTower(){
    deleteAttackTimer();
}

void BasicTower::setAttackTimer(){
    attackTimer = new PeriodicTimer(attackSpeed);
}

void BasicTower::deleteAttackTimer(){
    delete attackTimer;
}

