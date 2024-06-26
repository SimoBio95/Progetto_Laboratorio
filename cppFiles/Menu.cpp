//
// Created by Simone Biondi on 13/05/24.
//

#include "../hFiles/Menu.h"
#include <iostream>

Menu::Menu(unsigned int x, unsigned int y, std::string TitleName){
    videomode.height = x;
    videomode.width = y;
    menu = new sf::RenderWindow(videomode,TitleName,sf::Style::None);
}

void Menu::setMenuText(const std::string& directory,sf::Vector2f sizeOfShape) {
    windowShape = new sf::RectangleShape;
    windowShape->setSize(sizeOfShape);
    if(!texture.loadFromFile(directory)){
        std::cout << "File Menu non caricato!" ;
    }
    windowShape->setTexture(&texture);
}

bool Menu::isOpen() {
    return menu->isOpen();
}

char Menu::getEvent() {
    char decision = 'D'; //default
    while(menu->pollEvent(event)){
        switch (event.type){
            case (sf::Event::EventType::KeyPressed):
                if(event.key.code == sf::Keyboard::Escape){
                    decision = 'K';
                }
                break;
        }
    }
    return decision;
}

void Menu::display() {
    menu->display();
}

void Menu::clear() {
    menu->clear();
}

void Menu::draw(const sf::RectangleShape& windowMenu) {
    menu->draw(windowMenu);
}

sf::RectangleShape* Menu::getMenu() {
    return windowShape;
}

void Menu::setVisible(bool set) {
    menu->setVisible(set);
}

void Menu::close(){
    menu->close();
}