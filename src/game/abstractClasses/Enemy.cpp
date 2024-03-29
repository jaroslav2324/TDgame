#include "Enemy.h"

Enemy::Enemy(EnemiesWay* way, Base* base, Portal* portal, Coords coords){

    movementTimer = new PeriodicTimer(1 / FPS * 1000);

    Enemy::way = way;
    Enemy::base = base;
    Enemy::currentCoords = coords;
    Enemy::portal = portal;

    Enemy::coordsCurrentWaypoint = way->getFirstCoords();
    Enemy::coordsNextWaypoint = way->getWaypointCoords(1);

}

Enemy::~Enemy(){

    if (freezeTimer != nullptr){
        delete freezeTimer;
        freezeTimer = nullptr;
    }

    if (movementTimer != nullptr){
        delete movementTimer;
        movementTimer = nullptr;

    }
}

void Enemy::replaceToNextWaypointCoords(){
    coordsCurrentWaypoint = coordsNextWaypoint;
    coordsNextWaypoint = way->getNextWaypointCoords(numNextWaypoint);
    numNextWaypoint++;
}

void Enemy::MoveToNextWaypoint(double timePeriodOfMoving ){

    // convert to seconds
    timePeriodOfMoving /= 1000;

    //find proportion of coords change
    double diffX = coordsNextWaypoint.x - coordsCurrentWaypoint.x;
    double diffY = coordsNextWaypoint.y - coordsCurrentWaypoint.y;

    char signOfDiffX = 1;
    if (diffX < 0)
        signOfDiffX = -1;

    double distanceToNextWaypoint = sqrt(pow(diffX, 2) + pow(diffY, 2));
    double movingDistance = currentSpeed * timePeriodOfMoving;
    double scale = movingDistance / distanceToNextWaypoint;

    // equality movingDistance^2 = changeX^2 + changeY^2
    double changeY = diffY * scale;
    double changeX;
    changeX = sqrt(pow(movingDistance, 2) - pow(changeY, 2));
    changeX *= signOfDiffX;

    /*change coords*/
    currentCoords.x += changeX;
    currentCoords.y += changeY;
}

bool Enemy::ifWaypointPassed(){

    double diffX = coordsNextWaypoint.x - coordsCurrentWaypoint.x;
    double diffY = coordsNextWaypoint.y - coordsCurrentWaypoint.y;

    /*if diffX < 0 x coord of the next waypoint is left from current waypoint
      if diffX > 0 x coord of the next waypoint is right from current waypoint*/
    if (diffX < 0){
        /*if enemy passed by waypoint*/ 
        if (currentCoords.x < coordsNextWaypoint.x)
            currentCoords.x = coordsNextWaypoint.x;
    }
    else{
        /*if enemy passed by waypoint*/ 
        if (currentCoords.x > coordsNextWaypoint.x)
            currentCoords.x = coordsNextWaypoint.x;
    }

    /*if diffY < 0 y coord of the next waypoint is up from current waypoint
      if diffY > 0 y coord of the next waypoint is down from current waypoint*/
    if (diffY < 0){
        /*if enemy passed by waypoint*/ 
        if (currentCoords.y < coordsNextWaypoint.y)
            currentCoords.y = coordsNextWaypoint.y;
    }
    else{
        /*if enemy passed by waypoint*/ 
        if (currentCoords.y > coordsNextWaypoint.y)
            currentCoords.y = coordsNextWaypoint.y;
    }

    if (ifCoordsApprEqual(currentCoords, coordsNextWaypoint)){
        // cout << currentCoords.x << " " << currentCoords.y << " are equal ";
        // cout << coordsNextWaypoint.x << " " << coordsNextWaypoint.y << endl;
        return true;
    }
    return false;
    
}

/*hit Enemy*/
void Enemy::applyDamage(double damage){
    hitPoints -= damage;
    //cout << hitPoints << endl;
}

bool Enemy::isDead(){
    if (hitPoints <= 0)
        return true;
    return false;
}

/*
Slow down Enemy
freezeMultiplyer between 0 and 1
*/
void Enemy::freeze(double freezeMultiplyer, double time){
    isFreezed = true;
    currentSpeed = maxSpeed * (1 - freezeMultiplyer);
    activateFreezeTimer(time);
}

void Enemy::unfreeze(){
    isFreezed = false;
    currentSpeed = maxSpeed;
}

void Enemy::damageBaseAndGetKilled(){
    base->applyDamage(damageToBase);
    hitPoints = 0;
}

void Enemy::move(){

    if (movementTimer->tickIfNeeded()){

        if (ifWaypointPassed())
            replaceToNextWaypointCoords();

        if (freezeTimer != nullptr)
            if (freezeTimer->isCountdownEnd() && isFreezed)
                unfreeze();
            

        MoveToNextWaypoint(movementTimer->getCountPeriod());

        if(isNearBase())
            damageBaseAndGetKilled();
    }
}

bool Enemy::isNearBase(){
    Coords baseCoords = way->getLastCoords();
    if (ifCoordsApprEqual(currentCoords, baseCoords))
        return true;
    return false;
}

void Enemy::activateFreezeTimer(double freezeTime){

    if (freezeTimer == nullptr)
        freezeTimer = new CountdownTimer(freezeTime);
    else
        freezeTimer->replaceToMoreTime(freezeTime);
}

void Enemy::render(Renderer* renderer){

    int x = currentCoords.x - ENEMY_SPRITE_SIZE / 2;
    int y = currentCoords.y - ENEMY_SPRITE_SIZE / 2;
    SDL_Rect enemyRect = {x, y, ENEMY_SPRITE_SIZE, ENEMY_SPRITE_SIZE};
    renderer->renderTexture(enemyTextureType, &enemyRect);
    renderHitPointsBar(renderer);
}

void Enemy::renderHitPointsBar(Renderer* renderer){
    
    SDL_Color whiteColor = {255, 255, 255, 255};
    SDL_Color borderColor = {150, 150, 150, 255};
    SDL_Color color;

    if (hitPoints > 0.66 * maxHitPoints)
        color = {0, 255, 0, 255};
    else if (hitPoints > 0.33 * maxHitPoints)
        color = {255, 255, 0, 255};
    else
        color = {255, 0, 0, 255};

    //render border
    int x = currentCoords.x - ENEMY_SPRITE_SIZE / 2;
    int y = currentCoords.y - ENEMY_SPRITE_SIZE / 2 + 0.8 * ENEMY_SPRITE_SIZE;
    SDL_Rect borderRect = {x, y, ENEMY_SPRITE_SIZE,   (int)(0.2 * ENEMY_SPRITE_SIZE)};
    renderer->renderRect(&borderRect, borderColor);
    
    // fill with white color
    x = currentCoords.x - ENEMY_SPRITE_SIZE / 2 + 1;
    y = currentCoords.y - ENEMY_SPRITE_SIZE / 2 +       0.8 * ENEMY_SPRITE_SIZE + 1;
    SDL_Rect whiteRect = {x, y, ENEMY_SPRITE_SIZE - 2, (int)(0.2 * ENEMY_SPRITE_SIZE - 2)};
    renderer->renderFilledRect(&whiteRect, whiteColor);

    // render hitpoints
    x = currentCoords.x - ENEMY_SPRITE_SIZE / 2 + 1;
    y = currentCoords.y - ENEMY_SPRITE_SIZE / 2 +       0.8 * ENEMY_SPRITE_SIZE + 1;
    int width = (ENEMY_SPRITE_SIZE - 2) * ((double)hitPoints / maxHitPoints);
    SDL_Rect rect = {x, y, width, (int)(0.2 * ENEMY_SPRITE_SIZE - 2)};
    renderer->renderFilledRect(&rect, color);
}

int Enemy::getNumNextWaypoint(){
    return numNextWaypoint;
}

Coords Enemy::getCoords(){
    return currentCoords;
}

EnemyTypes Enemy::getType(){
    return enemyType;
}
