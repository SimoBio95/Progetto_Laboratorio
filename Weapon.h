#include "SFML/Graphics.hpp"

#ifndef PROGETTO_LABORATORIO_WEAPON_H
#define PROGETTO_LABORATORIO_WEAPON_H


class Weapon {
public:
    Weapon(){}
    Weapon(sf::Sprite);
private:
    sf::Sprite sprite;
int atk;
};


#endif //PROGETTO_LABORATORIO_WEAPON_H
