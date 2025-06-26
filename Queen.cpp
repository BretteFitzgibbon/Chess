#include <iostream>
#include <string>
#include "Queen.h"

Queen::Queen(int _row, int _col, bool _isWhite, std::string _name): Piece (_row, _col, _isWhite, _name) {ptype = "Queen";}
    
Queen::~Queen(){std::cout << "Destroying queen" << std::endl;}   // destructor

bool Queen::isLegalMoveTo(int _row, int _col) // true if this queen can move to the specified location from its current location
{ // _row, _col is the "to" location of our desired move
    if (abs(row - _row) != (abs(col - _col)) && (row != _row && col != _col)) // can move diagonally 
    // {
    //   if (row != _row && col != _col) // if it does not move diagonally, it can move vertically or horizontally, but not both
        return false; 
    //}
    else if (!board->isClear(row, col, _row, _col)) // are there pieces blocking this potential move?          
      return false;
      // Check if the final location is occupied by a same-colored piece           // if yes, then we are blocked by our own piece           // if no, then we have a capture – which will be handled by the Piece :: moveTo ( ) method
    Piece* endPiece = board->pieceAt(_row, _col);  // see if there is a piece at the "to" location
    if (endPiece != nullptr) 
    { // check if the piece at the "to" location is of the same color
        if (endPiece->isWhite == isWhite) 
        {
          std::cout << "queen.isLegalMoveTo(): This move is blocked at the to location by a same-colored piece!" << std::endl;            
         return false; // cannot move to or capture our own piece!        }
      } // done checking piece at "to" location
    }
      return true;
<<<<<<< HEAD
}
=======
}
>>>>>>> e392e0665ac15071173ec630aeebd343ff74dea2
