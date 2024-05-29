//
// Created by Simone Biondi on 13/05/24.
//

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

#ifndef PROGETTO_LABORATORIO_MENU_H
#define PROGETTO_LABORATORIO_MENU_H


class Menu {
public:
    Menu(){};
    Menu(unsigned int , unsigned int , std::string);
    bool isOpen();
    char getEvent();
    void setMenuText(const std::string &,sf::Vector2f );
    void draw(const sf::RectangleShape&);
    void clear();
    void display();
    void setVisible(bool);

    void close();

    sf::RectangleShape* getMenu();

private:
    sf::RenderWindow* menu;
    sf::VideoMode videomode;
    sf::RectangleShape* windowShape;
    sf::Texture texture;
    sf::Event event;

};


#endif //PROGETTO_LABORATORIO_MENU_H
