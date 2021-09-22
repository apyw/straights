// References MVC lecture code example
#include "observer.h"
#include "view.h"
#include "controller.h"
#include "model.h"
#include "subject.h"
#include <iostream>
#include <string>

View::View(int s, Controller *c, Model *m) : model{m}, controller{c}, seed{s}{

    std::cout << "Is Player1 a human (h) or a computer (c)?" << std::endl;
    char c1;
    std::cin >> c1;
    controller->player1Type(c1); 

    std::cout << "Is Player2 a human (h) or a computer (c)?" << std::endl;
    char c2;
    std::cin >> c2;
    controller->player2Type(c2);

    std::cout << "Is Player3 a human (h) or a computer (c)?" << std::endl;
    char c3;
    std::cin >> c3;
    controller->player3Type(c3);

    std::cout << "Is Player4 a human (h) or a computer (c)?" << std::endl;
    char c4;
    std::cin >> c4;
    controller->player4Type(c4);

    controller->newGame(seed);
    model->subscribe(this);
    update();
}
 
View::~View() {}

void View::update() {
    std::cout << "Cards on the table:" << std::endl;
    std::cout << "Clubs: ";
    controller->displayClubs();
    std::cout << "Diamonds: ";
    controller->displayDiamonds();
    std::cout << "Hearts: ";
    controller->displayHearts();
    std::cout << "Spades: ";
    controller->displaySpades();
    std::cout << "Your hand: ";
    controller->displayHand();
    std::cout << "Legal plays: ";
    controller->displayLegalPlays();
    nextCommand();
}

void View::nextCommand() {
    std::string cmd;
    std::string card;
    bool quit = false;
    while (!quit && std::cin >> cmd ) {
        if (cmd == "deck") {
            controller->displayDeck();
        } else if (cmd == "play") {
            std::cin >> card;
            controller->play(card);
        } else if (cmd == "discard") {
            std::cin >> card;
            controller->discard(card);
        } else if (cmd == "ragequit") {
            controller->rageQuit();
        } else if (cmd == "quit") {
            quit = true;
        }
    }
}
