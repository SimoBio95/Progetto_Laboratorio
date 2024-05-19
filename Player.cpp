//
// Created by Simone Biondi on 06/05/24.
//
#include <iostream>
#include "Player.h"


eventTexture Player::eventoinGame = normal_mode;


Player::Player():GameCharacter(10,10,10){
    if(!texture.loadFromFile("../Sprite/Player/moveright.png"))
        std::cout << "Player non caricato" << std::endl;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (0,0,35,32));
    weapon = new MachineGun;
    weapon->getSound().setVolume(40.f);
}

sf::Sprite Player::getSprite() {
    return sprite;
}

//Movimenti giocatori + set up delle corrette texture

void Player::Movement(sf::Sprite& sprite) {
    elapsedTime += deltaTime;
    sprite.move(0,5);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        eventoinGame = moveL;
        spriteSize = sf::Vector2i (42,32);
        setUpTexture(sprite,eventoinGame);
        sprite.move(-10.f,0);
    }
    if(sf::Keyboard::isKeyPressed((sf::Keyboard::D))){
        eventoinGame = moveR;
        spriteSize = sf::Vector2i (40,32);
        setUpTexture(sprite,eventoinGame);
        sprite.move(10.f,0);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
       if(!isJumping){
           currentVelocity .x = 0;
           currentVelocity.y = jumpVelocity;
           isJumping = true;
       }
       currentVelocity.y += gravity;
       sprite.move(currentVelocity);
       if(sprite.getPosition().y >= (1080 - sprite.getGlobalBounds().height*3 +45)){
           sprite.setPosition(sprite.getPosition().x,1080 - sprite.getGlobalBounds().height*3 +45 );
           currentVelocity.y = 0;
           isJumping = false;
       }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        eventoinGame = normal_mode;
        spriteSize = sf::Vector2i (42,32);
        setUpTexture(sprite,eventoinGame);
        sprite.move(0,10.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
        spriteSize = sf::Vector2i (43,32);
        if(eventoinGame == moveR || eventoinGame == shootingR){
            eventoinGame = shootingR;
            setUpTexture(sprite,eventoinGame);
        }
        if(eventoinGame == moveL || eventoinGame == shootingL){
            eventoinGame = shootingL;
            setUpTexture(sprite,eventoinGame);
        }
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K)){
        if(!gun_shot){
            weapon->getSound().play();
            weapon->getSound().setLoop();
            gun_shot = true;
        }
    }else if(gun_shot){
        weapon->getSound().stop();
        gun_shot = false;
    }
}

void Player::Collision(float x,float y,sf::Sprite& sprite){
    if(sprite.getPosition().x <= 0)
        sprite.setPosition(0,sprite.getPosition().y);
    if(sprite.getPosition().y <=0)
        sprite.setPosition(sprite.getPosition().x,0);
    if(sprite.getPosition().y > y - sprite.getGlobalBounds().height*3 + 45)
        sprite.setPosition(sprite.getPosition().x,y - sprite.getGlobalBounds().height*3 + 45);
    if(sprite.getPosition().x > x - sprite.getGlobalBounds().width*2 -70)
        sprite.setPosition(x - sprite.getGlobalBounds().width*2 -70,sprite.getPosition().y);


}

void Player::setUpSprite(sf::Sprite& sprite,float x,float y){ //set up dello sprite
    sprite.setOrigin(0,0);
    sprite.setScale(3,3);
    sprite.setPosition(0,y - sprite.getGlobalBounds().height);
}

void Player::setUpTexture(sf::Sprite& sprite,eventTexture evento) { // Setta le corrette animazioni di gioco in base agli input da tastiera
    switch (evento) {
        case shootingL:
        animation(elapsedTime,3,5,sprite,"../Sprite/Player/shootLeft.png",45);
        break;
        case normal_mode:
            texture.loadFromFile("../Sprite/Player/moveright.png");
            sprite.setTexture(texture);
            sprite.setTextureRect(sf::IntRect (0,0,35,32));
            break;
        case shootingR:
            animation(elapsedTime,3,5,sprite,"../Sprite/Player/shootright.png",45);
            spriteSize = sf::Vector2i (40,32);
            break;
        case moveR:
            animation(elapsedTime,3,5,sprite,"../Sprite/Player/moveright.png",25);
            break;
        case moveL:
            animation(elapsedTime,3,5,sprite,"../Sprite/Player/moveleft.png",25);
    }
}

void Player::animation (sf::Time time,int n_Frames,int AnimationDuration,sf::Sprite& sprite,std::string directory,int n){
    time = getTime();
    float timeAsSec = time.asSeconds();
    int animFrameTime = static_cast<int>((timeAsSec*n/AnimationDuration)*n_Frames)%n_Frames;
    texture.loadFromFile(directory);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect (animFrameTime*spriteSize.x,0,spriteSize.x,spriteSize.y));
}

void Player::setTime(sf::Time time){
    elapsedTime = time;
}

sf::Time Player::getTime(){
    return elapsedTime;
}