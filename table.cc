#include "table.h"
#include "player.h"

Table::Table() {}

Table::~Table() {}

std::vector<Card*> Table::getPlayedClubs() {
    return playedClubs;
}

std::vector<Card*> Table::getPlayedDiamonds() {
    return playedDiamonds;
}

std::vector<Card*> Table::getPlayedHearts() {
    return playedHearts;
}

std::vector<Card*> Table::getPlayedSpades() {
    return playedSpades;
}

void Table::generateLegal(std::vector<Card*> playerHand) {
    legalPlays.clear();
    for (unsigned i = 0; i < playerHand.size(); i++) {
        if (playerHand[i]->getRank() == seven) {
            if (playerHand[i]->getSuit() == spade) {
                legalPlays.clear();
                legalPlays.push_back(playerHand[i]);
                return;
            } else {
                legalPlays.push_back(playerHand[i]);
            }
        } else {
            if (playerHand[i]->getSuit() == club) {
                for (unsigned j = 0; j < playedClubs.size(); j++) {
                    if (playedClubs[j]->getRank() - playerHand[i]->getRank() == 1 ||
                    playerHand[i]->getRank() - playedClubs[j]->getRank() == 1) {
                        legalPlays.push_back(playerHand[i]);
                    }
                }
            } else if (playerHand[i]->getSuit() == diamond) {
                for (unsigned j = 0; j < playedDiamonds.size(); j++) {
                    if (playedDiamonds[j]->getRank() - playerHand[i]->getRank() == 1 ||
                    playerHand[i]->getRank() - playedDiamonds[j]->getRank() == 1) {
                        legalPlays.push_back(playerHand[i]);
                    }
                }
            } else if (playerHand[i]->getSuit() == heart) {
                for (unsigned j = 0; j < playedHearts.size(); j++) {
                    if (playedHearts[j]->getRank() - playerHand[i]->getRank() == 1 ||
                    playerHand[i]->getRank() - playedHearts[j]->getRank() == 1) {
                        legalPlays.push_back(playerHand[i]);
                    }
                }
            } else if (playerHand[i]->getSuit() == spade) {
                for (unsigned j = 0; j < playedSpades.size(); j++) {
                    if (playedSpades[j]->getRank() - playerHand[i]->getRank() == 1 ||
                    playerHand[i]->getRank() - playedSpades[j]->getRank() == 1) {
                        legalPlays.push_back(playerHand[i]);
                    }
                }
            }
        }
    }
}

std::vector<Card*> Table::getLegalPlays() {
    return legalPlays;
}

bool Table::isLegal(Card* card) {
    for (unsigned i = 0; i < legalPlays.size(); i++) {
        if (*card == *legalPlays[i]) {
            return true;
        }
    }
    return false;
}

void Table::addCard(Card* card) {
    if (card->getSuit() == club) {
        if (playedClubs.empty() || card->getRank() > playedClubs[playedClubs.size()-1]->getRank()) {
            playedClubs.emplace_back(card);
        } else {
            for (unsigned i = 0; i < playedClubs.size(); i++) {
                if (card->getRank() < playedClubs[i]->getRank()) {
                    playedClubs.emplace(playedClubs.begin()+i, card);
                    break;
                }
            }
        }
    } else if (card->getSuit() == diamond) {
        if (playedDiamonds.empty() || card->getRank() > playedDiamonds[playedDiamonds.size()-1]->getRank()) {
            playedDiamonds.emplace_back(card);
        } else {
            for (unsigned i = 0; i < playedDiamonds.size(); i++) {
                if (card->getRank() < playedDiamonds[i]->getRank()) {
                    playedDiamonds.emplace(playedDiamonds.begin()+i, card);
                    break;
                }
            }
        }
    } else if (card->getSuit() == heart) {
        if (playedHearts.empty() || card->getRank() > playedHearts[playedHearts.size()-1]->getRank()) {
            playedHearts.emplace_back(card);
        } else {
            for (unsigned i = 0; i < playedHearts.size(); i++) {
                if (card->getRank() < playedHearts[i]->getRank()) {
                    playedHearts.emplace(playedHearts.begin()+i, card);
                    break;
                }
            }
        }
    } else if (card->getSuit() == spade) {
        if (playedSpades.empty() || card->getRank() > playedSpades[playedSpades.size()-1]->getRank()) {
            playedSpades.emplace_back(card);
        } else {
            for (unsigned i = 0; i < playedSpades.size(); i++) {
                if (card->getRank() < playedSpades[i]->getRank()) {
                    playedSpades.emplace(playedSpades.begin()+i, card);
                    break;
                }
            }
        }
    }
}
