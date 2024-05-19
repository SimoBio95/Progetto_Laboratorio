#include "SFML/Graphics.hpp"

#ifndef PROGETTO_LABORATORIO_WEAPON_H
#define PROGETTO_LABORATORIO_WEAPON_H

#include "Sound.h"

class Weapon {

public:

    Weapon(){};

    sf::Sprite& getSprite();
    Sound getSound();


protected:

    Sound* sound;

    sf::Texture texture;
    sf::Sprite sprite;


};


#endif //PROGETTO_LABORATORIO_WEAPON_H
