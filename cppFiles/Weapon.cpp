#include "../hFiles/Weapon.h"

sf::Sprite &Weapon::getSprite() {
    return sprite;
}

Sound Weapon::getSound(){
    return *sound;
}

float Weapon::getAtkSpeed() const{
    return atkspeed;
}

