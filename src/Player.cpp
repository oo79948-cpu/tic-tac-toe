#include "Player.hpp"

#include <iostream>
#include <ostream>

Player::Player(Board* board, std::string token) {
    this->board = board;
    this->token = token;
    winCount = 0;
    tieCount = 0;
}

bool Player::makeMove(int position) {
    return board->makeMove(position, token);
}

std::string Player::info() {
    return "Player " + token;
}

int Player::win() {
    winCount++;
    return winCount;
}

int Player::tie() {
    tieCount++;
    return tieCount;
}


Player::~Player() {
    std::cout << info() << " - # of wins: " << winCount << ", # of ties:  " << tieCount << std::endl;
    std::cout << "Goodbye!"  << std::endl;
}