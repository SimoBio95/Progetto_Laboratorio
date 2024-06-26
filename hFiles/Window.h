#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#ifndef PROGETTO_LABORATORIO_WINDOW_H
#define PROGETTO_LABORATORIO_WINDOW_H


class Window {
public:
    Window();
    ~Window(){}

    bool isOpen();
    char getEvent();

    void DrawSprite(sf::Sprite&);
    void DrawRectangle(sf::RectangleShape&);

    void clear();
    void display();
    void setVisible(bool);
    void setActive(bool);

    void close();

    sf::RectangleShape returnSfondo();

    sf::Vector2u getSize() const;

private:
    sf::RenderWindow* Finestra;
    sf::VideoMode VideoMode;
    sf::RectangleShape SfondoFinestra;
    sf::Texture SfondoTexture;
    sf::Event Event;
};


#endif
