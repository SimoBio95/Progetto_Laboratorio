#include "GameEngine.h"

enum choose{inGame,onMenu,Exit};

static choose chooseWindow;


GameEngine::GameEngine(){

    //Istanzia oggetti dinamicamente
    test = new sf::Sprite;
    Giocatore = new Player();
    menu = new Menu(800,600,"Menu");
    sound->initSound("../Audio/progettoL.wav");
    FinestraDiGioco = new Window();

    //set Up generale di Finestre,Suono,Giocatore
    FinestraDiGioco->setVisible(false);
    Sfondo = FinestraDiGioco->returnSfondo();
    PlayerSprite = Giocatore->getSprite();
    Giocatore->setUpSprite(PlayerSprite,FinestraDiGioco->getSize().x,FinestraDiGioco->getSize().y);
    menu->setMenuText("../Sprite/finestredigioco/finestra1.png",sf::Vector2f (600,800));





    //test
    if(!texture.loadFromFile("../Sprite/Test_sprite/test.png"))
        std::cout << "test non caricato" << std::endl;
    test->setTexture(texture);
    test->setScale(2,2);
    test->setPosition(350,350);
    test->setTextureRect(sf::IntRect(0,0,spritesize.x,spritesize.y));
}

void GameEngine::DrawAll() {
    FinestraDiGioco->DrawRectangle(Sfondo);
    FinestraDiGioco->DrawSprite(PlayerSprite);
    FinestraDiGioco->DrawSprite(*test);
}

void GameEngine::RenderGame() {
    FinestraDiGioco->clear();
    DrawAll();
    FinestraDiGioco->display();
}

void GameEngine::GameRun(){
    sound->play();
    sound->setLoop();
    chooseWindow = onMenu;
    bool run = true;
    while(run){
        deltaTime = clock.restart();
        elapsedTime += deltaTime;
        Giocatore->setTime(elapsedTime);
        switch (chooseWindow){
        case(Exit):{
            run = false;
            break;
        }
        case (onMenu):{
            char decision = menu->getEvent();
            menu->setVisible(true);
            menu->clear();
            menu->draw(*menu->getMenu());
            menu->display();
            if (decision == 'K'){
                menu->setVisible(false);
                FinestraDiGioco->setVisible(true);
                chooseWindow = inGame;
            }
            break;
        }
        case (inGame):{
            char decision = FinestraDiGioco->getEvent();
            if(decision == 'E'){
                chooseWindow = onMenu;
                menu->setVisible(true);
            }

            if(decision == 'S' ){
                menu->close();
                chooseWindow = Exit;
                break;
            }else{
                //animation();
                Update();
                RenderGame();
            }
            break;
        }
        }
}
}


void GameEngine::Update() {
    //Collisions:
    Giocatore->Collision(FinestraDiGioco->getSize().x,FinestraDiGioco->getSize().y,PlayerSprite);
    Giocatore->Movement(PlayerSprite);
}


void GameEngine::animation() {
    elapsedTime += deltaTime;
    //Giocatore->animation(elapsedTime,3,1,PlayerSprite);
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