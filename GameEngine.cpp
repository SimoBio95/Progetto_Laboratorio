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
    bullet = new Bullets();
    machineGun = new MachineGun;


    //set Up generale di Finestre,Suono,Giocatore

    FinestraDiGioco->setVisible(false);
    Sfondo = FinestraDiGioco->returnSfondo();
    PlayerSprite = Giocatore->getSprite();
    Giocatore->setUpSprite(PlayerSprite,FinestraDiGioco->getSize().x,FinestraDiGioco->getSize().y);
    menu->setMenuText("../Sprite/finestredigioco/finestra1.png",sf::Vector2f (600,800));
    bullet->setBullet(Giocatore->getPos().x,Giocatore->getPos().y);



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
   for(int i = 0; i < projectiles.size(); i++){
       setBullet();
       /*if(projectiles[i].getSprite().getPosition().x > 1680){
           FinestraDiGioco->DrawSprite(projectiles[i].getSprite());
           bullet->animation(elapsedTime,3,5,projectiles[i].getSprite(),"../Sprite/SpriteWeapons/proiettili.png",45);
       }else if(projectiles[i].getSprite().getPosition().x < 20){
           bullet->animation(elapsedTime,3,5,projectiles[i].getSprite(),"../Sprite/SpriteWeapons/proiettili.png",45);
           FinestraDiGioco->DrawSprite(projectiles[i].getSprite());*/
       FinestraDiGioco->DrawSprite(projectiles[i].getSprite());
       }
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


void GameEngine::Update() { //Collisions + shooting check
    Giocatore->Collision(FinestraDiGioco->getSize().x,FinestraDiGioco->getSize().y,PlayerSprite);
    Giocatore->Movement(PlayerSprite);
    if(Giocatore->isShooting()){
        addBullet();
    }
}


void GameEngine::animation() {
    elapsedTime += deltaTime;
    float timeasSec = elapsedTime.asSeconds();
    int animFrame = static_cast<int>((timeasSec/animationDuration)*framesnum)%framesnum;
    test->setTextureRect(sf::IntRect (animFrame*spritesize.x,0,spritesize.x,spritesize.y));
}


void GameEngine::addBullet() {
    if(Bullets::shootTimer >= 7){
        bullet->setBullet(PlayerSprite.getPosition().x +32,PlayerSprite.getPosition().y +32);
        if(Giocatore->getEventPlayer() == shootingL){
            bullet->setDirection(Left);
            projectiles.push_back(*bullet);
        }else if( Giocatore->getEventPlayer() == shootingR){
            bullet->setDirection(Right);
            projectiles.push_back(*bullet);
        }
        Bullets::shootTimer = 0;
    }else{
        Bullets::shootTimer++;
    }
}

void GameEngine::setBullet() { //Check collisions and scale of the projectile, depending on the player movements
    for(int i = 0; i < projectiles.size(); i++){
        projectiles[i].update(projectiles[i].getDirection(),projectiles[i].getSprite(),machineGun->getAtkSpeed(),elapsedTime);
        if(projectiles[i].getSprite().getPosition().x > FinestraDiGioco->getSize().x + 100){
            projectiles.erase(projectiles.begin() + i);
    }
        if(projectiles[i].getSprite().getPosition().x < 0 - 100){
            projectiles.erase(projectiles.begin() +i) ;
        }
    }
}
