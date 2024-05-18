#include "SFML/Graphics.hpp"

#ifndef PROGETTO_LABORATORIO_WEAPON_H
#define PROGETTO_LABORATORIO_WEAPON_H


class Weapon {

public:

    Weapon();
    Weapon(int atk,int atkspeed,int ammo):atk(atk),atkspeed(atkspeed),ammo(ammo){}

    sf::Sprite& getSprite();


protected:

    sf::Texture texture;
    sf::Sprite sprite;
    int atk;
    int atkspeed;
    int ammo;

};


#endif //PROGETTO_LABORATORIO_WEAPON_H
