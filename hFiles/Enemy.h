//
// Created by Simone Biondi on 20/05/24.
//
#include "SFML/Graphics.hpp"
#include "GameCharacter.h"

#ifndef PROGETTO_LABORATORIO_ENEMY_H
#define PROGETTO_LABORATORIO_ENEMY_H

enum Direct {LEFT,RIGHT,Dead,MoreDead};


class Enemy:public GameCharacter {
public:
    Enemy();
    ~Enemy() = default;
    void animation(sf::Time,int,int,sf::Sprite&,std::string,int) override;

    sf::Sprite& getSprite(){
        return sprite;
    }

    void setDirection(Direct direction1){
        direction = direction1;
    }



    static int deadTime;

    void setEnemy(float,float);
    sf::RectangleShape& gethpBar(){
        return hpBar;
    }

    Direct getDirection(){
        return direction;
    }

    void update(Direct direction1,sf::Sprite& enemy,const sf::Time& elapsedTime,sf::RectangleShape& hpbar,float deltatime);


    static int spawnTime;
private:

    Direct direction;


    sf::Vector2i  spriteSize = sf::Vector2i (32,32);


    float multiplier = 60.f;


    sf::RectangleShape hpBar;

};



#endif //PROGETTO_LABORATORIO_ENEMY_H
