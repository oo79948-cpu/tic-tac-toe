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