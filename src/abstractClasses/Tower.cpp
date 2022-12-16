#include "Tower.h"

Tower::Tower(SDL_Renderer* renderer, EnemyManager* enemyManager, Coords coords){
    //TODO delete SDL_Renderer from constructor or move to fields of the class?

    Tower::enemyManager = enemyManager;
    Tower::towerCoords = coords;

    float exp = 0;
    for (int i = 0; i <= MAX_TOWER_LEVEL; i++){
        listExpForLvls.push_back(exp);
        exp += 100;
    }
}

Tower::Tower(SDL_Renderer* renderer,EnemyManager* enemyManager, float damage, float radius, float attackSpeed, int level, Coords coords){
    //TODO delete SDL_Renderer from constructor or move to fields of the class?

    Tower::enemyManager = enemyManager;
    Tower::damage = damage;
    Tower::radius = radius;
    Tower::attackSpeed = attackSpeed;
    Tower::level = level;
    Tower::towerCoords = coords;

    float exp = 0;
    for (int i = 0; i <= MAX_TOWER_LEVEL; i++){
        listExpForLvls.push_back(exp);
        exp += 100;
    }
}

Tower::~Tower(){
    if (towerTexture != nullptr){
        SDL_DestroyTexture(towerTexture);
        towerTexture = nullptr;
        }
}

float Tower::getDamage(){
    return damage;
}

float Tower::getRadius(){
    return radius;
}

void Tower::setDamage(float damage){
    Tower::damage = damage;
}

void Tower::setRadius(float radius){
    Tower::radius = radius;
}

void Tower::setLevel(int level){
    Tower::level = level;
}

void Tower::setExpForDamage(float exp){
    expForDamage = exp;
}

void Tower::setExpForKill(float exp){
    expForKill = exp;
}

void Tower::setCoords(Coords coords){
    Tower::towerCoords = coords;
}

void Tower::setGridCoords(std::pair<int, int> gridCoords){
    Tower::gridCoords = gridCoords;
}

void Tower::addExperience(float exp){
    experience += exp;
}

float Tower::getExpForNextLvl(int level){
    return listExpForLvls[level];
}

void Tower::checkAndLevelUp(){
    if (experience > expForNextLvl){
        experience -= expForNextLvl;
        level++;
        expForNextLvl = getExpForNextLvl(level);
    }
}


void Tower::findFirstEnemyInRadius(){
    aimedEnemy = enemyManager->findFirstEnemyForTower(towerCoords, radius);
}

void Tower::findNearestEnemyInRadius(){
    aimedEnemy = enemyManager->findNearestEnemyForTower(towerCoords, radius);
}

void Tower::attack(SDL_Renderer* renderer){

/*move all projectiles and delete if they hit enemy*/
    moveAllProjectiles();

    if(attackTimer->tickIfNeeded()){

        findFirstEnemyInRadius();

        // if enemy found
        if (aimedEnemy != nullptr){

            /*spawn projectile and add it to the list*/
            //TODO change BasicProjectile
            Projectile* projectile = newProjectile(renderer);
            projectileList.push_back(projectile);

            /*add experience for tower*/
            if (aimedEnemy->isDead()){
                aimedEnemy = nullptr;
                int size = projectileList.size();
                for (int i = size - 1; i >= 0; i--){
                    delete projectileList[i];
                    projectileList.pop_back();
                }
                    

                addExperience(expForKill);
            }
            else
                addExperience(expForDamage);

            checkAndLevelUp(); 
        }

    }
    //cout << projectileList.size() << endl;
}

void Tower::moveAllProjectiles(){

    int offset = 0;
    for (auto projectile: projectileList){
        projectile->attack();
        if (projectile->hasDamagedEnemy()){
            delete projectile;
            projectileList.erase(projectileList.begin() + offset);
        }
        offset++;
    }   
   
    //cout << projectileList.size() << endl;
}

void Tower::setDestroyed(){
    destroyed = true;
}

bool Tower::isDestroyed(){
    if (destroyed)
        return true;
    return false;
}

void Tower::render(SDL_Renderer* renderer){

    if (towerCursorInteractionMode == HOVERED_OVER)
        renderRadiusCircle(renderer);

    int x = towerCoords.x - TOWER_SPRITE_SIZE / 2;
    int y = towerCoords.y - TOWER_SPRITE_SIZE / 2;
    SDL_Rect towerRect = {x, y, TOWER_SPRITE_SIZE, TOWER_SPRITE_SIZE};
    SDL_RenderCopy(renderer, towerTexture, 0, &towerRect);
}

void Tower::renderAllProjectiles(SDL_Renderer* renderer){
    for (auto projectilePtr: projectileList)
        projectilePtr->render(renderer);
}

Coords Tower::getCoords(){
    return towerCoords;
}

void Tower::renderRadiusCircle(SDL_Renderer * renderer)
{
    SDL_SetRenderDrawColor(renderer, 100, 100, 180, 180);

    int centerX = towerCoords.x;
    int centerY = towerCoords.y;
    int diameter = (radius * 2);

    int x = (radius - 1);
    int y = 0;
    int tx = 1;
    int ty = 1;
    int error = (tx - diameter);

    // TODO add line width
    while (x >= y)
    {
        //  Each of the following renders an octant of the circle
        SDL_RenderDrawPoint(renderer, centerX + x, centerY - y);
        SDL_RenderDrawPoint(renderer, centerX + x, centerY + y);
        SDL_RenderDrawPoint(renderer, centerX - x, centerY - y);
        SDL_RenderDrawPoint(renderer, centerX - x, centerY + y);
        SDL_RenderDrawPoint(renderer, centerX + y, centerY - x);
        SDL_RenderDrawPoint(renderer, centerX + y, centerY + x);
        SDL_RenderDrawPoint(renderer, centerX - y, centerY - x);
        SDL_RenderDrawPoint(renderer, centerX - y, centerY + x);

        if (error <= 0)
        {
            ++y;
            error += ty;
            ty += 2;
        }

        if (error > 0)
        {
            --x;
            tx += 2;
            error += (tx - diameter);
        }
    }
}

void Tower::setModeNoCursorInteraction(){
    towerCursorInteractionMode = NO_INTERACTION;
}

void Tower::setModePressedOn(){
    towerCursorInteractionMode = PRESSED_ON;
    //pressingCooldownTimer->replaceTime(pressingCooldownTime);
}

void Tower::setModeHoveredOver(){
    towerCursorInteractionMode = HOVERED_OVER;
}

bool Tower::isPointInRect(Coords point){
    
    int x1 = towerCoords.x - TOWER_SPRITE_SIZE / 2;
    int y1 = towerCoords.y - TOWER_SPRITE_SIZE / 2;

    int x2 = towerCoords.x + TOWER_SPRITE_SIZE / 2;
    int y2 = towerCoords.y + TOWER_SPRITE_SIZE / 2;

    if (point.x < x1 || point.y < y1 || point.x >= x2 || point.y >= y2)
        return false;
    return true;
}
    