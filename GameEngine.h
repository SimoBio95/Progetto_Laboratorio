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
private:
    Window* FinestraDiGioco;
    Player Giocatore;
    sf::RectangleShape Sfondo;
    sf::Sprite PlayerSprite;
    sf::Event event;

};


#endif //PROGETTO_LABORATORIO_GAMEENGINE_H
