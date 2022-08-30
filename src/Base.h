#pragma once

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