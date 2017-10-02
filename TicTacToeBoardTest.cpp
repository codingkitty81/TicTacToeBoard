/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

//EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	TicTacToeBoard board;
	ASSERT_TRUE(true);
}

TEST(TicTacToeBoardTest, turnToggle) {
	TicTacToeBoard board;
	Piece result = board.toggleTurn();
	ASSERT_EQ(O,result);
}

TEST(TicTacToeBoardTest, multiToggle) {
	TicTacToeBoard board;
	Piece result = board.toggleTurn();
	result = board.toggleTurn();
	ASSERT_EQ(X,result);
}

TEST(TicTacToeBoardTest, pieceXplace) {
	TicTacToeBoard board;
	Piece result = board.placePiece(0, 0);
	ASSERT_EQ(X,result);
}

TEST(TicTacToeBoardTest, pieceOplace) {
	TicTacToeBoard board;
	board.toggleTurn();
	Piece result = board.placePiece(1, 1);
	ASSERT_EQ(O,result);
}

TEST(TicTacToeBoardTest, pieceOOBplace) {
	TicTacToeBoard board;
	Piece result = board.placePiece(3, 0);
	ASSERT_EQ(Invalid,result);
}

TEST(TicTacToeBoardTest, pieceTakenPlace) {
	TicTacToeBoard board;
	board.placePiece(2, 0);
	Piece result = board.placePiece(2, 0);
	ASSERT_EQ(X,result);
}

TEST(TicTacToeBoardTest, pieceXget) {
	TicTacToeBoard board;
	board.placePiece(1, 1);
	Piece result = board.getPiece(1, 1);
	ASSERT_EQ(X,result);
}

TEST(TicTacToeBoardTest, pieceX2get) {
	TicTacToeBoard board;
	board.placePiece(2, 1);
	Piece result = board.getPiece(2, 1);
	ASSERT_EQ(X,result);
}

TEST(TicTacToeBoardTest, pieceOget) {
	TicTacToeBoard board;
	board.toggleTurn();
	board.placePiece(1, 1);
	Piece result = board.getPiece(1, 1);
	ASSERT_EQ(O,result);
}
/**
 * BUG: When getting the piece from a specific position on the board, if
 * that position is neither blank or X, then when checking for O the column
 * and row are flipped. For example if checking position 2,1 and it is neither
 * Blank or X, position 1,2 will be checked for an O. If this position is
 * not an O, the function will return Invalid.
**/
TEST(TicTacToeBoardTest, pieceO2get) {
	TicTacToeBoard board;
	board.toggleTurn();
	board.placePiece(2, 1);
	Piece result = board.getPiece(2, 1);
	ASSERT_EQ(O,result);
}

TEST(TicTacToeBoardTest, pieceOOBget) {
	TicTacToeBoard board;
	Piece result = board.getPiece(0, 3);
	ASSERT_EQ(Invalid,result);
}

TEST(TicTacToeBoardTest, gameNotOver1) {
	TicTacToeBoard board;
	board.placePiece(0, 0);
	board.toggleTurn();
	board.placePiece(1, 1);
	board.toggleTurn();
	board.placePiece(2, 2);
	Piece result = board.getWinner();
	ASSERT_EQ(Invalid,result);
}

TEST(TicTacToeBoardTest, gameNotOver2) {
	TicTacToeBoard board;
	board.toggleTurn();
	board.placePiece(0, 2);
	board.toggleTurn();
	board.placePiece(1, 1);
	board.toggleTurn();
	board.placePiece(2, 0);
	Piece result = board.getWinner();
	ASSERT_EQ(Invalid,result);
}
/**
 * BUG: When getting the piece from a specific position on the board, if
 * that position is neither blank or X, then when checking for O the column
 * and row are flipped. For example if checking position 2,1 and it is neither
 * Blank or X, position 1,2 will be checked for an O. If this position is
 * not an O, the function will return Invalid.
**/
TEST(TicTacToeBoardTest, getOwinnerRow) {
	TicTacToeBoard board;
	board.toggleTurn();
	board.placePiece(0, 0);
	board.toggleTurn();
	board.placePiece(0, 1);
	board.toggleTurn();
	board.placePiece(0, 2);
	Piece result = board.getWinner();
	ASSERT_EQ(O,result);
}

TEST(TicTacToeBoardTest, getXwinnerRow) {
	TicTacToeBoard board;
	board.placePiece(0, 0);
	board.toggleTurn();
	board.placePiece(0, 1);
	board.toggleTurn();
	board.placePiece(0, 2);
	Piece result = board.getWinner();
	ASSERT_EQ(X,result);
}

TEST(TicTacToeBoardTest, getXwinnerCol) {
	TicTacToeBoard board;
	board.placePiece(1, 1);
	board.placePiece(0, 0);
	board.placePiece(0, 1);
	board.placePiece(2, 0);
	board.placePiece(1, 0);
	board.placePiece(1, 2);
	board.placePiece(2, 1);
	board.placePiece(0, 2);
	board.placePiece(2, 2);
	Piece result = board.getWinner();
	ASSERT_EQ(X,result);
}
