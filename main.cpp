#include <iostream>
#include "Window.h"
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"


int main() {
Window Finestra;
while(Finestra.isOpen()){
    Finestra.getEvent();
    Finestra.RenderGame();
}
return 0;
}
