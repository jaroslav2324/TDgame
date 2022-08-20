
#include "abstractClasses/Enemy.cpp"

class BasicEnemy: public Enemy{
    public:
    BasicEnemy(std::string spritePath): Enemy(spritePath){
        setMovementTimer();
    };

    ~BasicEnemy();

    private:
    void setMovementTimer();
    void deleteMovementTimer();
};

BasicEnemy::~BasicEnemy(){
    deleteMovementTimer();
}


void BasicEnemy::setMovementTimer(){
    movementTimer = new Timer(1 / FPS);
}

void BasicEnemy::deleteMovementTimer(){
    delete movementTimer;
}