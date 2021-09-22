#include "player.h"

Player::Player(std::vector<Card*> cards, int id) 
    : playerScore{0}, id{id}, playerHand{cards} {}

Player::Player(const Player &other) 
    : playerScore{other.playerScore}, id{other.id}, 
    playerHand{other.playerHand}, discards{other.discards} {}

Player::~Player() {}

std::vector<Card*> Player::getPlayerHand() {
    return playerHand;
}
std::vector<Card*> Player::getDiscards() {
    return discards; 
}
 
int Player::findIndex(Suit suit, Rank rank) {
    for (int i = 0; i < 13; i++) {
        if (playerHand[i]->getSuit() == suit && playerHand[i]->getRank() == rank) {
            return i;
        } 
    }
    return -1;
}

void Player::deal(std::vector<Card*> cards) {
    playerHand.clear();
    discards.clear();
    playerHand = cards;
}

int Player::calculateScore() {
    int score = 0;
    for (unsigned i = 0; i < discards.size(); i++) {
        score += discards[i]->getRank() + 1;
    }
    playerScore += score;
    return score;
}

int Player::getPlayerScore() {
    return playerScore;
}

HumanPlayer::HumanPlayer(std::vector<Card*> cards, int id) : Player{cards,id} {}

char HumanPlayer::getPlayerType() {
    return 'h';
}

void HumanPlayer::play(Table* table, std::string card) {
    Rank rank = seven; // assumes card has valid syntax, and that the specified card is in the players hand
    Suit suit = spade; // assumes card has valid syntax, and that the specified card is in the players hand
    std::vector<char> suits = { 'C', 'D', 'H', 'S' };
	std::vector<char> ranks = { 'A', '2', '3', '4', '5', '6',
		'7', '8', '9', 'T', 'J', 'Q', 'K' };
    for (unsigned i = 0; i < ranks.size(); i++) {
        if (card[0] == ranks[i]) {
            rank = static_cast<Rank>(i);
            break;
        }
    }
    for (unsigned i = 0; i < suits.size(); i++) {
        if (card[1] == suits[i]) {
            suit = static_cast<Suit>(i);
            break;
        }
    }
    int index = findIndex(suit, rank);
    if (table->isLegal(playerHand[index])) {
        table->addCard(playerHand[index]);
        std::cout << "Player" << id+1 << " plays " << *playerHand[index] << "." << std::endl;
        playerHand.erase(playerHand.begin()+index);
    } else {
        throw std::invalid_argument {"This is not a legal play."};
    }
}

void HumanPlayer::discard(Table* table, std::string card) {
    Rank rank = seven; // assumes card has valid syntax, and that the specified card is in the players hand
    Suit suit = spade; // assumes card has valid syntax, and that the specified card is in the players hand
    std::vector<char> suits = { 'C', 'D', 'H', 'S' };
	std::vector<char> ranks = { 'A', '2', '3', '4', '5', '6',
		'7', '8', '9', 'T', 'J', 'Q', 'K' };
    if (table->getLegalPlays().empty()) {
        for (unsigned i = 0; i < ranks.size(); i++) {
            if (card[0] == ranks[i]) {
                rank = static_cast<Rank>(i);
                break;
            }
        }
        for (unsigned i = 0; i < suits.size(); i++) {
            if (card[1] == suits[i]) {
                suit = static_cast<Suit>(i);
                break;
            }
        }
        int index = findIndex(suit, rank);
        discards.emplace_back(playerHand[index]);
        std::cout << "Player" << id+1 << " discards " << *playerHand[index] << "." << std::endl;
        playerHand.erase(playerHand.begin()+index);
    } else {
        throw std::invalid_argument {"You have a legal play. You may not discard."};
    }
}

ComputerPlayer::ComputerPlayer(std::vector<Card*> cards, int id) : Player{cards,id} {} 

ComputerPlayer::ComputerPlayer(Player & oldPlayer) : Player {oldPlayer} {}

char ComputerPlayer::getPlayerType() {
    return 'c';
}

void ComputerPlayer::play(Table* table, std::string card) {
    if (table->getLegalPlays().empty()) {
        discard(table, card);
    } else {
        int index = 0;
        for (unsigned i = 0; i < playerHand.size(); i++) {
            if (playerHand[i] == table->getLegalPlays()[0]) {
                index = i;
                break; 
            }
        }
        table->addCard(table->getLegalPlays()[0]);
        std::cout << "Player" << id+1 << " plays " << *table->getLegalPlays()[0] << "." << std::endl;
        playerHand.erase(playerHand.begin()+index);
    }
}

void ComputerPlayer::discard(Table*, std::string card) {
    discards.emplace_back(playerHand[0]);
    std::cout << "Player" << id+1 << " discards " << *playerHand[0] << "." << std::endl;
    playerHand.erase(playerHand.begin());
}
