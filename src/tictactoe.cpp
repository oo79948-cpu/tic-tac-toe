#include "tictactoe.hpp"

#include <iostream>
#include <string>
#include <limits>

#include "Board.hpp"

Game::Game() {
    playerX = new Player(&board,"X");
    playerO = new Player(&board,"O");
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
    return !gameEnded() || getPlayAgain();
}

bool Game::gameEnded() {
    if (winner != nullptr) {
        board.printBoard();
        std::cout << std::endl << winner->info() << " wins!" << std::endl;
        winner->win();
        currentPlayer = winner;
        winner = nullptr;
        changePlayer(); // loser starts next game
        return true;
    }
    if (board.isBoardFull()) {
        std::cout << std::endl << "Tie!!!" << std::endl;
        playerO->tie();
        playerX->tie();
        return true;
    }
    return false;
}

bool Game::getPlayAgain() {
    while (true) {
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
        if (!currentPlayer->makeMove(position)) {
            std::cout << "That is not a valid move! Try again." << std::endl;
        } else {
            if (weHaveAWinner()) {
                winner = currentPlayer;
            }
            changePlayer();
        }
    } while (keepPlaying());
}
