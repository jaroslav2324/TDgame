#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "game/Application.h"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	Application app;
	app.loop();

	return 0;
}
