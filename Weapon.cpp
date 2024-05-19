#include "Weapon.h"

sf::Sprite &Weapon::getSprite() {
    return sprite;
}

Sound Weapon::getSound(){
    return *sound;
}