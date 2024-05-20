#include "Window.h"
#include "Weapon.h"
#include "Player.h"
#include "Sound.h"
#include "Menu.h"
#include "MachineGun.h"
#include "Bullets.h"
#include <vector>

#ifndef PROGETTO_LABORATORIO_GAMEENGINE_H
#define PROGETTO_LABORATORIO_GAMEENGINE_H


class GameEngine {
public:
    GameEngine();
    void GameRun();




private:

    void setBullet();
    void addBullet();

    void RenderGame();
    void DrawAll();
    void Update();
    void animation();

    Window* FinestraDiGioco;
    Player* Giocatore;
    sf::RectangleShape Sfondo;
    sf::Sprite PlayerSprite;

    MachineGun* machineGun;


    sf::Time deltaTime;
    sf::Clock clock;
    sf::Time elapsedTime;
    int framesnum = 3;
    float animationDuration = 1;

    Bullets* bullet;
    vector<Bullets> projectiles;

    sf::Sprite* test;
    sf::Texture texture;
    sf::Vector2i spritesize = sf::Vector2i (9,10);

    Sound* sound;
    Menu* menu;



};


#endif //PROGETTO_LABORATORIO_GAMEENGINE_H
