#pragma once

#include <type_traits>
#include <iostream>
#include <fstream>

#include "settings.h"

using std::ostream;
using std::cout;
using std::endl;

// if you are adding texture do not forget to load it in renderer, add it in operator <<
enum class TexturesEnumeration{
    BASIC_ENEMY_TEXTURE,
    ORC_ENEMY_TEXTURE,
    BASIC_TOWER_TEXTURE,
    ICE_TOWER_TEXTURE,
    FIRE_TOWER_TEXTURE,
    BASIC_PROJECTILE_TEXTURE,
    ICEBALL_PROJECTILE_TEXTURE,
    FIREBALL_PROJECTILE_TEXTURE,
    BASIC_GRID_TILE_TEXTURE,
    PORTAL_TEXTURE,
    BASE_TEXTURE,
    TEST_TEXTURE,
    TEST_BUTTON_NO_INTERACTION_TEXTURE,
    TEST_BUTTON_HOVERED_OVER_TEXTURE,
    TEST_BUTTON_PRESSED_ON_TEXTURE,
    WHITE_CIRCLE,
    first=TexturesEnumeration::BASIC_ENEMY_TEXTURE,
    last=TexturesEnumeration::WHITE_CIRCLE
};

// This block is made for iteration over enum
TexturesEnumeration operator++(TexturesEnumeration& textureNum);
TexturesEnumeration operator*(TexturesEnumeration textureNum);
TexturesEnumeration begin(TexturesEnumeration textureNum);
TexturesEnumeration end(TexturesEnumeration textureNum);

// for cout
ostream& operator<<(std::ostream& out, const TexturesEnumeration& textureNum);
