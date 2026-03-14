#pragma once

#include "Board.hpp"
#include "Player.hpp"

class Game {
    Player *playerX;
    Player *playerO;
    Player *currentPlayer;
    Player *winner;
    Board board;
    void changePlayer();
    bool keepPlaying();
    bool weHaveAWinner();
    int getPosition();
    bool getPlayAgain();
    bool gameEnded();
public:
    Game();
    ~Game();
    void playGame();
};
