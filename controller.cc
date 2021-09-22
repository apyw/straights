//References MVC lecture code example
#include "controller.h"
#include "model.h"

Controller::Controller( Model *m ) : model{m} {}

void Controller::newGame(int seed) {
    model->startGame(seed);
}

void Controller::player1Type(char type) {
    model->setPlayerType(1,type);
}
void Controller::player2Type(char type) {
    model->setPlayerType(2,type);
}
void Controller::player3Type(char type) {
    model->setPlayerType(3,type);
}
void Controller::player4Type(char type) {
    model->setPlayerType(4,type);
}

void Controller::play(std::string card) {
    model->playCard(card);
}

void Controller::discard(std::string card) {
    model->discardCard(card);
}

void Controller::rageQuit() {
    model->rageQuit();
}

void Controller::displayDeck() {
    model->displayDeck();
}
void Controller::displayClubs() {
    model->displayClubs();
}
void Controller::displayDiamonds() {
    model->displayDiamonds();
}
void Controller::displayHearts() {
    model->displayHearts();
}
void Controller::displaySpades() {
    model->displaySpades();
}
void Controller::displayHand() {
    model->displayHand();
}
void Controller::displayLegalPlays() {
    model->displayLegalPlays();
}
