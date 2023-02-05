#include "SoundPlayer.h"

SoundPlayer::SoundPlayer(){

    int frequency = 22050;
    Uint32 audioFormat = AUDIO_S32LSB;
    int audioChannels = 2;
    int audioBuffers = 4096;

    if (Mix_OpenAudio(frequency, audioFormat, audioChannels, audioBuffers) != 0)
        cout << CoutTextColors::RED << "Unable to initialize audio" <<CoutTextColors::RESET << endl;

    // fill paths of textures
    map<SoundsEnumeration, const char*> soundsPaths;

    soundsPaths[SoundsEnumeration::BTN_HOVERED_OVER] = "../data/sounds/btn_hover.wav";
    soundsPaths[SoundsEnumeration::BTN_PRESSED_ON] = "../data/sounds/btn_press.wav";
    soundsPaths[SoundsEnumeration::BATTLE_MUSIC_1] = "../data/sounds/susp_mel_20.wav";
    // add new paths here


    // if something was not loaded
    if (DEBUG_CONSOLE_OUTPUT_ON)
        for (const auto soundNum: SoundsEnumeration())
            if (soundsPaths.find(soundNum) == soundsPaths.end())
                cout << "No path was added for sound " << soundNum << endl;
        
  
    // load textures
    for (const auto soundNum: SoundsEnumeration()){
        sounds[soundNum] = Mix_LoadWAV(soundsPaths[soundNum]);

        if (DEBUG_CONSOLE_OUTPUT_ON)
            if (sounds[soundNum] == nullptr)
                cout << "Wrong path for texture " << soundNum << endl;


        if (DEBUG_CONSOLE_OUTPUT_ON)
            cout << soundNum;
    }

    if (DEBUG_CONSOLE_OUTPUT_ON)
        cout << endl << endl;
}

SoundPlayer::~SoundPlayer(){

    for (const auto soundNum: SoundsEnumeration())
        Mix_FreeChunk(sounds[soundNum]);

    Mix_CloseAudio();
}

void SoundPlayer::playSound(SoundsEnumeration soundNum, SoundChannels channel, int loops){
    Mix_PlayChannel(static_cast<int>(channel), sounds[soundNum], loops);
}

void SoundPlayer::setVolume(SoundChannels soundChannel, u_char volume){

    int volume128 = (double)volume / 100 * MIX_MAX_VOLUME;

    Mix_Volume(static_cast<int>(soundChannel), volume128);
}
