#pragma once

#include "../Timers.h"
#include "../abstractClasses/Enemy.h"
#include "../game/Portal.h"


class BasicEnemy: public Enemy{
    public:
    BasicEnemy(EnemiesWay* way, Base* base, Portal* portal, Coords coords): Enemy(way, base, portal, coords){
        enemyTextureType = TexturesEnumeration::BASIC_ENEMY_TEXTURE;

        hitPoints = 2;
        maxHitPoints = 2;
        currentSpeed = 100;
        maxSpeed = 100;

        damageToBase = 1;

        enemyType = EnemyTypes::FLYING_ENEMY;
    };

    ~BasicEnemy();

    private:
    
};