#pragma once

#include <iostream>
#include <string>
#include <map>

#include "SDL2/SDL.h"
#include "SDL2/SDL_mixer.h"

#include "../EngineSettings.h"
#include "SoundsEnumeration.h"
#include "SoundChannels.h"
#include "../utility/CoutTextColors.h"

using std::map;
using std::string;
using std::cout;
using std::endl;

class SoundPlayer{

    public:

    SoundPlayer();
    ~SoundPlayer();

    void playSound(SoundsEnumeration soundNum, SoundChannels channel = SoundChannels::ALL_CHANNELS, int loops = 0);

    private:

    map<SoundsEnumeration, Mix_Chunk*> sounds;
};

