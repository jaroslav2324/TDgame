#include "SoundsEnumeration.h"

// This block is made for iteration over enum

SoundsEnumeration operator++(SoundsEnumeration& soundNum){
    return soundNum = static_cast<SoundsEnumeration>(std::underlying_type<SoundsEnumeration>::type(soundNum) + 1);
}

SoundsEnumeration operator*(SoundsEnumeration soundNum){
    return soundNum;
}

SoundsEnumeration begin(SoundsEnumeration textureNum){
    return SoundsEnumeration::first;
}

SoundsEnumeration end(SoundsEnumeration soundNum){
    SoundsEnumeration lastNum = SoundsEnumeration::last;
    return ++lastNum;
}

// for cout
ostream& operator<<(std::ostream& out, const SoundsEnumeration& soundNum){
    
    switch (soundNum)
    {
    case SoundsEnumeration::BTN_HOVERED_OVER:
        out << "\"button hovered over\"" << endl;
        break;
    case SoundsEnumeration::BTN_PRESSED_ON:
        out << "\"button pressed on\"" << endl;
        break;
    case SoundsEnumeration::BATTLE_MUSIC_1:
        out << "\"battle music 1\"" << endl;
        break;
    default:
        if (DEBUG_CONSOLE_OUTPUT_ON)
            cout << "No case for such sound num: " << static_cast<int>(soundNum) << endl;
        break;
    }

    return out;
}
