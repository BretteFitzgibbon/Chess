#include <iostream>
#include <string>
#include "Bishop.h"

// constructor
Bishop::Bishop(int _row, int _col, bool _isWhite, std::string _name): Piece (_row, _col, _isWhite, _name) {ptype = "Bishop";}

// destructor
Bishop::~Bishop() {std::cout << "Destroying bishop" << std::endl;} 

/*
Boolean method that is true if the Bishop can move to the specified location from its current location. _row, _col is the "to" location of our desired move.
*/
bool Bishop::isLegalMoveTo(int _row, int _col) 
{
    if (abs(row - _row) != (abs(col - _col))) // bishops must move at 45-degree angles  
      return false;
    else if (!board->isClear(row, col, _row, _col)) // are there pieces blocking this potential move?          
      return false;
      /*
      Check if the final location is occupied by a same-colored piece.       If yes, then we are blocked by our own piece. If no, then we           have a capture – which will be handled by the Piece :: moveTo (        ) method.
      */
    Piece* endPiece = board->pieceAt(_row, _col);  // see if there is a piece at the "to" location
    if (endPiece != nullptr) 
    { // check if the piece at the "to" location is of the same color
        if (endPiece->isWhite == isWhite) 
        {
          std::cout << "bishop.isLegalMoveTo(): This move is blocked at the to location by a same-colored piece!" << std::endl;            
         return false; 
        } // cannot move to or capture our own piece!
      std::cout << "bishop.isLegalMoveTo(): This move is ok" << std::endl; // JDY DEBUG
      return true;
      } // done checking piece at "to" location     

  return true; // JDY BUG: we must always return a value
}
