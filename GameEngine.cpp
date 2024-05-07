#include "GameEngine.h"

GameEngine::GameEngine(Window* Finestra,Player& Giocatore):Sfondo(Finestra->returnSfondo()),PlayerSprite(Giocatore.getSprite()){
    test = new sf::Sprite;
    FinestraDiGioco = Finestra;
    Giocatore.setUpSprite(PlayerSprite,Finestra->getSize().x,Finestra->getSize().y);

   /* std::cout <<"Widht:"<< PlayerSprite.getGlobalBounds().width <<  "   Height:" << PlayerSprite.getGlobalBounds().height << std::endl;
    std::cout <<"X:"<< PlayerSprite.getPosition().x << "   Y:" << PlayerSprite.getPosition().y  << std::endl;
    std::cout << "Orig.X:" << PlayerSprite.getOrigin().x << " Orig.Y:" << PlayerSprite.getOrigin().y ;*/


    //test
    if(!texture.loadFromFile("../Sprite/Test_sprite/test.png"))
        std::cout << "test non caricato" << std::endl;
    test->setTexture(texture);
    test->setScale(2,2);
    test->setPosition(350,350);
    test->setTextureRect(sf::IntRect(0,0,spritesize.x,spritesize.y));
   // std::cout <<"X:"<< test.getPosition().x << "   Y:" << test.getPosition().y  << std::endl;
}

void GameEngine::DrawAll() {
    FinestraDiGioco->DrawRectangle(Sfondo);
    FinestraDiGioco->DrawSprite(PlayerSprite);
    FinestraDiGioco->DrawSprite(*test);
}

void GameEngine::RenderGame() {
    Update();
    FinestraDiGioco->clear();
    DrawAll();
    FinestraDiGioco->display();
}

void GameEngine::GameRun(){
    while(FinestraDiGioco->isOpen()) {
        deltaTime = clock.restart();
        FinestraDiGioco->getEvent();
        animation();
        RenderGame();

    }
}



void GameEngine::Update() {
    //std::cout <<"\n" << PlayerSprite.getPosition().x << " \n" <<  PlayerSprite.getPosition().y ;
    //Collisions:
    Giocatore.Collision(FinestraDiGioco->getSize().x,FinestraDiGioco->getSize().y,PlayerSprite);
    Giocatore.Movement(PlayerSprite);
}


void GameEngine::animation() {
    elapsedTime += deltaTime;
    Giocatore.animation(elapsedTime,3,1,PlayerSprite);
    float timeasSec = elapsedTime.asSeconds();
    int animFrame = static_cast<int>((timeasSec/animationDuration)*framesnum)%framesnum;
    test->setTextureRect(sf::IntRect (animFrame*spritesize.x,0,spritesize.x,spritesize.y));

}