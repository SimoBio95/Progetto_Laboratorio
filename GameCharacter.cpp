
#include "GameCharacter.h"

GameCharacter::GameCharacter(int atk, int hp, int def):atk(atk),hp(hp),def(def) {

}

int GameCharacter::getHP() {
    return hp;
}

int GameCharacter::getATK() {
    return atk;
}

int GameCharacter::getDEF() {
    return def;
}

void GameCharacter::damageGet(int damage){
    hp = hp - (damage);
}