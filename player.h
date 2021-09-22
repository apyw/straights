/*
 * Straights card game implementation
 *
 * Player class.  Is responsible for keeping track of each player.  
 *
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "table.h"
#include <string>
#include <vector>
#include <stdexcept>

class Player {
    int playerScore;
  protected:
    int id; 
    std::vector<Card*> playerHand;
    std::vector<Card*> discards;
  public:
    Player(std::vector<Card*> cards, int id); // Constructor
    Player(const Player &other); // Copy constructor
    virtual ~Player(); // Destructor
    std::vector<Card*> getPlayerHand();
    std::vector<Card*> getDiscards(); 
    int findIndex(Suit suit, Rank rank);
    void deal(std::vector<Card*> cards);
    char virtual getPlayerType() = 0; 
    void virtual play(Table*, std::string card) = 0;
    void virtual discard(Table*, std::string card) = 0;
    int calculateScore();
    int getPlayerScore();
};
 
class HumanPlayer : public Player {
  public:
    HumanPlayer(std::vector<Card*> cards, int id);
    char getPlayerType();
    void play(Table*, std::string card);
    void discard(Table*, std::string card);
};

class ComputerPlayer : public Player {
  public:
    ComputerPlayer(std::vector<Card*> cards, int id);
    ComputerPlayer(Player & oldPlayer);
    char getPlayerType();
    void play(Table*, std::string card);
    void discard(Table*, std::string card);
};

#endif 
