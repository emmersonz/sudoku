/*
  sudokuboard.h file
  EMMERSON ZHAIME
  LAB NUMBER 3
  10/03/2014

  The code declares a sudokuboard class which is an object that consists of 
  a board which is a 9 by 9 array of characters. The class consists of methods
  for placing a character on the board, printing the whole board, getting a
  character at a certain position on the board, remove a character at a given
  position, checking whether you can place a given character on a given position
  on the board, and checking whether the board has been solved.
 */

#include <iostream>
using namespace std;

class sudokuboard{

 public:
  // Constructor to initialize the sudokuboard
  sudokuboard();

  void place(size_t r, size_t c, char n); 
  // place numeral n at position (r,c)

  void print() const;
  // write the board to cout

  char get(size_t r, size_t c)const;
  // return the numeral at position (r,c)

  void remove(size_t r, size_t c);
  // remove the numeral at the position (r, c)

  bool canPlace(size_t r, size_t c, char n) const;
  // returns true if and only if the board would allow placing
  // n at (r,c)

  bool solved()const;
  // returns true if and only if there are no blank spots on the board.
  
 private:
  string board[9];

};
