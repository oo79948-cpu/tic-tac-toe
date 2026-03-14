#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/tictactoe.hpp"

TEST_CASE( "can make move on an empty board" ) {
    Board board;
    REQUIRE( board.canMakeMove(1) == true );
    REQUIRE( board.canMakeMove(2) == true );
    REQUIRE( board.canMakeMove(3) == true );
    REQUIRE( board.canMakeMove(4) == true );
    REQUIRE( board.canMakeMove(5) == true );
    REQUIRE( board.canMakeMove(6) == true );
    REQUIRE( board.canMakeMove(7) == true );
    REQUIRE( board.canMakeMove(8) == true );
    REQUIRE( board.canMakeMove(9) == true );
}


TEST_CASE( "can't make move on the same field or out of bounds" ) {
    Board board;
    REQUIRE( board.canMakeMove(0) == false );
    REQUIRE( board.canMakeMove(10) == false );
    REQUIRE( board.makeMove(0, "X") == false );
    REQUIRE( board.makeMove(10, "O") == false );
    board.makeMove(7, "X");
    REQUIRE( board.canMakeMove(7) == false );
}

TEST_CASE( "game is won horizontally - first row" ) {
    Board board;
    REQUIRE( board.isGameWon() == false );
    board.makeMove(1, "X");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(2, "X");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(3, "X");
    REQUIRE( board.isGameWon() == true );
}

TEST_CASE( "game is won horizontally - second row" ) {
    Board board;
    REQUIRE( board.isGameWon() == false );
    board.makeMove(4, "X");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(5, "X");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(6, "X");
    REQUIRE( board.isGameWon() == true );
}

TEST_CASE( "game is won horizontally - third row" ) {
    Board board;
    REQUIRE( board.isGameWon() == false );
    board.makeMove(7, "O");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(8, "O");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(9, "O");
    REQUIRE( board.isGameWon() == true );
}

TEST_CASE( "game is won horizontally - first column" ) {
    Board board;
    REQUIRE( board.isGameWon() == false );
    board.makeMove(1, "X");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(4, "X");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(7, "X");
    REQUIRE( board.isGameWon() == true );
}

TEST_CASE( "game is won horizontally - second column" ) {
    Board board;
    REQUIRE( board.isGameWon() == false );
    board.makeMove(2, "X");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(5, "X");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(8, "X");
    REQUIRE( board.isGameWon() == true );
}

TEST_CASE( "game is won horizontally - third column" ) {
    Board board;
    REQUIRE( board.isGameWon() == false );
    board.makeMove(3, "O");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(6, "O");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(9, "O");
    REQUIRE( board.isGameWon() == true );
}

TEST_CASE( "game is won diagonally - 1" ) {
    Board board;
    REQUIRE( board.isGameWon() == false );
    board.makeMove(1, "X");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(5, "X");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(9, "X");
    REQUIRE( board.isGameWon() == true );
}

TEST_CASE( "game is won diagonally - 2" ) {
    Board board;
    REQUIRE( board.isGameWon() == false );
    board.makeMove(3, "O");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(5, "O");
    REQUIRE( board.isGameWon() == false );
    board.makeMove(7, "O");
    REQUIRE( board.isGameWon() == true );
}


TEST_CASE( "board is full" ) {
    Board board;
    REQUIRE( board.isBoardFull() == false );
    board.makeMove(1, "O");
    REQUIRE( board.isBoardFull() == false );
    board.makeMove(2, "X");
    REQUIRE( board.isBoardFull() == false );
    board.makeMove(3, "O");
    REQUIRE( board.isBoardFull() == false );
    board.makeMove(4, "X");
    REQUIRE( board.isBoardFull() == false );
    board.makeMove(5, "X");
    REQUIRE( board.isBoardFull() == false );
    board.makeMove(6, "O");
    REQUIRE( board.isBoardFull() == false );
    board.makeMove(7, "X");
    REQUIRE( board.isBoardFull() == false );
    board.makeMove(8, "O");
    REQUIRE( board.isBoardFull() == false );
    board.makeMove(9, "X");
    REQUIRE( board.isBoardFull() == true );
}


TEST_CASE( "game is won horizontally by a player making move - first row" ) {
    Board board;
    Player player(&board, "X");
    REQUIRE( board.isGameWon() == false );
    player.makeMove(1);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(2);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(3);
    REQUIRE( board.isGameWon() == true );
}

TEST_CASE( "game is won horizontally by a player making move - second row" ) {
    Board board;
    Player player(&board, "X");
    REQUIRE( board.isGameWon() == false );
    player.makeMove(4);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(5);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(6);
    REQUIRE( board.isGameWon() == true );
}

TEST_CASE( "game is won horizontally by a player making move - third row" ) {
    Board board;
    Player player(&board, "O");
    REQUIRE( board.isGameWon() == false );
    player.makeMove(7);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(8);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(9);
    REQUIRE( board.isGameWon() == true );
}

TEST_CASE( "game is won horizontally by a player making move - first column" ) {
    Board board;
    Player player(&board, "O");
    REQUIRE( board.isGameWon() == false );
    player.makeMove(1);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(4);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(7);
    REQUIRE( board.isGameWon() == true );
}

TEST_CASE( "game is won horizontally by a player making move - second column" ) {
    Board board;
    Player player(&board, "O");
    REQUIRE( board.isGameWon() == false );
    player.makeMove(2);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(5);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(8);
    REQUIRE( board.isGameWon() == true );
}

TEST_CASE( "game is won horizontally by a player making move - third column" ) {
    Board board;
    Player player(&board, "X");
    REQUIRE( board.isGameWon() == false );
    player.makeMove(3);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(6);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(9);
    REQUIRE( board.isGameWon() == true );
}

TEST_CASE( "game is won diagonally by a player making move - 1" ) {
    Board board;
    Player player(&board, "X");
    REQUIRE( board.isGameWon() == false );
    player.makeMove(1);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(5);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(9);
    REQUIRE( board.isGameWon() == true );
}

TEST_CASE( "game is won diagonally by a player making mov - 2" ) {
    Board board;
    Player player(&board, "0");
    REQUIRE( board.isGameWon() == false );
    player.makeMove(3);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(5);
    REQUIRE( board.isGameWon() == false );
    player.makeMove(7);
    REQUIRE( board.isGameWon() == true );
}


TEST_CASE( "board is full by players making moves" ) {
    Board board;
    Player playerO(&board, "O");
    Player playerX(&board, "X");
    REQUIRE( board.isBoardFull() == false );
    playerO.makeMove(1);
    REQUIRE( board.isBoardFull() == false );
    playerX.makeMove(2);
    REQUIRE( board.isBoardFull() == false );
    playerO.makeMove(3);
    REQUIRE( board.isBoardFull() == false );
    playerX.makeMove(4);
    REQUIRE( board.isBoardFull() == false );
    playerX.makeMove(5);
    REQUIRE( board.isBoardFull() == false );
    playerO.makeMove(6);
    REQUIRE( board.isBoardFull() == false );
    playerX.makeMove(7);
    REQUIRE( board.isBoardFull() == false );
    playerO.makeMove(8);
    REQUIRE( board.isBoardFull() == false );
    playerX.makeMove(9);
    REQUIRE( board.isBoardFull() == true );
}

TEST_CASE("players info for Player X and Player O") {
    Player playerX(nullptr, "X");
    Player playerO(nullptr, "O");
    REQUIRE( playerX.info() == "Player X");
    REQUIRE( playerO.info() == "Player O");
}

TEST_CASE("player's win and tie increments") {
    Player playerX(nullptr, "X");
    Player playerO(nullptr, "O");
    playerX.win();
    playerX.win();
    playerX.win();

    int xWin = playerX.win();
    int oWin = playerO.win();

    REQUIRE( xWin == 4);
    REQUIRE( oWin == 1);

    playerO.tie();
    playerX.tie();

    int xTie = playerX.tie();
    int oTie = playerO.tie();
    REQUIRE( xTie == 2);
    REQUIRE( oTie == 2);
}