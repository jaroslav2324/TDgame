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

ostream& operator<<(ostream& out, CoutTextColors textColor){

    if (textColor == CoutTextColors::RESET)
        out << "\033[0m";

    string clrStr = std::to_string(static_cast<int>(textColor));
    string outStr = "\033[1;" + clrStr + "m";
    out << outStr.c_str();
    return out;
}
