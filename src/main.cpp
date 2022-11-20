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

using std::cout;
using std::endl;

//TODO implement main logic
int main(int argc, char **argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		cout << "SDL error" << endl;

	if (IMG_Init(IMG_INIT_JPG) != 0)
			cout << "SDL_image error" << endl;

	SDL_Window* window = SDL_CreateWindow("window", 0, 0, 500, 500, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Base* base = new Base(std::make_pair<float, float>(0, 0));
	EnemiesWay* way = new EnemiesWay();
	
	EnemyManager* testEnemyManager = new EnemyManager(base, way);
	
	Enemy* testEnemy = new BasicEnemy(way, base);
	
	Tower* testTower = new BasicTower(testEnemyManager);

	while (true)
	{
		//testTower->render(renderer);
		testEnemy->render(renderer);
		std::cout << "main" << std::endl;
		SDL_RenderPresent(renderer);
	}
	

	Projectile* testProjectile = new Projectile(testEnemy, std::make_pair(0, 0));

	delete testEnemyManager;
	
	delete testEnemy;
	
	delete testTower;
	delete testProjectile;

	delete way;
	delete base;
	

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	return 0;
}
