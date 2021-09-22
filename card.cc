#include "card.h"
#include <vector>

Card::Card(Suit s, Rank r) : suit{s}, rank{r} {}

Suit Card::getSuit() const{
    return suit;
}

Rank Card::getRank() const{
    return rank;
}

bool operator==(const Card &a, const Card &b) {
    return a.getSuit() == b.getSuit() && a.getRank() == b.getRank();
}

std::ostream &operator<<(std::ostream &out, const Card &card) {
    std::vector<char> suits = { 'C', 'D', 'H', 'S' };
	std::vector<char> ranks = { 'A', '2', '3', '4', '5', '6',
		'7', '8', '9', 'T', 'J', 'Q', 'K' };
    out << ranks[card.getRank()] << suits[card.getSuit()];
    return out;
}
