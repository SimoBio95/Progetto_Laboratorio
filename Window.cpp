#include "Window.h"

Window::Window(){
    Finestra = nullptr;
    this->VideoMode.width = 1920;
    this->VideoMode.height = 1080;
    this->Finestra = new sf::RenderWindow(this->VideoMode,"Laboratorio",sf::Style::Default);
    Finestra->setFramerateLimit(60);
    if(!SfondoTexture.loadFromFile("../Sprite/Texture_Generali/Sfondo1.png"))
        std::cout<<"Sfondo non caricato"<<std::endl;
    this->SfondoFinestra.setTexture(&(this->SfondoTexture));
    this->SfondoFinestra.setSize(sf::Vector2f (Finestra->getSize().x,Finestra->getSize().y));
};

void Window::DrawSprite(sf::Sprite& sprite) {
    Finestra->draw(sprite);
}

void Window::DrawRectangle(sf::RectangleShape & rectangle){
    Finestra->draw(rectangle);
}

bool Window::isOpen() {
   return Finestra->isOpen();
}

void Window::getEvent() {
    while(Finestra->pollEvent(Event)){
        switch(Event.type){
            case sf::Event::EventType::Closed:
                Finestra->close();
                break;
            case sf::Event::EventType::KeyPressed:
            if(Event.key.code == sf::Keyboard::Escape)
                Finestra->close();
            break;
        }
    }
}

sf::Vector2u Window::getSize() const {
    unsigned int width = VideoMode.width;
    unsigned int height = VideoMode.height;
    return {width,height};
}

void Window::clear() {
    Finestra->clear();
}

void Window::display() {
    Finestra->display();
}

sf::RectangleShape Window::returnSfondo() {
    return SfondoFinestra;
}