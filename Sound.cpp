//
// Created by Simone Biondi on 12/05/24.
//
#include <iostream>
#include "Sound.h"


sf::SoundBuffer* Sound::initSound(const std::string & percorso_file){
    directory = percorso_file;
    buffer = new sf::SoundBuffer;
   if(!buffer->loadFromFile(directory)){
       std::cout << "Audio non caricato!: " << directory  ;
   }
   sound = new sf::Sound;
   sound->setBuffer(*buffer);
    std::cout <<"Audio caricato1  " ;
   return buffer;
}

void Sound::setBuffer(sf::SoundBuffer& buffer1) {
    sound = new sf::Sound;
    sound->setBuffer(buffer1);
}

void Sound::play() {
    sound->play();
}

void Sound::setLoop() {
    sound->setLoop(true);
}

void Sound::stop() {
    sound->stop();
}

void Sound::pause(){
    sound->pause();
}

void Sound::setVolume(float x) {
    sound->setVolume(x);
}

