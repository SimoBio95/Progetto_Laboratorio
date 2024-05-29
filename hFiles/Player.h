//
// Created by Simone Biondi on 06/05/24.
//
#include "GameCharacter.h"


#ifndef PROGETTO_LABORATORIO_PLAYER_H
#define PROGETTO_LABORATORIO_PLAYER_H

enum eventTexture {shootingL,normal_mode,shootingR,moveR,moveL};

class Player:public GameCharacter {
public:
    Player();

    static eventTexture eventoinGame;

    sf::Sprite getSprite();

    static eventTexture getEventPlayer();

    void setHpDamageGet(){
        hp--;
    }

    sf::RectangleShape& gethpBar(){
        return hpBar;
    }

    void Movement(sf::Sprite&,sf::RectangleShape& hpbar);
    void Collision(float,float,sf::Sprite&);

    sf::Vector2f getPos();

    void setUpSprite(sf::Sprite&,float,float);
    void setUpTexture(sf::Sprite&,eventTexture);

    void animation(sf::Time,int,int,sf::Sprite&,std::string,int) override;

    sf::FloatRect getGlobalBounds();

    void setTime(sf::Time);
    sf::Time getTime();

    Player* getPlayer();

    Weapon* getWeapon();

    sf::Vector2i spriteSize = sf::Vector2i (42,32);

    bool isShooting() const;

    sf::Vector2f getScale();

private:
    sf::Vector2f currentVelocity = sf::Vector2f(0.f,0.f);
    float gravity = 4.f;
    float jumpVelocity = -30.f;
    bool isJumping = false;



    sf::Time deltaTime;
    sf::Clock clock;
    sf::Time elapsedTime;

    Weapon* weapon;

    bool gun_shot = false;

    sf::RectangleShape hpBar;

};


#endif //PROGETTO_LABORATORIO_PLAYER_H
