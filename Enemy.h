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
        direction = new Direct;
        *direction = direction1;
    }
    int getEnemyDead(){
        return enemyDead;
    }

    void setEnemyDead(int x){
        enemyDead = x;
    }

    sf::Texture& getTexture(){
        return texture;
    }

    void setTexture(sf::String texture){
        this->texture.loadFromFile(texture);
    }

    static int deadTime;

    void setEnemy(float,float);
    sf::RectangleShape& gethpBar(){
        return hpBar;
    }

    Direct getDirection(){
        return *direction;
    }

    void update(Direct direction1,sf::Sprite& enemy,const sf::Time& elapsedTime,sf::RectangleShape& hpbar,float deltatime);

    int getTimer(){
        return timer;
    }
    void setTimer(int x){
        timer = x;
    }

    static int spawnTime;
private:
    Direct* direction;
    sf::Vector2i  spriteSize = sf::Vector2i (32,32);


    int timer = 0;

    float multiplier = 60.f;

    int enemyDead = 150;

    sf::RectangleShape hpBar;

};



#endif //PROGETTO_LABORATORIO_ENEMY_H
