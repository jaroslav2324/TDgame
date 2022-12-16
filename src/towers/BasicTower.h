#pragma once

#include "../abstractClasses/Tower.h"

class BasicTower: public Tower{
    public:
    BasicTower(SDL_Renderer* renderer, EnemyManager* enemyManager, Coords coords): Tower(renderer, enemyManager, coords){
        attackSpeed = 750;
        radius = 200;

        loadTexture(renderer);

        setAttackTimer();

    };
    BasicTower(SDL_Renderer* renderer, EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords): 
    Tower(renderer, enemyManager, damage, radius, attackSpeed, level, coords){
        attackSpeed = 750;
        radius = 200;

        loadTexture(renderer);

        setAttackTimer();

    };
    ~BasicTower();

    private:

    void loadTexture(SDL_Renderer* renderer);

    void setAttackTimer();
    void deleteAttackTimer();
    Projectile* newProjectile(SDL_Renderer* renderer);
};
