#include "deck.h"
#include <algorithm>

const int suitNum = 4;
const int rankNum = 13;
const int deckSize = 52; 

Deck::Deck() {
    for (int i = 0; i < suitNum; i++) {
        for (int j = 0; j < rankNum; j++) {
            cardDeck.push_back(new Card(static_cast<Suit>(i), static_cast<Rank>(j)));
        }
    }
}

Deck::~Deck() {
    for(unsigned int i = 0; i < cardDeck.size(); i++) {
        delete cardDeck[i];
    }
    cardDeck.clear();
}

std::vector<Card*> Deck::getCardDeck() const{
    return cardDeck;
}

// source: codeForStudents/shuffle.cc
void Deck::shuffle(std::default_random_engine rng) {
    std::shuffle(cardDeck.begin(), cardDeck.end(), rng );
}

std::vector<Card*> Deck::deal(int playerID) {
    std::vector<Card*> hand;
    for (int i = 0; i < 13; i++) {
        hand.push_back(cardDeck[playerID * 13 + i]);
    }
    return hand;
}

std::ostream &operator<<(std::ostream &out, const Deck &deck) {
    for (int i = 0; i < deckSize; i++) { 
        out << *(deck.getCardDeck()[i]) << " ";
        if ((i+1)%13 == 0) out << std::endl;
    }
    return out;
}
