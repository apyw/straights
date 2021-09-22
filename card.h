/*
 * Straights card game implementation
 *
 * Card class.  Is responsible for keeping track of value of card.  
 *
 */

#ifndef CARD_H
#define CARD_H

#include <iostream>

enum Suit { club, diamond, heart, spade };
enum Rank { ace, two, three, four, five, six, seven, eight, 
            nine, ten, jack, queen, king};

class Card {
    Suit suit;
    Rank rank;
  public:
    Card(Suit, Rank);
    Suit getSuit() const;
    Rank getRank() const;
};

bool operator==(const Card &a, const Card &b);
std::ostream &operator<<(std::ostream &out, const Card &card);

#endif 
