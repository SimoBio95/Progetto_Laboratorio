//
// Created by Simone Biondi on 19/05/24.
//
#include "../hFiles/Bullet.h"
#include <iostream>


float Bullet::shootTimer = 7;

Bullet::Bullet(){
    if(!texture1.loadFromFile("../Sprite/SpriteWeapons/proiettili.png"))
        std::cout << "Proiettili non caricati" ;
    sprite1.setTexture(texture1);
    sprite1.setTextureRect(sf::IntRect (0,0,32,32));
    sprite1.setScale(0.1,0.1);
}


sf::Sprite& Bullet::getSprite(){
    return sprite1;
}

void Bullet::setBullet(float x, float y) {
    sprite1.setPosition(x,y);
}

void Bullet::animation (sf::Time time, int n_Frames, int AnimationDuration, sf::Sprite& sprite, std::string directory, int n){
    float timeAsSec = time.asSeconds();
    int animFrameTime = static_cast<int>((timeAsSec*n/AnimationDuration)*n_Frames)%n_Frames;
    texture1.loadFromFile(directory);
    sprite.setTexture(texture1);
    sprite.setTextureRect(sf::IntRect (animFrameTime*spriteSize.x,0,spriteSize.x,spriteSize.y));
}

void Bullet::update(Direction dir, sf::Sprite& bullet, float atkspeed, const sf::Time& elapsedTime, float deltaTime) {
    if (dir == Left) {
        bullet.setScale(-1.5, 1);
        bullet.move(-150*atkspeed*deltaTime*multiplier, 0);
        animation(elapsedTime,4,3,bullet,"../Sprite/SpriteWeapons/proiettili.png",30);
    } else if (dir == Right) {
        bullet.setScale(1.5, 1);
        bullet.move(150* atkspeed*deltaTime*multiplier, 0);
        animation(elapsedTime,4,3,bullet,"../Sprite/SpriteWeapons/proiettili.png",30);
    }
}