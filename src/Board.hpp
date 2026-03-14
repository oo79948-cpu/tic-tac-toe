#pragma once
#include <vector>
#include <string>

class Board {
    std::vector<std::string> grid;
public:
    Board();
    void initBoard();
    bool canMakeMove(int position);
    bool makeMove(int position, std::string token);
    void printBoard();
    bool isGameWon();
    bool isBoardFull();
};