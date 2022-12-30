#pragma once

#define DEBUG_CONSOLE_OUTPUT_ON true
#define DEBUG_OUTPUT_FPS false
#define DEBUG_OUTPUT_MOUSE_CLICKS false
#define LOADING_LEVELS_ON true
#define SAVING_LEVELS_ON false

#define FPS 60.0

#define MAX_TOWER_LEVEL 9

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 900

#define GAME_LEVEL_WIDTH 11 //amount of tiles in width on the game screen
#define GAME_LEVEL_HEIGHT 8 //amount of tiles in height on the game screen

#define TILESIZE 100 //amount of pixels in grid tile side
//TODO move to classes as constants?
#define TOWER_SPRITE_SIZE 100
#define ENEMY_SPRITE_SIZE 50
#define PROJECTILE_SPRITE_SIZE 30

/*used in comparison of coordinates*/
#define EPSILON_COORDS 1
