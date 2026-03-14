#pragma once

#include <string>
#include "Board.hpp"

class Player {
    std::string token;
    int winCount;
    int tieCount;
    Board* board;
public:
    Player(Board* board, std::string token);
    ~Player();
    std::string info();
    int win();
    int tie();
    bool makeMove(int position);
};
