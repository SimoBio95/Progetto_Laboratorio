//
// Created by Simone Biondi on 17/05/24.
//
#include <iostream>
#include "MachineGun.h"

MachineGun::MachineGun(){
    sound = new Sound;
    sound->initSound("../Audio/mitra.mp3");
    std::cout << "mitra caricato" ;
}
