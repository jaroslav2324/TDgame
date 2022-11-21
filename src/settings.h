#pragma once

#define FPS 60

#define MAX_TOWER_LEVEL 9

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 900

#define GAME_LEVEL_WIDTH 12 //amount of files in width on the game screen
#define GAME_LEVEL_HEIGHT 9 //amount of files in height on the game screen

#define TILESIZE 100 //amount of pixels in grid tile side
//TODO move to classes as constants?
#define TOWER_SPRITE_SIZE 100
#define ENEMY_SPRITE_SIZE 50
#define PROJECTILE_SPRITE_SIZE 30

/*used in comparison of coordinates*/
#define EPSILON_COORDS 1

//TODO change sprite paths
#define BASIC_ENEMY_SPRITE_PATH "../Assets/enemy.png"

#define BASIC_TOWER_SPRITE_PATH "../Assets/tower.jpg"

#define BASIC_GRID_TILE_SPRITE_PATH "../Assets/tile.jpg"
#define PORTAL_TILE_SPRITE_PATH "../Assets/portal.jpg"
#define BASE_TILE_SPRITE_PATH "../Assets/base.jpg"

// relative path build/TowerDefence file
#define TEST_SPRITE_PATH "../Assets/test.jpeg"
