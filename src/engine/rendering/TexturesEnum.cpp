#include "TexturesEnum.h"

// This block is made for iteration over enum

TexturesEnumeration operator++(TexturesEnumeration& textureNum){
    return textureNum = static_cast<TexturesEnumeration>(std::underlying_type<TexturesEnumeration>::type(textureNum) + 1);
}

TexturesEnumeration operator*(TexturesEnumeration textureNum){
    return textureNum;
}

TexturesEnumeration begin(TexturesEnumeration textureNum){
    return TexturesEnumeration::first;
}

TexturesEnumeration end(TexturesEnumeration textureNum){
    TexturesEnumeration lastNum = TexturesEnumeration::last;
    return ++lastNum;
}

// for cout
ostream& operator<<(std::ostream& out, const TexturesEnumeration& textureNum){
    
    switch (textureNum)
    {
    case TexturesEnumeration::BASIC_ENEMY_TEXTURE:
        out << "\"basic enemy texture\"" << endl;
        break;
    case TexturesEnumeration::ORC_ENEMY_TEXTURE:
        out << "\"orc enemy texture\"" << endl;
        break;
    case TexturesEnumeration::BASIC_TOWER_TEXTURE:
        out << "\"basic tower texture\"" << endl;
        break;
    case TexturesEnumeration::ICE_TOWER_TEXTURE:
        out << "\"ice tower texture\"" << endl;
        break;
    case TexturesEnumeration::FIRE_TOWER_TEXTURE:
        out << "\"fire tower texture\"" << endl;
        break;
    case TexturesEnumeration::BASIC_PROJECTILE_TEXTURE:
        out << "\"basic projectile texture\"" << endl;
        break;
    case TexturesEnumeration::ICEBALL_PROJECTILE_TEXTURE:
        out << "\"iceball projectile texture\"" << endl;
        break;
    case TexturesEnumeration::FIREBALL_PROJECTILE_TEXTURE:
        out << "\"fireball projectile texture\"" << endl;
        break;
    case TexturesEnumeration::BASIC_GRID_TILE_TEXTURE:
        out << "\"basic grid tile texture\"" << endl;
        break;
    case TexturesEnumeration::PORTAL_TEXTURE:
        out << "\"portal texture\"" << endl;
        break;
    case TexturesEnumeration::BASE_TEXTURE:
        out << "\"base texture\"" << endl;
        break;
    case TexturesEnumeration::TEST_TEXTURE:
        out << "\"test texture\"" << endl;
        break;
    case TexturesEnumeration::TEST_BUTTON_NO_INTERACTION_TEXTURE:
        out << "\"test button(no interaction) texture\"" << endl;
        break;
    case TexturesEnumeration::TEST_BUTTON_HOVERED_OVER_TEXTURE:
        out << "\"test button(hovered over) texture\"" << endl;
        break;
    case TexturesEnumeration::TEST_BUTTON_PRESSED_ON_TEXTURE:
        out << "\"test button(pressed on) texture\"" << endl;
        break;
    case TexturesEnumeration::WHITE_CIRCLE:
        out << "\"white circle texture\"" << endl;
        break;
    default:
        if (DEBUG_CONSOLE_OUTPUT_ON)
            cout << "No case for such texture num: " << static_cast<int>(textureNum) << endl;
        break;
    }

    return out;
}
