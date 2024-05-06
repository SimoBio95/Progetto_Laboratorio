#include "SFML/Graphics.hpp"

#ifndef PROGETTO_LABORATORIO_GAMECHARACTER_H
#define PROGETTO_LABORATORIO_GAMECHARACTER_H


class GameCharacter {
public:
    GameCharacter(){}
    GameCharacter(int,int,int);
    int getHP();
    int getATK();
    int getDEF();

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    int hp;
    int atk;
    int def;

};


#endif //PROGETTO_LABORATORIO_GAMECHARACTER_H
