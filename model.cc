//References MVC lecture code example
#include "model.h"
#include <iostream>

const int cardNum = 52;

Model::Model() : playerType(4), firstRound{true}, moves{0} {
    table = new Table();
    deck = new Deck();
}

Model::~Model() {
    delete deck;
    for(unsigned int i = 0; i < players.size(); i++) {
        delete players[i];
    }
    players.clear();
}

void Model::startGame(int seed) {
    rng = std::default_random_engine(seed);
    startRound();
}

void Model::setPlayerType(int id, char type) { 
    playerType[id-1] = type;
}

void Model::startRound() {
    moves = 0;
    deck->shuffle(rng);
    for (int i = 0; i < 4; i++) { 
        if (firstRound == true) {
            if (playerType[i] == 'h') {
                players.emplace_back(new HumanPlayer(deck->deal(i), i));
            } else  {
                players.emplace_back(new ComputerPlayer(deck->deal(i), i));
            }
        } else {
            players[i]->deal(deck->deal(i));
        }  
    }
    firstRound = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            if (players[i]->findIndex(spade,seven) != -1) {
                currentPlayer = i;
                break;
            }
        }
    }
    std::cout<<"A new round begins. It's Player" << currentPlayer+1 << "'s turn to play." << std::endl;
    table->generateLegal(players[currentPlayer]->getPlayerHand());
    if (players[currentPlayer]->getPlayerType() == 'h') {
        notify();
    } else {
        playCard("");
    }
}

Player* Model::getCurrentPlayer() {
    return players[currentPlayer];
}

void Model::playCard(std::string card) {
    try {
        players[currentPlayer]->play(table, card);
    } catch (std::invalid_argument & e) {
        std::cout << e.what() << std::endl;
        return;
    }
    moves++;
    if (moves >= 52) endRound();
    next();
}

void Model::discardCard(std::string card) {
    try {
        players[currentPlayer]->discard(table, card);
    } catch (std::invalid_argument & e) {
        std::cout << e.what() << std::endl;
        return;
    }
    moves++;

    if (moves >= 52) endRound();
    next();
}

void Model::next() {
    currentPlayer++;
    currentPlayer = currentPlayer % 4;
    table->generateLegal(players[currentPlayer]->getPlayerHand());
    if (players[currentPlayer]->getPlayerType() == 'h') {
        notify();
    } else {
        playCard("");
    }
}

void Model::endRound() {
    int minPlayerID = -1; // playerID with lowest score
    int minScore = 0;
    int maxScore = 0;
    for (unsigned i = 0; i < players.size(); i++) {
        std::cout << "Player" << i+1 << "'s discards: ";
        for (unsigned j = 0; j < players[i]->getDiscards().size(); j++) { 
            std::cout << *(players[i]->getDiscards()[j]) << " ";
        }
        std::cout << std::endl;

        int oldScore = players[i]->getPlayerScore();
        int roundScore = players[i]->calculateScore();
        int newScore = players[i]->getPlayerScore();
        if (newScore < minScore || i == 0) {
            minScore = newScore;
            minPlayerID = i;
        }
        if (newScore > maxScore || i == 0) {
            maxScore = newScore;
        }
        std::cout << "Player" << i+1 << "'s score: " << oldScore << " + " << roundScore 
            << " = " << newScore << std::endl;
    }
    
    delete table;
    if (maxScore >= 80) {
        std::cout << "Player" << minPlayerID+1 << " wins!" << std::endl;
        throw 0;
    } else {
        table = new Table;
        startRound();
    }
}

void Model::rageQuit() {
    ComputerPlayer *newPlayer = new ComputerPlayer(*players[currentPlayer]);
    delete players[currentPlayer];
    players[currentPlayer] = newPlayer;
    playerType[currentPlayer] = 'c';
    playCard("");
}

void Model::displayDeck() {
    std::cout<< *deck << std::endl;
}
void Model::displayClubs() {
    std::vector<char> ranks = { 'A', '2', '3', '4', '5', '6',
		'7', '8', '9', 'T', 'J', 'Q', 'K' };
    for (unsigned i = 0; i < table->getPlayedClubs().size(); i++) { 
        std::cout << ranks[table->getPlayedClubs()[i]->getRank()] << " ";
    }
    std::cout << std::endl;
}
void Model::displayDiamonds() {
    std::vector<char> ranks = { 'A', '2', '3', '4', '5', '6',
		'7', '8', '9', 'T', 'J', 'Q', 'K' };
    for (unsigned i = 0; i < table->getPlayedDiamonds().size(); i++) { 
        std::cout << ranks[table->getPlayedDiamonds()[i]->getRank()] << " ";
    }
    std::cout << std::endl;
}
void Model::displayHearts() {
    std::vector<char> ranks = { 'A', '2', '3', '4', '5', '6',
		'7', '8', '9', 'T', 'J', 'Q', 'K' };
    for (unsigned i = 0; i < table->getPlayedHearts().size(); i++) { 
        std::cout << ranks[table->getPlayedHearts()[i]->getRank()] << " ";
    }
    std::cout << std::endl;
}
void Model::displaySpades() {
    std::vector<char> ranks = { 'A', '2', '3', '4', '5', '6',
		'7', '8', '9', 'T', 'J', 'Q', 'K' };
    for (unsigned i = 0; i < table->getPlayedSpades().size(); i++) { 
        std::cout << ranks[table->getPlayedSpades()[i]->getRank()] << " ";
    }
    std::cout << std::endl;
}
void Model::displayHand() {
    for (unsigned i = 0; i < players[currentPlayer]->getPlayerHand().size(); i++) { 
        std::cout << *(players[currentPlayer]->getPlayerHand()[i]) << " ";
    }
    std::cout << std::endl;
}
void Model::displayLegalPlays() {
    for (unsigned i = 0; i < table->getLegalPlays().size(); i++) { 
        std::cout << *(table->getLegalPlays()[i]) << " ";
    }
    std::cout << std::endl;
}
