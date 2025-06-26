#include <iostream>
#include <string>
#include "Bishop.h"

Bishop::Bishop(int _row, int _col, bool _isWhite, std::string _name): Piece (_row, _col, _isWhite, _name) {ptype = "Bishop";}
<<<<<<< HEAD

// destructor
Bishop::~Bishop() {std::cout << "Destroying bishop" << std::endl;} 

/* 
Boolean to assess whether the Bishop can move to the specified location from its current location.
Params: _row and _col are the location of our desired move.
*/
bool Bishop::isLegalMoveTo(int _row, int _col) 
{ 
  // Bishops must move at 45-degree angles  
  if (abs(row - _row) != (abs(col - _col))) 
      return false;
    // Are there pieces blocking this potential move?
    else if (!board->isClear(row, col, _row, _col)) 
      return false;
    /*
    Check if the final location is occupied by a same-colored piece.
    If yes, then we are blocked by our own piece.
    If no, then we have a capture – which will be handled by the Piece :: moveTo ( ) method
    */
    Piece* endPiece = board->pieceAt(_row, _col);  
    // See if there is a piece at the "to" location
    if (endPiece != nullptr) 
    { // Check if the piece at the "to" location is of the same color
        if (endPiece->isWhite == isWhite) 
        {
          std::cout << "bishop.isLegalMoveTo(): This move is blocked at the to location by a same-colored piece!" << std::endl;            
         return false; // Cannot move to or capture our own piece!    
      } // Done checking piece at "to" location
=======
    
Bishop::~Bishop() {std::cout << "Destroying bishop" << std::endl;}// destructor

bool Bishop::isLegalMoveTo(int _row, int _col) // true if this Bishop can move to the specified location from its current location
{ // _row, _col is the "to" location of our desired move
    if (abs(row - _row) != (abs(col - _col))) // bishops must move at 45-degree angles  
      return false;
    else if (!board->isClear(row, col, _row, _col)) // are there pieces blocking this potential move?          
      return false;
      // Check if the final location is occupied by a same-colored piece           // if yes, then we are blocked by our own piece           // if no, then we have a capture – which will be handled by the Piece :: moveTo ( ) method
    Piece* endPiece = board->pieceAt(_row, _col);  // see if there is a piece at the "to" location
    if (endPiece != nullptr) 
    { // check if the piece at the "to" location is of the same color
        if (endPiece->isWhite == isWhite) 
        {
          std::cout << "bishop.isLegalMoveTo(): This move is blocked at the to location by a same-colored piece!" << std::endl;            
         return false; // cannot move to or capture our own piece!        }
      } // done checking piece at "to" location
>>>>>>> e392e0665ac15071173ec630aeebd343ff74dea2
    }
      return true;
}
