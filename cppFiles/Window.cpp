#include "../hFiles/Window.h"

Window::Window(){
    Finestra = nullptr;
    this->VideoMode.width = 1920;
    this->VideoMode.height = 1080;
    this->Finestra = new sf::RenderWindow(this->VideoMode,"Laboratorio",sf::Style::Default);
    Finestra->setFramerateLimit(60);
    if(!SfondoTexture.loadFromFile("../Sprite/Texture_Generali/sfondoeffettivo.png"))
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

char Window::getEvent() {
    char decision = 'D'; //Default;
    while(Finestra->pollEvent(Event)){
        switch(Event.type){
            case sf::Event::EventType::Closed:
                Finestra->close();
                break;
            case sf::Event::EventType::KeyPressed:
            if(Event.key.code == sf::Keyboard::Escape)
                decision = 'E';
            if(Event.key.code == sf::Keyboard::P){
                decision = 'S';
                Finestra->close();
            }
            break;
        }
    }
    return decision;
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

void Window::close(){
    Finestra->close();
}

void Window::setVisible(bool set) {
    Finestra->setVisible(set);
}

void Window::setActive(bool set) {
    Finestra->setActive(set);
}

