#include "sound.h"
#include <SDL.h>
#include <iostream>

Sound::Sound() {
    int audio_rate = 44100;
    uint16_t audio_format = AUDIO_S16SYS;
    int audio_channels = 2;
    int audio_buffers = 4096;

    if ((Mix_OpenAudio(audio_rate, audio_format, audio_channels, audio_buffers)) != 0) {
        std::cout << "Unable to initialize audio: " << Mix_GetError() << std::endl;
    }
}

Sound::~Sound() {
    Mix_CloseAudio();
}

void Sound::addSound(std::string name, std::string path) {
    sound = Mix_LoadWAV(path.c_str());
    if (sound == NULL) {
        std::cout << "Unable to load WAV file: " << Mix_GetError() << std::endl;
    }
    sounds.insert(std::pair<std::string, Mix_Chunk*>(name, sound));
}

void Sound::playSound(std::string name) {
    if (sounds.find(name) != sounds.end()) {
        Mix_PlayChannel(-1, sounds[name], 0);
    }
}