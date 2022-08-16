#pragma once

#include <string>

#include <SDL2/SDL.h>

#include "./EnemiesWay.cpp"

using std::string;


/*Basic class for all enemies*/
class Enemy{
public:
    Enemy(string& enemySpritePath);
    
    //TODO MoveToNextWaypoint()
    //TODO bool ifWaypointPassed();
    void replaceToNextWaypointCoords(EnemiesWay& way);

    // DamageBase

protected:
    float hitPoints = 0;
    float maxHitPoints = 0;
    float currentSpeed = 0;
    float maxSpeed = 0;

    float damageToBase = 0;

    int numCurrentWaypoint = 0;
    std::pair<int, int> coordsNextWaypoint;
    
    SDL_Texture* enemySprite = nullptr;
};

void Enemy::replaceToNextWaypointCoords(EnemiesWay& way){
    coordsNextWaypoint = way.getNextVaypointCoords(numCurrentWaypoint);
    numCurrentWaypoint++;
}
