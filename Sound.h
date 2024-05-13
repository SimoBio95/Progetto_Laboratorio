//
// Created by Simone Biondi on 12/05/24.
//
#include "SFML/Audio.hpp"

#ifndef PROGETTO_LABORATORIO_SOUND_H
#define PROGETTO_LABORATORIO_SOUND_H


class Sound {
public:
    sf::SoundBuffer* initSound(const std::string & percorso_file);
    void setBuffer(sf::SoundBuffer&);
    void play();
    void setLoop();
private:
    std::string directory;
    sf::SoundBuffer* buffer;
    sf::Sound* sound;
};


#endif //PROGETTO_LABORATORIO_SOUND_H
