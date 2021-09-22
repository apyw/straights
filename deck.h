/*
 * Straights card game implementation
 *
 * Deck class.  Is responsible for keeping track of order of deck.  
 *
 */

#ifndef DECK_H
#define DECK_H

#include "card.h"
#include <vector>
#include <random>

class Deck {
    std::vector<Card*> cardDeck;
  public:
    Deck(); 
    ~Deck();
    std::vector<Card*> getCardDeck() const;
    void shuffle(std::default_random_engine rng);
    std::vector<Card*> deal(int playerID);
};

std::ostream &operator<<(std::ostream &out, const Deck &deck);

#endif
