//
// Created by Simone Biondi on 19/05/24.
//

#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"


enum Direction {Left,Right};

#ifndef PROGETTO_LABORATORIO_BULLETS_H
#define PROGETTO_LABORATORIO_BULLETS_H


class Bullets {
public:
    Bullets();
    static float shootTimer;
    sf::Sprite& getSprite();

    void animation(sf::Time time,int n_Frames,int AnimationDuration,sf::Sprite& sprite,std::string directory,int n);

    void setBullet(float,float);

    void setDirection(Direction dir) {
        direction = dir;
    }

    Direction getDirection() {
        return direction;
    }

   void update(Direction dir,sf::Sprite& bullet,float atkspeed,const sf::Time& elapsedTime) {
        if (dir == Left) {
            bullet.setScale(-1.5, 1);
            bullet.move(-5*atkspeed, 0);
            animation(elapsedTime,4,3,bullet,"../Sprite/SpriteWeapons/proiettili.png",30);
        } else if (dir == Right) {
            bullet.setScale(1.5, 1);
            bullet.move(5* atkspeed, 0);
            animation(elapsedTime,4,3,bullet,"../Sprite/SpriteWeapons/proiettili.png",30);
        }
    }

private:
    Direction direction;


    sf::Sprite sprite1;
    sf::Texture texture1;
    sf::Vector2f spriteSize = sf::Vector2f (32,32);

};


#endif //PROGETTO_LABORATORIO_BULLETS_H
