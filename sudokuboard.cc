
/*
  sudokuboard.cc
  EMMERSON ZHAIME
  LAB NUMBER 3
  10/03/2014

  The code defines each of the methods in the sudokuboard class that
  we declared in sudokuboard.h file.
  
 */
#include "sudokuboard.h"

sudokuboard:: sudokuboard()
{
  // Creating an empty board
  for (int i = 0; i < 9; i++){
      board[i]  = "_________"; 
  }   
}

void sudokuboard:: place(size_t r, size_t c, char n)
{
  // place numeral n at position (r,c)
  board[r][c] = n; 
}

void sudokuboard:: print()const
{
  // write the board to cout
  for(size_t i = 0; i < 9; i++)
    cout << board[i] << endl;
}

char sudokuboard:: get(size_t r, size_t c)const
{
  // return the numeral at position (r,c)
  return board[r][c];
}

void sudokuboard:: remove( size_t r, size_t c)
{
  // replace the numeral at position (r,c) with a blank space
  board[r][c] ='_' ;
}

bool sudokuboard:: canPlace(size_t r, size_t c, char n)const
{
  // returns true if and only if the board would allow placing
  // n at (r,c)
  if(board[r][c] != '_')
    return false;
  
  // checks whether there is another cell with numeral n in 
  // row r and column c
  for(size_t i = 0; i < 9; i++){
    if(board[r][i] == n)
      return false;
    if(board[i][c] == n)
      return false;
  }
  
  // checks whether there is another cell with numeral n in the
  // 3 by 3 square in which (r, c) resides 
  size_t _r = (r/3)*3; // produces the index of the first row in the current 3 by 3 square
  size_t _c = (c/3)*3; // produces the index of the frst column in the current 3 x 3 square

  // check every position in the current 3 by 3 square for the
  // occurrence numeral n
  for(size_t a = _r; a < _r + 3; a++){
    for(size_t b = _c; b < _c + 3; b++){
      if(board[a][b] == n)
	return false;
    }
  }
  return true;       
}

bool sudokuboard:: solved()const
{
  // checks every position on the board to see if there is still a blank cell
  for( size_t j = 0; j < 9; j++){
    for( size_t k = 0; k < 9; k++){
      if(board[j][k] == '_')
	return false; 
    }
  }   
  return true;
}
