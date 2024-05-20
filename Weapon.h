#include "SFML/Graphics.hpp"

#ifndef PROGETTO_LABORATORIO_WEAPON_H
#define PROGETTO_LABORATORIO_WEAPON_H

#include "Sound.h"

class Weapon {

public:

    Weapon(float atk,float atkspeed,int ammo):atk(atk),atkspeed(atkspeed),ammo(ammo){};

    sf::Sprite& getSprite();

    Sound getSound();

    float getAtkSpeed() const;

protected:

    float atk;
    float atkspeed;
    int ammo;

    Sound* sound;
    sf::Texture texture;
    sf::Sprite sprite;


};


#endif //PROGETTO_LABORATORIO_WEAPON_H
