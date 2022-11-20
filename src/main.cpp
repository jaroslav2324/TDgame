#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Game.h"
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

	if (IMG_Init(IMG_INIT_JPG) == 0)
		cout << "SDL_image error" << endl;


	SDL_Window* window = SDL_CreateWindow("window", 0, 0, 500, 500, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Game* game = new Game(renderer);

	game->renderAll(renderer);

	SDL_Delay(10000);

	delete game;
	

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	IMG_Quit();

	return 0;
}
