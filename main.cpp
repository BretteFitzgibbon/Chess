#include <iostream>
#include <fstream> // for journal file
#include <string>
#include <vector>
#include <cstdlib> // for abs()
#include "Piece.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "testMe.h"

using namespace std;

/*
r1w, h1w, b1w, Kw, Qw, b2w, h2w, r2w
 p1w,  p2w,  p3w, p4w, p5w,  p6w,  p7w, p8w
 p1b,  p2b,  p3b, p4b, p5b,  p6b,  p7b, p8b
r1b, h1b, b1b, Kb, Qb, b2b, h2b, r2b
*/

int main() 
    {
    cout << "COMP-235 Chess:" << endl;

  // DO TESTING?
  
      cout << "Would you like to test your implementation now? (y/n) "; 
      string resp; 
      getline(cin, resp); // get an entire line of text from the user
  
      if (resp[0] == 'y') 
      {
        testMe();
        cout << "Testing Complete.... Well-played! Goodbye." << endl;
        return 0;
      }
  

  // (else) INTERACTIVE PLAY

      /*
      Create an instance of the chess board, complete with pieces, ready to play.
      */
    ChessBoard gameBoard; 

      /*
        Print all the pieces on the board using the base-class printMe() method from Piece.h
        */
      for(int i = 0; i < 32; i++) 
        gameBoard.pieces[i]->printMe();

    gameBoard.printMe(); // print the entire game board

    ofstream journalMoves("journalMoves.txt");  // open an output journal file to track this game's moves
  
    while(true) 
      {
        char name_Chars[100]; // fixed array for name of piece
        int row; // integer row number, zero-based
        char col_Chars[100]; // fixed array for name of column
        int col; // integer column number, zero-based
        string input_line; // string for collecting the entire input line

        cout << endl << (gameBoard.whiteTurn ? "White" : "Black") << ", Enter a move (name row# col_letter)";
      
        getline(cin, input_line); // get an entire line of text from the user
        if (input_line == "quit") 
          break; 
      
        sscanf(input_line.c_str(), "%s %d %s", name_Chars, & row, col_Chars);
        col = ((int) col_Chars[0] - 96); // convert to int as 1 for a, 2 for b, 3 for c, etc.


        journalMoves << string(name_Chars) <<  " " << row <<  " " << col_Chars[0] << endl; // write the move to the journal file
      
        gameBoard.takeTurn(string(name_Chars), row, col); // allow the current player to take their turn with the provided move
        gameBoard.printMe(); // print out the result of the turn (if taken) after the move

        // BONUS:  implement these methods in ChessBoard.cpp for a +10 for either or both methods (total of +20 points bonus)
        string winnerName = gameBoard.isCheckmate();
        if (winnerName != "None") 
        { // The game is over 
          cout << (winnerName) << " has won the game via checkmate! Goodbye." << endl;
          break;
        }
        else if (gameBoard.isStalemate()) 
        {
          cout << " The game is a stalemate (tie)! Goodbye." << endl;
          break;
        }
    } // end while()

    cout << "Goodbye" << endl;
    journalMoves.close(); // close the journal file
    return 0;
}