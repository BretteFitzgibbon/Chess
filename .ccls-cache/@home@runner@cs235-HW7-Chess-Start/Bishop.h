#pragma once
#include <iostream>
#include <string>
#include "Piece.h"

class Bishop : public Piece 
{  // Bishop derives from (inherits from) Piece
  public:   
    Bishop(int _row, int _col, bool _isWhite, std::string _name); // construct a Bishop this location, of the specified colors, with the specified screen name (b1b, b2b, b1w, b2w)
    ~Bishop();   // destructor
    bool isLegalMoveTo(int _row, int _col); // true if this Bishop can move to the specified location from its current location
};