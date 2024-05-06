#include "GameEngine.h"

GameEngine::GameEngine(Window* Finestra,Player& Giocatore):Sfondo(Finestra->returnSfondo()),PlayerSprite(Giocatore.getSprite()){
    FinestraDiGioco = Finestra;
    this->Giocatore = Giocatore;
    PlayerSprite.setPosition(0,0);
}

void GameEngine::DrawAll() {
    FinestraDiGioco->DrawRectangle(Sfondo);
    FinestraDiGioco->DrawSprite(PlayerSprite);
}

void GameEngine::RenderGame() {
    FinestraDiGioco->clear();
    DrawAll();
    FinestraDiGioco->display();
}

void GameEngine::GameRun(){
    while(FinestraDiGioco->isOpen()) {
        FinestraDiGioco->getEvent();
        RenderGame();
    }
}