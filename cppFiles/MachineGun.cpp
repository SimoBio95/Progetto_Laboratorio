//
// Created by Simone Biondi on 17/05/24.
//
#include <iostream>
#include "../hFiles/MachineGun.h"

MachineGun::MachineGun(): Weapon(5,7,100){
    sound = new Sound;
    sound->initSound("../Audio/mitra.mp3");
}
