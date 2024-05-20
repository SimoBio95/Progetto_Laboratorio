//
// Created by Simone Biondi on 20/05/24.
//
#include "SFML/Graphics.hpp"
#include "GameCharacter.h"

#ifndef PROGETTO_LABORATORIO_ENEMY_H
#define PROGETTO_LABORATORIO_ENEMY_H

enum Direct {LEFT,RIGHT,Dead};


class Enemy:public GameCharacter {
public:
    Enemy();
    void animation(sf::Time,int,int,sf::Sprite&,std::string,int) override;

    sf::Sprite& getSprite(){
        return sprite;
    }

    void setDirection(std::string directions){
        this->dir = new std::string;
        *this->dir = directions;
    }

    sf::Texture& getTexture(){
        return texture;
    }

    void setTexture(sf::String texture){
        this->texture.loadFromFile(texture);
    }

    static int spawnTime;
    static int deadTime;

    void setEnemy(float,float);

    sf::String getDirection(){
        return *dir;
    }

    void update(std::string dir,sf::Sprite& enemy,const sf::Time& elapsedTime){
        if(dir == "left"){
            enemy.setScale(-3,5);
            enemy.move(-3.f,0);
            animation(elapsedTime,4,10,enemy,"../Sprite/SpriteEnemy/enemy.png",40);
        }else if(dir == "right"){
            enemy.setScale(3,5);
            enemy.move(+3.f,0);
            animation(elapsedTime,4,10,enemy,"../Sprite/SpriteEnemy/enemy.png",40);
        }else if(dir == "dead"){
            enemy.move(0,0);
            animation(elapsedTime,4,5,enemy,"../Sprite/SpriteEnemy/enemydied.png",3);
        }
    };

private:
    std::string* dir;
    Direct* direction;
    sf::Vector2i  spriteSize = sf::Vector2i (32,32);
};



#endif //PROGETTO_LABORATORIO_ENEMY_H
