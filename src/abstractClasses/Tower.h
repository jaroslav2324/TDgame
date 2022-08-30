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
    Tower(EnemyManager* enemyManager);
    Tower(EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level);

    virtual void setAttackTimer() = 0;

    //TODO change exp in derived classes
    void setExpForDamage(float exp);
    void setExpForKill(float exp);
    
    float getDamage();
    float getRadius();
    //int getLevel();

    void attack();

    bool isDestroyed();
    void setDestroyed();

    //TODO void loadSprite() = 0;
    //TODO render
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
    
    //TODO set coords
    std::pair<float, float> towerCoords;

    //TODO grid coords getters and setters
    int gridCoordX = 0;
    int gridCoordY = 0;

    //TODO add UI to destroy tower
    bool destroyed = false;

    PeriodicTimer* attackTimer = nullptr;

    EnemyManager* enemyManager = nullptr;
    Enemy* aimedEnemy = nullptr;

    SDL_Texture* towerSprite = nullptr;

    //FIXME [] for vector?
    std::vector<float> listExpForLvls[MAXLEVEL + 1];

    std::vector<Projectile*> projectileList;

    void findFirstEnemyInRadius();
    void findNearestEnemyInRadius();

    void addExperience(float exp);
    void checkAndLevelUp();

    void setDamage(float damage);
    void setRadius(float radius);
    void setLevel(int level);
};