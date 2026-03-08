#include <string>
#include <vector>

// Your functions go here
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

class Player {
    std::string token;
    int winCount;
    public:
    Player(std::string token);
    ~Player();
    std::string info();
    void win();
    void makeMove(Board& board, int position);
};

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
public:
    Game();
    ~Game();
    void playGame();
};