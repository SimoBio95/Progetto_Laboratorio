#include "../hFiles/GameEngine.h"

enum choose{inGame,onMenu,Exit};

static choose chooseWindow;


GameEngine::GameEngine(){


    //General set up: allocating dynamically all needed objects.

    test = new sf::Sprite;
    Giocatore = new Player();
    menu = new Menu(800,600,"Menu");
    buffer.loadFromFile("../Audio/musiclab.wav");
    sound.setBuffer(buffer);
    FinestraDiGioco = new Window();

    machineGun = new MachineGun;
    enemy = new Enemy;
    bullet = new Bullet;



    FinestraDiGioco->setVisible(false);
    Sfondo = FinestraDiGioco->returnSfondo();
    PlayerSprite = Giocatore->getSprite();
    Giocatore->setUpSprite(PlayerSprite,FinestraDiGioco->getSize().x,FinestraDiGioco->getSize().y);
    menu->setMenuText("../Sprite/finestredigioco/finestra1.png",sf::Vector2f (600,800));
    bullet->setBullet(Giocatore->getPos().x,Giocatore->getPos().y);

}

//Draw everything on the screen

void GameEngine::DrawAll() {
    FinestraDiGioco->DrawRectangle(Sfondo);
    FinestraDiGioco->DrawSprite(PlayerSprite);
    FinestraDiGioco->DrawSprite(*test);
    FinestraDiGioco->DrawRectangle(Giocatore->gethpBar());
   for(int i = 0; i < projectiles.size(); i++){
       setBullet();
       FinestraDiGioco->DrawSprite(projectiles[i].getSprite());
       }
   for(int i = 0; i < enemies.size();i++){
       setEnemy();
       FinestraDiGioco->DrawSprite(enemies[i].getSprite());
       FinestraDiGioco->DrawRectangle(enemies[i].gethpBar());
   }
    }


void GameEngine::RenderGame() {
    FinestraDiGioco->clear();
    DrawAll();
    FinestraDiGioco->display();
}

void GameEngine::GameRun(){
    srand(time(NULL));
    sound.play();
    sound.setLoop(true);
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
    Giocatore->Movement(PlayerSprite,Giocatore->gethpBar());
    if(Giocatore->isShooting()){
        addBullet();
    }
    addEnemy();
    collisionCheck();
}

//Addbullet method: it creates new bullets everytime K-key is being pressed on the Keyboard. A timer has been set up for not overcreating bullets.

void GameEngine::addBullet() {
    if(Bullet::shootTimer >= 7){
        bullet->setBullet(PlayerSprite.getPosition().x +32,PlayerSprite.getPosition().y +32);
        if(Giocatore->getEventPlayer() == shootingL){
            bullet->setDirection(Left);
            projectiles.push_back(*bullet);
        }else if( Giocatore->getEventPlayer() == shootingR){
            bullet->setDirection(Right);
            projectiles.push_back(*bullet);
        }
        Bullet::shootTimer = 0;
    }else{
        Bullet::shootTimer++;
    }
}

void GameEngine::setBullet() { //Check collisions and scale of the projectile, depending on the player movements
    for(int i = 0; i < projectiles.size(); i++){
        projectiles[i].update(projectiles[i].getDirection(),projectiles[i].getSprite(),machineGun->getAtkSpeed(),elapsedTime,clock.restart().asSeconds());
        if(projectiles[i].getSprite().getPosition().x > FinestraDiGioco->getSize().x + 100){
            projectiles.erase(projectiles.begin() + i);
    }
        if(projectiles[i].getSprite().getPosition().x < 0 - 100){
            projectiles.erase(projectiles.begin() + i) ;
        }
    }
}

//Add enemy method. It is kinda the same of "AddBullet" method. On top, it sets the what's called "Direction": it helped me out for setting
// the right textures and animate them.

void GameEngine::addEnemy() {
    if(Enemy::spawnTime >= 70){
        enemy->setEnemy(rand()%(10-1800),790);
        if(enemy->getSprite().getPosition().x < FinestraDiGioco->getSize().x/2 - 200){ //Spawn nemico ai limiti della mappa
            enemy->setDirection(RIGHT);
            enemies.push_back(*enemy);
        } else{
            enemy->setDirection(LEFT);
            enemies.push_back(*enemy);
        }

        Enemy::spawnTime = 0;
    }else
        Enemy::spawnTime++;
}

//Once enemies have been added in the enemies' vector, this SetEnemy method updates them and animate them during life-time

void GameEngine::setEnemy() {
    for (int i = 0; i < enemies.size(); i++){
        enemies[i].update(enemies[i].getDirection(),enemies[i].getSprite(),elapsedTime,enemies[i].gethpBar(),clock.restart().asSeconds());
    }
}

void GameEngine::collisionCheck(){
    for(int j = 0; j < enemies.size() ; j++){
        if(PlayerSprite.getGlobalBounds().intersects(enemies[j].getSprite().getGlobalBounds())){
            Giocatore->setHpDamageGet();
            enemies[j].damageGet(1,enemies[j].gethpBar());
        }
        for(int i = 0; i < projectiles.size(); i++){
            if(enemies[j].getSprite().getGlobalBounds().intersects(projectiles[i].getSprite().getGlobalBounds()) && enemies[j].getDirection() != Dead){
                enemies[j].damageGet(machineGun->getAtk(),enemies[j].gethpBar());
                projectiles.erase(projectiles.begin() +i);
            }
        }
        if(enemies[j].getSprite().getPosition().x > FinestraDiGioco->getSize().x)
            enemies.erase(enemies.begin()+j);
        if(Enemy::deadTime >= 180 && enemies[j].getDirection() ==Dead){
            enemies.erase(enemies.begin()+j);
            Enemy::deadTime = 0;
        }else
           Enemy::deadTime++;
        if(enemies[j].getHP() <= 0){
            enemies[j].setDirection(Dead);
        }
    }
}


//Unit testing su collisioni istanziare un player e nemico player spara e controlla che punti ferita diminuiscano. Erore tocca nemico perde hp muore. Factory pattern appena fatto
//Versiionare file wav e textures
//Cambiare bullet e enemy da puntatori a var locali
//Controllare le costanze