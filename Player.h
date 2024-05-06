//
// Created by Simone Biondi on 06/05/24.
//
#include "GameCharacter.h"
#ifndef PROGETTO_LABORATORIO_PLAYER_H
#define PROGETTO_LABORATORIO_PLAYER_H


class Player:public GameCharacter {
public:
    Player();
    sf::Sprite getSprite();

private:
};


#endif //PROGETTO_LABORATORIO_PLAYER_H
