#pragma once

#include "Tower.h"

class ProjectileTower: public Tower{
public:
    ProjectileTower(EnemyManager* enemyManager, Coords coords);
    ProjectileTower(EnemyManager* enemyManager, double damage, double radius, double attackSpeed, int level, Coords coords);
    ~ProjectileTower();

    void attack();
    void moveAllProjectiles();

    void render(Renderer* renderer);
    void renderAllProjectiles(Renderer* renderer);

protected:

    std::vector<Projectile*> projectileList;

    //TODO not abstract?
    virtual void setAttackTimer() = 0;

    virtual Projectile* newProjectile() = 0;
};
