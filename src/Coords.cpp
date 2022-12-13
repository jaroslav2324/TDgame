#include "Coords.h"

std::ostream& operator<<(std::ostream& os, const Coords& coords){
    os << "Coords: " << coords.x << " " << coords.y << std::endl;
    return os;
}

// ostream& operator<<(ostream& os, Coords coords){
//     os << "Coords: " << coords.x << " " << coords.y << endl;
//     return os;
// }
