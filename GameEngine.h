#include "Window.h"
#include "Weapon.h"
#include "Player.h"


#ifndef PROGETTO_LABORATORIO_GAMEENGINE_H
#define PROGETTO_LABORATORIO_GAMEENGINE_H


class GameEngine {
public:
    GameEngine(Window*,Player&);
    void RenderGame();
    void DrawAll();
    void Update();
    void GameRun();

    void animation();



private:
    Window* FinestraDiGioco;
    Player Giocatore;
    sf::RectangleShape Sfondo;
    sf::Sprite PlayerSprite;


    sf::Time deltaTime;
    sf::Clock clock;
    sf::Time elapsedTime;
    int framesnum = 3;
    float animationDuration = 1;


    sf::Sprite* test;
    sf::Texture texture;
    sf::Vector2i spritesize = sf::Vector2i (9,10);


};


#endif //PROGETTO_LABORATORIO_GAMEENGINE_H
