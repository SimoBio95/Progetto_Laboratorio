//
// Created by Simone Biondi on 20/05/24.
//

#include "Enemy.h"
#include <iostream>


Enemy::Enemy():GameCharacter(1,40,2){
    if(!texture.loadFromFile("../Sprite/SpriteEnemy/enemy.png"))
        std::cout << "Nemico non caricato!" ;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (0,0,32,32));

    hpBar.setFillColor(sf::Color::Red);
    hpBar.setOutlineColor(sf::Color::Black);
    hpBar.setOutlineThickness(2);
    hpBar.setSize(sf::Vector2f (static_cast<float>(hp),10));

}

void Enemy::animation (sf::Time time,int n_Frames,int AnimationDuration,sf::Sprite& sprite,std::string directory,int n){
    float timeAsSec = time.asSeconds();
    int animFrameTime = static_cast<int>((timeAsSec*n/AnimationDuration)*n_Frames)%n_Frames;
    texture.loadFromFile(directory);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (animFrameTime*spriteSize.x,0,spriteSize.x,spriteSize.y));
}


int Enemy::spawnTime = 70;

void Enemy::setEnemy(float x,float y){
    sprite.setPosition(x,y);
}

void Enemy::update(Direct direction1,sf::Sprite& enemy,const sf::Time& elapsedTime,sf::RectangleShape& hpbar,float deltatime){
    if(direction1 == LEFT){
        enemy.setScale(-3,5);
        enemy.move(-3*deltatime*multiplier,0);
        hpbar.setPosition(enemy.getPosition().x,enemy.getPosition().y);
        animation(elapsedTime,4,10,enemy,"../Sprite/SpriteEnemy/enemy.png",40);
    }else if(direction1 == RIGHT){
        enemy.setScale(3,5);
        enemy.move(3*deltatime*multiplier,0);
        hpbar.setPosition(enemy.getPosition().x,enemy.getPosition().y);
        animation(elapsedTime,4,10,enemy,"../Sprite/SpriteEnemy/enemy.png",40);
    }else if(direction1 == Dead){
        enemy.move(0,0);
        animation(elapsedTime,4,5,enemy,"../Sprite/SpriteEnemy/enemydied.png",4);
    }
}

int Enemy::deadTime = 140;