#pragma once

class Base{
    public:
    //TODO spawnCoords in constructor
    //TODO add interaction with end game interfase
    Base(std::pair<float, float> spawnCoords);

    int getHitPoits();
    void setHitPoints(int hitPoints);
    bool noHitPoitsLeft();

    void applyDamage(int damage);
    //TODO end game

    //TODO loadSprite

    private:
    int hitPoints;
};