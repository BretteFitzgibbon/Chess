#include <iostream>
#include <string>
#include "Pawn.h"

// constructor
Pawn::Pawn(int _row, int _col, bool _isWhite, std::string _name): Piece (_row, _col, _isWhite, _name) {ptype = "Pawn";}

// destructor
Pawn::~Pawn() {std::cout << "Destroying pawn" << std::endl;}  

/* 
  Boolean method to see if the Pawn can move to the specified location from its current location
*/
bool Pawn::isLegalMoveTo(int _row, int _col) 
{ // _row, _col is the "to" location of our desired move

    // Check if trying to move diagonally for capture
    bool isDiagonalMove = (_col != col);

    if(isWhite == true) {
        if(_row <= row) // cannot move backwards or stay in same row
            return false;

        // Handle diagonal moves (captures only)
        if (isDiagonalMove) {
            if (abs(_col - col) != 1 || _row - row != 1) // must be exactly one diagonal
                return false;

            Piece* capturePiece = board->pieceAt(_row, _col);
            if (capturePiece != nullptr && capturePiece->isWhite != isWhite) {
                return true; // valid capture
            }
            return false; // no piece to capture diagonally
        }

        // Handle forward moves (non-diagonal)
        if (row == 2) {
            if (_row - row > 2) // can move two spaces on first move
                return false;
        } else {
            if (_row - row > 1) // cannot move more than one row up
                return false;
        }
    }
    else // black pieces
    {
        if (_row >= row) // cannot move backwards or stay in same row
            return false;

        // Handle diagonal moves (captures only)
        if (isDiagonalMove) {
            if (abs(_col - col) != 1 || row - _row != 1) // must be exactly one diagonal
                return false;

            Piece* capturePiece = board->pieceAt(_row, _col);
            if (capturePiece != nullptr && capturePiece->isWhite != isWhite) {
                return true; // valid capture
            }
            return false; // no piece to capture diagonally
        }

        // Handle forward moves (non-diagonal)
        if (row == 7) {
            if (row - _row > 2) // can move two spaces on first move
                return false;
        } else {
            if (row - _row > 1) // cannot move more than one row down
                return false;
        }
    }

    // For non-diagonal moves, check if path is clear and destination is empty
    if (!board->isClear(row, col, _row, _col)) // are there pieces blocking this potential move?          
        return false;

    Piece* endPiece = board->pieceAt(_row, _col);  // see if there is a piece at the "to" location
    if (endPiece != nullptr) {
        // Forward moves cannot capture
        return false;
    }

    return true;
}