#pragma once

#include "SDL2/SDL.h"

#include "../settings.h"
#include "Tower.h"

class LaserTower: public Tower{
public:
    LaserTower(EnemyManager* enemyManager, Coords coords);
    LaserTower(EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords);
    ~LaserTower();

    void attack();

    void render(Renderer* renderer);
    void renderLaser(Renderer* renderer);

    void setLaserColor(SDL_Color color);
    void setLaserWidth(int width);

protected:

    SDL_Color laserColor = {255, 255, 0, 255};
    int laserWidth = 5;

    virtual void setAttackTimer();
};
