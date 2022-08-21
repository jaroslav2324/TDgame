#include "Enemy.cpp"

class Projectile{
    public:
    //speed, damage, ...
    Projectile(Enemy* aimedEnemy);
    //TODO load sprite
    void hitEnemy();

    protected:
    double speed = 0;
    double damage = 0;
    bool isFreezing = false;
    //TODO freeze amount
    //freeze time

    Enemy* aimedEnemy;

};