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
#include "UI/MainMenu.h"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
		cout << "SDL error" << endl;

	if (IMG_Init(IMG_INIT_JPG) == 0)
		cout << "SDL_image error" << endl;


	SDL_Window* window = SDL_CreateWindow("TD_Game", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	PeriodicTimer* fpsTimer = new PeriodicTimer(1 / FPS * 1000);

	MainMenu* mainMenu = new MainMenu(renderer, fpsTimer);
	mainMenu->loop(renderer);

	// Game* game = new Game(renderer);
	// game->loop(renderer);
	// delete game;
	
	delete mainMenu;
	delete fpsTimer;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	IMG_Quit();

	return 0;
}
