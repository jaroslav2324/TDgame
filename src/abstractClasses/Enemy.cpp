#pragma once

#include <string>

#include <SDL2/SDL.h>

using std::string;

class Enemy{
public:
    Enemy(string& enemySpritePath);
    

protected:
    float hitPoints = 0;
    float maxHitPoints = 0;
    float currentSpeed = 0;
    float maxSpeed = 0;

    float damageToBase = 0;
    
    SDL_Texture* enemySprite = nullptr;
};