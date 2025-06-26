#include <iostream>
#include <string>
#include "Knight.h"

Knight::Knight(int _row, int _col, bool _isWhite, std::string _name): Piece (_row, _col, _isWhite, _name) {ptype = "Knight";}
    
Knight::~Knight(){std::cout << "Destroying knight" << std::endl;}   // destructor

bool Knight::isLegalMoveTo(int _row, int _col) // true if this knight can move to the specified location from its current location
{ // _row, _col is the "to" location of our desired move
    if (row == _row || col == _col) // must end up in both a different row and a different column
      return false;
    else if (abs(row - _row) == abs(col - _col)) // cannot move diagonally
      return false;
    else if (abs(row - _row) > 2 || abs(col - _col) > 2) // moving too far
      return false;
      // Check if the final location is occupied by a same-colored piece           // if yes, then we are blocked by our own piece           // if no, then we have a capture – which will be handled by the Piece :: moveTo ( ) method
    Piece* endPiece = board->pieceAt(_row, _col);  // see if there is a piece at the "to" location
    if (endPiece != nullptr) 
    { // check if the piece at the "to" location is of the same color
        if (endPiece->isWhite == isWhite) 
        {
          std::cout << "knight.isLegalMoveTo(): This move is blocked at the to location by a same-colored piece!" << std::endl;            
         return false; // cannot move to or capture our own piece!        }
      } // done checking piece at "to" location
    }
      return true;
<<<<<<< HEAD
}
=======
}
>>>>>>> e392e0665ac15071173ec630aeebd343ff74dea2
