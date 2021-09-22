/*
 * Straights card game implementation
 *
 * Table class.  Is responsible for keeping track of current cards on table.  
 *
 */

#ifndef TABLE_H
#define TABLE_H

#include "card.h"
#include <vector>

class Table {
    std::vector<Card*> playedClubs;
    std::vector<Card*> playedDiamonds;
    std::vector<Card*> playedHearts;
    std::vector<Card*> playedSpades;
    std::vector<Card*> legalPlays;
  public:
    Table(); 
    ~Table(); 
    std::vector<Card*> getPlayedClubs();
    std::vector<Card*> getPlayedDiamonds();
    std::vector<Card*> getPlayedHearts();
    std::vector<Card*> getPlayedSpades();
    void generateLegal(std::vector<Card*> playerHand);
    std::vector<Card*> getLegalPlays();
    bool isLegal(Card*);
    void addCard(Card*);
};

#endif 
