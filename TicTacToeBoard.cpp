#include "TicTacToeBoard.h"
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;
}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if(turn == X) {
    turn = O;
  } else {
    turn = X;
  }
  
  return turn;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if(row < 0 || row > 2 || column < 0 || column > 2) {
    return Invalid;
  }
  if(board[row][column] == Blank) {
    board[row][column] = turn;
    Piece prevTurn = turn;
    toggleTurn();
    return prevTurn;
  } else {
    return getPiece(row, column);
  }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if(row < 0 || row > 2 || column < 0 || column > 2) {
    return Invalid;
  }
  if(board[row][column] == Blank) {
    return Blank;
  } else if(board[row][column] == X) {
    return X;
  } else if(board[column][row] == O) {
    return O;
  }
  
  return Invalid;
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  Piece tic, tac, toe;
  int r = 0;
  int c = 0;
  
  //compare rows
  for(int i = 0; i < 3; i++) {
    tic = getPiece(i, c);
    tac = getPiece(i, c+1);
    toe = getPiece(i, c+2);
    
    //look for blank
    if(tic == Blank || tac == Blank || toe == Blank) {
      return Invalid;
    }
    
    if(tic == tac && tic == toe) {
      return tic;
    }
  }
  
  //compare columns
  for(int k = 0; k < 3; k++) {
    tic = getPiece(r, k);
    tac = getPiece(r+1, k);
    toe = getPiece(r+2, k);
    
    //look for blank
    if(tac == Blank || tac == Blank || toe == Blank) {
      return Invalid;
    }
    
    if(tic == tac && tic == toe) {
      return tic;
    }
  }
  
  //compare diagnals
  tic = getPiece(r, c);
  tac = getPiece(r+1, c+1);
  toe = getPiece(r+2, c+2);
  
  if(tic == Blank || tac == Blank || toe == Blank) {
    return Invalid;
  }
  
  if(tic == tac && tic == toe) {
    return tic;
  }
  
  tic = getPiece(r+2, c);
  tac = getPiece(r+1, c+1);
  toe = getPiece(r, c+2);
  
  if(tic == Blank || tac == Blank || toe == Blank) {
    return Invalid;
  }
  
  if(tic == tac && tic == toe) {
    return tic;
  }
  
  return Blank;
}
