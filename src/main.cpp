#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Timers.h"
#include "abstractClasses/Enemy.h"
#include "enemies/BasicEnemy.h"
#include "abstractClasses/Tower.h"
#include "towers/BasicTower.h"
#include "abstractClasses/Projectile.h"
#include "entityManagers/EnemyManager.h"

//TODO implement main logic
int main(int argc, char **argv)
{
	std::cout << "main" << std::endl;
	
	EnemyManager* testEnemyManager = new EnemyManager();
	
	Enemy* testEnemy = new BasicEnemy("");
	
	Tower* testTower = new BasicTower(testEnemyManager);

	Projectile* testProjectile = new Projectile(testEnemy, std::make_pair(0, 0));

	delete testEnemyManager;
	
	delete testEnemy;
	
	delete testTower;
	delete testProjectile;
	

	return 0;
}
