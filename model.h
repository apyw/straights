/*
 * Straights card game implementation
 * References MVC lecture code example
 *
 * Model class.  Is responsible for keeping track of the deck of cards.  
 * It knows nothing about views or controllers.
 *
 */

#ifndef MODEL_H
#define MODEL_H

#include "subject.h"
#include "player.h"
#include "table.h"
#include "deck.h"
#include <string>
#include <vector>
#include <stdexcept>
#include <random>

class Model : public Subject {
    std::default_random_engine rng;
    Table *table;
    std::vector<Player*> players;
    std::vector<char> playerType;
    Deck *deck;
    int currentPlayer;
    bool firstRound;
    int moves;

  public:
    Model();
    ~Model();
    void startGame(int seed); // new game
    void setPlayerType(int id, char type); // sets player as human/ computer
    void startRound(); // new round
    Player* getCurrentPlayer(); 
    void playCard(std::string card); // current player plays card 
    void discardCard(std::string card); // current player discards card 
    void next(); 
    void endRound(); // calculates score at the end of each round and determines if game continues
    void rageQuit(); // current player rage quits
    //void quit();

    void displayDeck();
    void displayClubs();
    void displayDiamonds();
    void displayHearts();
    void displaySpades();
    void displayHand();
    void displayLegalPlays();
};

#endif
