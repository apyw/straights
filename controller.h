/*
 * Straights card game implementation
 * References MVC lecture code example
 *
 * Controller class.  Is responsible for translating UI events (from the View)
 * into method calls to the Model.
 *
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

class Model;
 
class Controller {
    Model *model;
  public:
    Controller( Model* );
    void newGame(int seed);
    void player1Type(char type);
    void player2Type(char type);
    void player3Type(char type);
    void player4Type(char type);
    void play(std::string card);
    void discard(std::string card);
    void rageQuit();
    
    void displayDeck();
    void displayClubs();
    void displayDiamonds();
    void displayHearts();
    void displaySpades();
    void displayHand();
    void displayLegalPlays();

}; // Controller

#endif
