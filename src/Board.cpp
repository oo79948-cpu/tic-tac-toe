#include "Board.hpp"
#include <iostream>

Board::Board() {
    initBoard();
}

void Board::initBoard() {
    grid.clear();
    grid.emplace_back("1");
    grid.emplace_back("2");
    grid.emplace_back("3");
    grid.emplace_back("4");
    grid.emplace_back("5");
    grid.emplace_back("6");
    grid.emplace_back("7");
    grid.emplace_back("8");
    grid.emplace_back("9");
}

bool Board::makeMove(int position, std::string token) {
    if (canMakeMove(position)) {
        int index = position - 1;
        grid[index] = token;
        return true;
    }
    return false;
}

bool Board::canMakeMove(int position) {
    if (position < 1 || position > 9) {
        return false;
    }
    int index = position - 1;
    return grid.at(index) != "X" && grid.at(index) != "O";
}

bool Board::isBoardFull() {
    for (auto element: grid) {
        if (element != "X" && element != "O") {
            return false;
        }
    }
    return true;
}

bool Board::isGameWon() {
    //horizontal
    if (grid.at(0) == grid.at(1) && grid.at(1) == grid.at(2)) {
        return true;
    }
    if (grid.at(3) == grid.at(4) && grid.at(4) == grid.at(5)) {
        return true;
    }
    if (grid.at(6) == grid.at(7) && grid.at(7) == grid.at(8)) {
        return true;
    }

    //vertical
    if (grid.at(0) == grid.at(3) && grid.at(3) == grid.at(6)) {
        return true;
    }
    if (grid.at(1) == grid.at(4) && grid.at(4) == grid.at(7)) {
        return true;
    }
    if (grid.at(2) == grid.at(5) && grid.at(5) == grid.at(8)) {
        return true;
    }

    //diagonal
    if (grid.at(0) == grid.at(4) && grid.at(4) == grid.at(8)) {
        return true;
    }
    if (grid.at(2) == grid.at(4) && grid.at(4) == grid.at(6)) {
        return true;
    }
    return false;
}

void Board::printBoard() {
    std::cout << std::endl;
    for (int i = 0; i < grid.size(); ++i) {

        if ( i % 3 == 0 && i != 0) { // new line on 3 and 6 index
            std::cout << std::endl << "--+---+--" << std::endl;
        }

        std::cout << grid.at(i);

        if ( (i + 1) % 3 != 0) { // separator not at the end
            std::cout << " | ";
        }
    }
    std::cout << std::endl;
}
