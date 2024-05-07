#include <iostream>
#include "Window.h"
#include "GameEngine.h"
#include "Player.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"


int main() {
    Window Finestra;
    Player Giocatore;
    GameEngine Game(&Finestra,Giocatore);


    Game.GameRun();


return 0;
}

//Continuare con Proiettili, arma e quindi con texture nuove.
