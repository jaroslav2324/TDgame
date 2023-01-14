#pragma once

#include <type_traits>
#include <iostream>
#include <fstream>

#include "settings.h"

using std::ostream;
using std::cout;
using std::endl;

enum class SoundsEnumeration{
    BTN_HOVERED_OVER,
    BTN_PRESSED_ON,
    BATTLE_MUSIC_1,
    //check if added sounds
    first = SoundsEnumeration::BTN_HOVERED_OVER,
    //check if added sounds
    last = SoundsEnumeration::BATTLE_MUSIC_1
};

// This block is made for iteration over enum
SoundsEnumeration operator++(SoundsEnumeration& soundNum);
SoundsEnumeration operator*(SoundsEnumeration soundNum);
SoundsEnumeration begin(SoundsEnumeration soundNum);
SoundsEnumeration end(SoundsEnumeration soundNum);

// for cout
ostream& operator<<(std::ostream& out, const SoundsEnumeration& soundNum);
