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

void Window::RenderGame() {
   Finestra->clear();
   Finestra->draw(SfondoFinestra);
   Finestra->display();
}

void Window::getEvent() {
    while(Finestra->pollEvent(Event)){
        if(Event.type == sf::Event::Closed)
            Finestra->close();
        if(Event.type == sf::Event::KeyPressed && Event.key.code == sf::Keyboard::Escape)
            Finestra->close();
    }
}

sf::Vector2f Window::getSize() {
    return sf::Vector2f(VideoMode.width,VideoMode.height);
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