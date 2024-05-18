//
// Created by Simone Biondi on 06/05/24.
//
#include "GameCharacter.h"
#include "Weapon.h"
#include "MachineGun.h"

#ifndef PROGETTO_LABORATORIO_PLAYER_H
#define PROGETTO_LABORATORIO_PLAYER_H

enum eventTexture {shootingL,normal_mode,shootingR,moveR,moveL};

class Player:public GameCharacter {
public:
    Player();

    static eventTexture eventoinGame;
    sf::Sprite getSprite();

    void Movement(sf::Sprite&);
    void Collision(float,float,sf::Sprite&);

    void setUpSprite(sf::Sprite&,float,float);
    void setUpTexture(sf::Sprite&,eventTexture);

    void animation(sf::Time,int,int,sf::Sprite&,std::string,int) override;

    void setTime(sf::Time);
    sf::Time getTime();

    sf::Vector2i spriteSize = sf::Vector2i (40,32);

private:
    sf::Vector2f currentVelocity = sf::Vector2f(0.f,0.f);
    float gravity = 4.f;
    float jumpVelocity = -30.f;
    bool isJumping = false;
    sf::SoundBuffer buffer;
    sf::Sound sound;

    Weapon* weapon;

    sf::Time deltaTime;
    sf::Clock clock;
    sf::Time elapsedTime;




};


#endif //PROGETTO_LABORATORIO_PLAYER_H
