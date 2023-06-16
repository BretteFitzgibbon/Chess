#include <iostream>
#include <string>
#include "King.h"

King::King(int _row, int _col, bool _isWhite, std::string _name): Piece (_row, _col, _isWhite, _name) {ptype = "King";}
    
King::~King() {std::cout << "Destroying king" << std::endl;}   // destructor

bool King::isLegalMoveTo(int _row, int _col) // true if this king can move to the specified location from its current location
{ // _row, _col is the "to" location of our desired move
    if (abs(row - _row) > 1 || abs(col - _col) > 1)
      return false; 
    else if (!board->isClear(row, col, _row, _col)) // are there pieces blocking this potential move?          
      return false;
      // Check if the final location is occupied by a same-colored piece           // if yes, then we are blocked by our own piece           // if no, then we have a capture – which will be handled by the Piece :: moveTo ( ) method
    Piece* endPiece = board->pieceAt(_row, _col);  // see if there is a piece at the "to" location
    if (endPiece != nullptr) 
    { // check if the piece at the "to" location is of the same color
        if (endPiece->isWhite == isWhite) 
        {
          std::cout << "king.isLegalMoveTo(): This move is blocked at the to location by a same-colored piece!" << std::endl;            
         return false; // cannot move to or capture our own piece!        }
      } // done checking piece at "to" location
    }
      return true;
}