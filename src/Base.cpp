

class Base{
    public:
    Base();

    int getHitPoits();
    void setHitPoints(int hitPoints);
    bool noHitPoitsLeft();

    void applyDamage(int damage);
    //TODO end game

    //TODO loadSprite

    private:
    int hitPoints;
};

Base::Base(){

}

int Base::getHitPoits(){
    return hitPoints;
}

void Base::setHitPoints(int hitPoints){
    Base::hitPoints = hitPoints;
}

void Base::applyDamage(int damage){
    hitPoints -= damage;
}

bool Base::noHitPoitsLeft(){
    if (hitPoints <= 0)
        return true;
    return false;
}