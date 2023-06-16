#include <iostream>
#include <string>
#include "Pawn.h"

Pawn::Pawn(int _row, int _col, bool _isWhite, std::string _name): Piece (_row, _col, _isWhite, _name) {ptype = "Pawn";}
    
Pawn::~Pawn() {std::cout << "Destroying pawn" << std::endl;}   // destructor

bool Pawn::isLegalMoveTo(int _row, int _col) // true if this pawn can move to the specified location from its current location
{ // _row, _col is the "to" location of our desired move
    if(isWhite == true)
    {
      if(_row < row) // cannot move backwards
        return false;
      if (row == 2)
      {
        if (_row - row > 2) // can move two spaces on first move
          return false;
        //else
          //return true;
      }
      else
      {
        if (_row - row > 1) // cannot move more than one row up
        return false;
      }
      if (col != 1 && col != 8) // these two columns have only one diagonal space on the board
      {
        Piece* capturePiece1 = board->pieceAt(row + 1, col - 1); // left diagonal
        Piece* capturePiece2 = board->pieceAt(row + 1, col + 1); // right diagonal
        if (capturePiece1 != nullptr && capturePiece1->isWhite != isWhite)
        {
          if(capturePiece1->row == _row && capturePiece1->col == _col)
            return true;
        }
        else if (capturePiece2 != nullptr && capturePiece2->isWhite != isWhite)
        {
          if(capturePiece2->row == _row && capturePiece2->col == _col)
            return true;
        }
      }
      else if (col == 1)
      {
        Piece* capturePiece = board->pieceAt(row + 1, col + 1); // right diagonal
        if (capturePiece != nullptr && capturePiece->isWhite != isWhite)
        {
          if(capturePiece->row == _row && capturePiece->col == _col)
            return true;
        }
      }
      else if (col == 8)
      {
        Piece* capturePiece = board->pieceAt(row + 1, col - 1); // left diagonal
        if (capturePiece != nullptr && capturePiece->isWhite != isWhite)
        {
          if(capturePiece->row == _row && capturePiece->col == _col)
            return true;
      }
      }
      else 
        return false; // cannot move diagonally unless it is to capture
    }
    else // row arithmetic is reversed for black pieces
    {
      if (_row > row) // cannot move backwards
        return false;
      if (row == 7)
      {
        if (row - _row > 2) // can move two spaces on first move
          return false;
        //else
          //return true;
      }
      else
      {
        if (row - _row > 1) // cannot move more than one row down
        return false;
      }
      //if (row - _row > 1) 
        //return false;
      if (col != 1 && col != 8) // these two columns have only one diagonal space on the board
      {
        Piece* capturePiece1 = board->pieceAt(row - 1, col - 1); // left diagonal
        Piece* capturePiece2 = board->pieceAt(row - 1, col + 1); // right diagonal
        if (capturePiece1 != nullptr && capturePiece1->isWhite != isWhite)
        {
          if(capturePiece1->row == _row && capturePiece1->col == _col)
            return true;
        }
      else if (capturePiece2 != nullptr && capturePiece2->isWhite != isWhite)
      {
        if(capturePiece2->row == _row && capturePiece2->col == _col)
          return true;
      }
     }
    else if (col == 1)
      {
      Piece* capturePiece = board->pieceAt(row - 1, col + 1); // right diagonal
      if (capturePiece != nullptr && capturePiece->isWhite != isWhite)
      {
        if(capturePiece->row == _row && capturePiece->col == _col)
          return true;
      }
      }
      else if (col == 8)
      {
      Piece* capturePiece = board->pieceAt(row - 1, col - 1); // left diagonal
      if (capturePiece != nullptr && capturePiece->isWhite != isWhite)
      {
        if(capturePiece->row == _row && capturePiece->col == _col)
          return true;
      }
      }
      else
        return false; // cannot move diagonally unless it is to capture
    }
    if (_col != col) // cannot move to a different column
      return false;
    if (!board->isClear(row, col, _row, _col)) // are there pieces blocking this potential move?          
      return false;
      // Check if the final location is occupied by a same-colored piece           // if yes, then we are blocked by our own piece           // if no, then we have a capture – which will be handled by the Piece :: moveTo ( ) method
    Piece* endPiece = board->pieceAt(_row, _col);  // see if there is a piece at the "to" location
    if (endPiece != nullptr) 
    { // check if the piece at the "to" location is of the same color
        //if (endPiece->isWhite == isWhite) 
        //{
          std::cout << "pawn.isLegalMoveTo(): This move is blocked!"<<std::endl;     
         return false; // cannot move to or capture our own piece!        }
       // done checking piece at "to" location
    }
  return true;
  }
