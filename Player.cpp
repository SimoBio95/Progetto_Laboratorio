//
// Created by Simone Biondi on 06/05/24.
//
#include <iostream>
#include "Player.h"

enum eventTexture {shooting,normal_mode};
static eventTexture eventoinGame;

Player::Player():GameCharacter(10,10,10){
    eventoinGame = normal_mode;
    if(!texture.loadFromFile("../Sprite/Player/giocatore.png"))
        std::cout << "Player non caricato" << std::endl;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (0,0,25,32));
}

sf::Sprite Player::getSprite() {
    return sprite;
}

void Player::Movement(sf::Sprite& sprite) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        setUpTexture(sprite);
        sprite.move(-10.f,0);
        sprite.setTextureRect(sf::IntRect (30,0,25,32));
    }
    if(sf::Keyboard::isKeyPressed((sf::Keyboard::D))){
        setUpTexture(sprite);
        sprite.move(10.f,0);
        sprite.setTextureRect(sf::IntRect(0,0,25,32));
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        setUpTexture(sprite);
        sprite.move(0,-10.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        setUpTexture(sprite);
        sprite.move(0,10.f);
        sprite.setTextureRect(sf::IntRect (95,0,25,32));
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
        eventoinGame = shooting;
        setUpTexture(sprite);
        eventoinGame = normal_mode;
    }
}

void Player::Collision(float x,float y,sf::Sprite& sprite){
    if(sprite.getPosition().x <= 0)
        sprite.setPosition(0,sprite.getPosition().y);
    if(sprite.getPosition().y <=0)
        sprite.setPosition(sprite.getPosition().x,0);
    if(sprite.getPosition().y > y - sprite.getGlobalBounds().height*3 + 45)
        sprite.setPosition(sprite.getPosition().x,y - sprite.getGlobalBounds().height*3 + 45);
    if(sprite.getPosition().x > x - sprite.getGlobalBounds().width*4 + 15)
        sprite.setPosition(x - sprite.getGlobalBounds().width*4 + 15,sprite.getPosition().y);


}

void Player::setUpSprite(sf::Sprite& sprite,float x,float y){
    sprite.setOrigin(0,0);
    sprite.setScale(3,3);
    sprite.setPosition(0,y - sprite.getGlobalBounds().height*3 + 45);
}

void Player::setUpTexture(sf::Sprite& sprite) {
    switch (eventoinGame) {
        case shooting:
        texture.loadFromFile("../Sprite/Player/giocatore_sparo+mod.png");
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(90,0,30,32) );
        break;
        case normal_mode:
            texture.loadFromFile("../Sprite/Player/giocatore.png");
            sprite.setTexture(texture);

            break;
    }
}

void Player::animation (sf::Time time,int n_Frames,int AnimationDuration,sf::Sprite& sprite){
    float timeAsSec = time.asSeconds();
    int animFrameTime = static_cast<int>((timeAsSec/AnimationDuration)*n_Frames)%n_Frames;
    texture.loadFromFile("../Sprite/Player/giocatore_sparo+mod.png");
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (animFrameTime*spriteSize.x,0,spriteSize.x,spriteSize.y));
}