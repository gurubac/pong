#ifndef SOUND_H
#define SOUND_H

#include <SDL_mixer.h>
#include <iostream>
#include <map>
#include <string>

class Sound {
public:
    Sound();
    ~Sound();
    void addSound(std::string name, std::string path);
    void playSound(std::string name);
private:
    Mix_Chunk *sound;
    std::map<std::string, Mix_Chunk*> sounds;
};

#endif