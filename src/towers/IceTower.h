#pragma once

#include "../abstractClasses/Tower.h"

class IceTower: public Tower{
    public:
    IceTower(SDL_Renderer* renderer, EnemyManager* enemyManager, Coords coords): Tower(renderer, enemyManager, coords){
        attackSpeed = 1500;
        radius = 350;

        loadTexture(renderer);

        setAttackTimer();

    };
    IceTower(SDL_Renderer* renderer, EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords): 
    Tower(renderer, enemyManager, damage, radius, attackSpeed, level, coords){
        attackSpeed = 1500;
        radius = 350;

        loadTexture(renderer);
        
        setAttackTimer();

    };
    ~IceTower();

    private:

    void loadTexture(SDL_Renderer* renderer);

    void setAttackTimer();
    void deleteAttackTimer();
    Projectile* newProjectile(SDL_Renderer* renderer);
};
