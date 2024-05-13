#include "GameEngine.h"

enum choose{inGame,onMenu};

static choose chooseWindow;


GameEngine::GameEngine(){
    test = new sf::Sprite;
    this->Giocatore = new Player();
    //Giocatore.setUpSprite(PlayerSprite,Finestra->getSize().x,Finestra->getSize().y);
    //sound->setBuffer(*(sound->initSound("../Audio/game.wav")));



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
   // sound->play();
    //sound->setLoop();
    chooseWindow = onMenu;
    bool run = true;
    while(run){
    switch (chooseWindow){
        case (onMenu):
            menu = new Menu(800,600,"Menu");
            menu->setMenuText("../Sprite/finestredigioco/finestra1.png",sf::Vector2f (600,800));
            while(menu->isOpen()){
                menu->clear();
                menu->draw(*menu->getMenu());
                menu->display();
                if(menu->getEvent()){
                    chooseWindow = inGame;
                }
            }
            break;
        case (inGame):{
            FinestraDiGioco = new Window();
            Sfondo = FinestraDiGioco->returnSfondo();
            PlayerSprite = Giocatore->getSprite();
            Giocatore->setUpSprite(PlayerSprite,FinestraDiGioco->getSize().x,FinestraDiGioco->getSize().y);
            while(FinestraDiGioco->isOpen()){
                deltaTime = clock.restart();
                animation();
                RenderGame();
                if(FinestraDiGioco->getEvent()){
                    FinestraDiGioco->close();
                    run = false;
                }
            }
            break;
        }

    }
    }
    delete menu;
    delete FinestraDiGioco;
    delete Giocatore;
}


void GameEngine::Update() {
    //std::cout <<"\n" << PlayerSprite.getPosition().x << " \n" <<  PlayerSprite.getPosition().y ;
    //Collisions:
    Giocatore->Collision(FinestraDiGioco->getSize().x,FinestraDiGioco->getSize().y,PlayerSprite);
    Giocatore->Movement(PlayerSprite);
}


void GameEngine::animation() {
    elapsedTime += deltaTime;
    Giocatore->animation(elapsedTime,3,1,PlayerSprite);
    float timeasSec = elapsedTime.asSeconds();
    int animFrame = static_cast<int>((timeasSec/animationDuration)*framesnum)%framesnum;
    test->setTextureRect(sf::IntRect (animFrame*spritesize.x,0,spritesize.x,spritesize.y));

}

 // Da riutilizzare per Gamerun
/*while(FinestraDiGioco->isOpen()) {
                deltaTime = clock.restart();
                FinestraDiGioco->getEvent();
                animation();
                RenderGame();
            }*/