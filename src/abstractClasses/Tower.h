#pragma once

#include <string>
#include <vector>

#include <SDL2/SDL.h>

#include "../settings.h"
#include "../Timers.h"
#include "Enemy.h"
#include "../entityManagers/EnemyManager.h"
#include "Projectile.h"

using std::string;

/*Basic class for all towers*/
class Tower{
public:
    Tower(SDL_Renderer* renderer,EnemyManager* enemyManager);
    //TODO end constructor
    Tower(SDL_Renderer* renderer,EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level);
    ~Tower();

    float getDamage();
    float getRadius();

    void attack(SDL_Renderer* renderer);

    bool isDestroyed();
    void setDestroyed();

    //TODO make private pure virtual
    virtual void loadTexture(SDL_Renderer* renderer);
    void render(SDL_Renderer* renderer);
    void renderAllProjectiles(SDL_Renderer* renderer);

    float getExpForNextLvl(int currentLevel);

protected:
    float damage = 0;
    double freezeMultyplyer = 0;
    double freezeTime = 0;
    float radius = 0;

    int level = 0;
    float experience = 0;
    float expForNextLvl = 0;

    float expForDamage = 0;
    float expForKill = 0;

    //in milliseconds
    float attackSpeed = 0;
    
    std::pair<float, float> towerCoords;

    std::pair<int, int> gridCoords;

    //TODO add UI to destroy tower
    bool destroyed = false;

    PeriodicTimer* attackTimer = nullptr;

    EnemyManager* enemyManager = nullptr;
    Enemy* aimedEnemy = nullptr;

    SDL_Texture* towerTexture = nullptr;

    std::vector<float> listExpForLvls;

    std::vector<Projectile*> projectileList;

    virtual void setAttackTimer() = 0;
    

    void setExpForDamage(float exp);
    void setExpForKill(float exp);

    void findFirstEnemyInRadius();
    void findNearestEnemyInRadius();

    void addExperience(float exp);
    void checkAndLevelUp();

    void setDamage(float damage);
    void setRadius(float radius);
    void setLevel(int level);
    void setCoords(std::pair<float, float> coords);
    void setGridCoords(std::pair<int, int> gridCoords);
};