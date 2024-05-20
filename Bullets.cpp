//
// Created by Simone Biondi on 19/05/24.
//
#include "Bullets.h"
#include <iostream>


float Bullets::shootTimer = 7;

Bullets::Bullets(){
    if(!texture1.loadFromFile("../Sprite/SpriteWeapons/proiettili.png"))
        std::cout << "Proiettili non caricati" ;
    sprite1.setTexture(texture1);
    sprite1.setTextureRect(sf::IntRect (0,0,32,32));
    sprite1.setScale(0.1,0.1);
    std::cout << "Proiettile caricato" ;
}


sf::Sprite& Bullets::getSprite(){
    return sprite1;
}

void Bullets::setBullet(float x, float y) {
    sprite1.setPosition(x,y);
}

void Bullets::animation (sf::Time time,int n_Frames,int AnimationDuration,sf::Sprite& sprite,std::string directory,int n){
    float timeAsSec = time.asSeconds();
    int animFrameTime = static_cast<int>((timeAsSec*n/AnimationDuration)*n_Frames)%n_Frames;
    texture1.loadFromFile(directory);
    sprite.setTexture(texture1);
    sprite.setTextureRect(sf::IntRect (animFrameTime*spriteSize.x,0,spriteSize.x,spriteSize.y));
}