
#pragma once

#include <string>
#include <vector>
#include <list>

#include <SDL2/SDL.h>

#include "../settings.h"
#include "../Renderer.h"
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
    Tower(EnemyManager* enemyManager, double damage, double radius, double attackSpeed, int level, Coords coords);
    ~Tower();

    double getDamage();
    double getRadius();
    Coords getCoords();

    virtual void attack() = 0;

    bool isDestroyed();
    void setDestroyed();

    virtual void render(Renderer* renderer);

    double getExpForNextLvl(int currentLevel);

    void setDamage(double damage);
    void setCoords(Coords coords);

    bool isPointInRect(Coords point);
    void setModeNoCursorInteraction();
    void setModePressedOn();
    void setModeHoveredOver();

protected:
    double damage = 0;
    double radius = 0;

    int level = 0;
    double experience = 0;
    double expForNextLvl = 0;

    double expForDamage = 0;
    double expForKill = 0;

    //in milliseconds
    double attackSpeed = 0;
    
    Coords towerCoords;

    SDL_Color radiusColor = {100, 100, 180, 180};
    SDL_Color radiusAreaFillColor = {150, 150, 200, 80};

    ObjectCursorInteractionsModes towerCursorInteractionMode = NO_INTERACTION;

    //TODO add UI to destroy tower
    bool destroyed = false;

    PeriodicTimer* attackTimer = nullptr;

    EnemyManager* enemyManager = nullptr;
    Enemy* aimedEnemy = nullptr;
    EnemyTypes aimedEnemiesType;

    TexturesEnumeration towerTextureType;

    std::vector<double> listExpForLvls;

    virtual void setAttackTimer();
    
    void setExpForDamage(double exp);
    void setExpForKill(double exp);

    void findFirstEnemyInRadius();
    void findNearestEnemyInRadius();

    void addExperience(double exp);
    void checkAndLevelUp();

    void setRadius(double radius);
    void setLevel(int level);

    void renderRadiusCircle(Renderer* renderer);
};
