#pragma once

#include "Tower.h"

class ProjectileTower: public Tower{
public:
    ProjectileTower(EnemyManager* enemyManager, Coords coords);
    ProjectileTower(EnemyManager* enemyManager, double damage, double radius, double attackSpeed, int level, Coords coords);
    ~ProjectileTower();

    void attack();
    void moveAllProjectiles();
    
    void renderAllProjectiles(Renderer* renderer);

protected:

    std::vector<Projectile*> projectileList;

    virtual Projectile* newProjectile() = 0;
};
