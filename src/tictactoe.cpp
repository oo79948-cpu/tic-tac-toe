#include "tictactoe.hpp"

#include <iostream>
#include <string>

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
            std::cout << std::endl << "--+---+---" << std::endl;
        }

        std::cout << grid.at(i);

        if ( (i + 1) % 3 != 0) { // separator not at the end
            std::cout << " | ";
        }
    }
    std::cout << std::endl;
}

Player::Player(std::string token) {
    this->token = token;
    winCount = 0;
}

void Player::makeMove(Board& board, int position) {
    board.makeMove(position, token);
}

std::string Player::info() {
    return "Player " + token;
}

void Player::win() {
    winCount++;
}

Player::~Player() {
    std::cout << info() << " - # of wins: " << winCount << std::endl;
    std::cout << "Goodbye!"  << std::endl;
}

Game::Game() {
    playerX = new Player("X");
    playerO = new Player("O");
    currentPlayer = playerX;
    winner = nullptr;
    std::cout << "Welcome to Tic-Tac-Toe!" << std::endl;
}

Game::~Game() {
    std::cout << "Goodbye Players!" << std::endl;
    delete playerX;
    delete playerO;
}

void Game::changePlayer() {
    if (currentPlayer == playerX) {
        currentPlayer = playerO;
    } else {
        currentPlayer = playerX;
    }
}

bool Game::keepPlaying() {
    bool ask = false;
    if (winner != nullptr) {
        std::cout << std::endl << winner->info() << " wins!" << std::endl;
        currentPlayer = winner;
        winner = nullptr;
        changePlayer(); // loser starts next game
        ask = true;
    }
    else if (board.isBoardFull()) {
        std::cout << std::endl << "Draw!!!" << std::endl;
        ask = true;
    }

    while (ask) {
        std::string response;
        std::cout << "Play again? (yes or no): ";
        std::cin >> response;
        if (response == "yes") {
            board.initBoard();
            return true;
        }
        if (response == "no") {
            return false;
        }
        std::cout << "That is not a valid entry!" << std::endl;
    }
    return true;
}

bool Game::weHaveAWinner() {
    return board.isGameWon();
}

int Game::getPosition() {
    int userInput;
    std::cin >> userInput;
    if (std::cin.fail()) {
        userInput = -1;
    }
    std::cin.clear(); // Clear the error flag
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the buffer
    return userInput;
}

void Game::playGame() {
    do {
        board.printBoard();
        std::cout << std::endl << currentPlayer->info() << ", what is your move? ";
        int position = getPosition();
        if (!board.canMakeMove(position)) {
            std::cout << "That is not a valid move! Try again." << std::endl;
        } else {
            currentPlayer->makeMove(board, position);
            if (weHaveAWinner()) {
                winner = currentPlayer;
                winner->win();
                board.printBoard();
            }
            changePlayer();
        }
    } while (keepPlaying());
}
