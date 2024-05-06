//
// Created by Simone Biondi on 06/05/24.
//
#include <iostream>
#include "Player.h"

Player::Player():GameCharacter(10,10,10){
    if(!texture.loadFromFile("../Sprite/Player/player1.png"))
        std::cout << "Player non caricato" << std::endl;
    sprite.setTexture(texture);
}

sf::Sprite Player::getSprite() {
    return sprite;
}
