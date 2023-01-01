#pragma once

#include <string>
#include <iostream>
#include <ostream>

using std::string;
using std::cout;
using std::ostream;


/*Bright colors*/
enum class CoutTextColors{
    BLACK = 30,
    RED,
    GREEN,
    YELLOW,
    BLUE,
    MAGENTA,
    CYAN,
    WHITE,
    RESET 
};

ostream& operator<<(ostream& out, CoutTextColors textColor);
