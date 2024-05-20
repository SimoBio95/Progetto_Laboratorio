//
// Created by Simone Biondi on 20/05/24.
//

#include "Enemy.h"
#include <iostream>


Enemy::Enemy():GameCharacter(1,10,2){
    if(!texture.loadFromFile("../Sprite/SpriteEnemy/enemy.png"))
        std::cout << "Nemico non caricato!" ;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (0,0,32,32));
}

void Enemy::animation (sf::Time time,int n_Frames,int AnimationDuration,sf::Sprite& sprite,std::string directory,int n){
    float timeAsSec = time.asSeconds();
    int animFrameTime = static_cast<int>((timeAsSec*n/AnimationDuration)*n_Frames)%n_Frames;
    texture.loadFromFile(directory);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (animFrameTime*spriteSize.x,0,spriteSize.x,spriteSize.y));
}

int Enemy::spawnTime = 30;

void Enemy::setEnemy(float x,float y){
    sprite.setPosition(x,y);
}

int Enemy::deadTime = 50;