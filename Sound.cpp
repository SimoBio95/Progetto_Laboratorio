//
// Created by Simone Biondi on 12/05/24.
//
#include <iostream>
#include "Sound.h"


sf::SoundBuffer* Sound::initSound(const std::string & percorso_file){
    this->buffer = new sf::SoundBuffer;
   if(!buffer->loadFromFile(percorso_file)){
       std::cout << "Audio non caricato!" ;
   }
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

