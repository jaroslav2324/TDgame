#pragma once

#include <string>
#include <vector>
#include <list>

#include <SDL2/SDL.h>

#include "../settings.h"
#include "../TexturesHolder.h"
#include "../Timers.h"
#include "Enemy.h"
#include "../entityManagers/EnemyManager.h"
#include "Projectile.h"
#include "../projectiles/BasicProjectile.h"
#include "../ObjectCursorInteractionsModes.h"

using std::string;

/*Basic class for all towers*/
class Tower{
public:
    Tower(EnemyManager* enemyManager, Coords coords);
    //TODO end constructor
    Tower(EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords);
    ~Tower();

    float getDamage();
    float getRadius();
    Coords getCoords();

    void attack(SDL_Renderer* renderer);
    void moveAllProjectiles();

    bool isDestroyed();
    void setDestroyed();

    void render(SDL_Renderer* renderer, TexturesHolder* texturesHolder);
    void renderAllProjectiles(SDL_Renderer* renderer, TexturesHolder* texturesHolder);

    float getExpForNextLvl(int currentLevel);

    void setDamage(float damage);
    void setCoords(Coords coords);

    bool isPointInRect(Coords point);

    void setModeNoCursorInteraction();
    void setModePressedOn();
    void setModeHoveredOver();

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
    
    Coords towerCoords;

    // TODO delete?
    std::pair<int, int> gridCoords;

    ObjectCursorInteractionsModes towerCursorInteractionMode = NO_INTERACTION;

    //TODO add UI to destroy tower
    bool destroyed = false;

    PeriodicTimer* attackTimer = nullptr;

    EnemyManager* enemyManager = nullptr;
    Enemy* aimedEnemy = nullptr;

    TexturesEnumeration towerTextureType;

    std::vector<float> listExpForLvls;

    std::vector<Projectile*> projectileList;

    virtual void setAttackTimer() = 0;

    virtual Projectile* newProjectile(SDL_Renderer* renderer) = 0;
    
    void setExpForDamage(float exp);
    void setExpForKill(float exp);

    void findFirstEnemyInRadius();
    void findNearestEnemyInRadius();

    void addExperience(float exp);
    void checkAndLevelUp();

    void setRadius(float radius);
    void setLevel(int level);
    void setGridCoords(std::pair<int, int> gridCoords);

    void renderRadiusCircle(SDL_Renderer* renderer);
};