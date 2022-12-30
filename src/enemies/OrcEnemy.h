#pragma once

#include "../Timers.h"
#include "../abstractClasses/Enemy.h"
#include "../game/Portal.h"


class OrcEnemy: public Enemy{
    public:
    OrcEnemy(EnemiesWay* way, Base* base, Portal* portal, Coords coords): Enemy(way, base, portal, coords){
        enemyTextureType = TexturesEnumeration::ORC_ENEMY_TEXTURE;

        hitPoints = 5;
        maxHitPoints = 5;
        currentSpeed = 50;
        maxSpeed = 50;

        damageToBase = 2;

        enemyType = EnemyTypes::GROUND_ENEMY;
    };
};