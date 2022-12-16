#pragma once

#include "../abstractClasses/Tower.h"

class FireTower: public Tower{
    public:
    FireTower(SDL_Renderer* renderer, EnemyManager* enemyManager, Coords coords): Tower(renderer, enemyManager, coords){
        attackSpeed = 50;
        radius = 100;

        loadTexture(renderer);

        setAttackTimer();

    };
    FireTower(SDL_Renderer* renderer, EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords): 
    Tower(renderer, enemyManager, damage, radius, attackSpeed, level, coords){
        attackSpeed =   50;
        radius = 100;

        loadTexture(renderer);

        setAttackTimer();

    };
    ~FireTower();

    private:

    void loadTexture(SDL_Renderer* renderer);

    void setAttackTimer();
    void deleteAttackTimer();
    Projectile* newProjectile(SDL_Renderer* renderer);
};
