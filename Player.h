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

    void Movement(sf::Sprite&);
    void Collision(float,float,sf::Sprite&);

    void setUpSprite(sf::Sprite&,float,float);
    void setUpTexture(sf::Sprite&);

    void animation(sf::Time,int,int,sf::Sprite&) override;

    sf::Vector2i spriteSize = sf::Vector2i (27,32);

private:
    sf::Vector2f currentVelocity = sf::Vector2f(0.f,0.f);
    float gravity = 0.5f;
    float jumpVelocity = -15.f;
    bool isJumping = false;
};


#endif //PROGETTO_LABORATORIO_PLAYER_H
