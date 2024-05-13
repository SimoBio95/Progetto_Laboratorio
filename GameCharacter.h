#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


#ifndef PROGETTO_LABORATORIO_GAMECHARACTER_H
#define PROGETTO_LABORATORIO_GAMECHARACTER_H


class GameCharacter  {
public:
    GameCharacter(){}
    GameCharacter(int,int,int);

    virtual void animation(sf::Time,int,int,sf::Sprite&) = 0;

    int getHP();
    int getATK();
    int getDEF();

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::RectangleShape rectShape;
    int hp;
    int atk;
    int def;

};


#endif //PROGETTO_LABORATORIO_GAMECHARACTER_H
