/*
  sudoku.cc
  EMMERSON ZHAIME
  LAB NUMBER 3
  10,03/2014

 The code takes a sudokuboard and solve it by placing an appropriate number
 on each of the positions on the board.
 */

#include "sudokuboard.h"
#include "stack.h"
#include <iostream>
using namespace std;

// Create a sudokuboard and a stack
sudokuboard b;
stack st;

char search_numeral (const sudokuboard & b, size_t r, size_t c, char n)
{
  // returns the smallest numeral that can be placed on (r, c)
  for(char i = '1' ; i <= '9'; i++){
    if(b.canPlace(r,c,i))
      return i;
  }
  return ':';
}

char next_numeral (const sudokuboard & b, size_t r, size_t c, char n)
{
  // returns the smallest numeral greater than n that can be placed
  // on (r, c)
  for (char i = n + 1; i <= '9'; i++){
    if(b.canPlace(r, c, i))
      return i;
  }
  return ':';
}

bool find_most_constrained (size_t & r, size_t &  c, char & num)
{
  // chooses the best blank position on the board to place a numeral;
  // the best position is the one at which the fewest numerals can be placed.
  // It then places the smallest numeral that can be placed at that position 
  // and return true.

  // set a variable to keep the number of numerals that can be placed on the most
  // constrained cell so far
  size_t current_constrained = 10; 

  // search for empty cells on the board
  for (size_t i = 0; i < 9; i++){
    for (size_t j = 0; j < 9; j++){

      // create variable to count the number of numerals that can be placed on a cell
      size_t count = 0; 
      if (b.get(i,j) == '_'){
	for (char x = '1'; x <= '9'; x++){
	  if(b.canPlace(i,j,x))
	     count++ ;
	}
	if(count != 0){

	  // If the current cell is more constrained than the current most 
	  // constrained cell set that cell to be the current most constrained cell
	  if(count < current_constrained){
	    
	    // change value of the most constrained cell to the current cell
	    current_constrained = count;
	    r = i;
	    c = j;

	    // set the value on num to the smallest numeral that can be placed there
	    num = search_numeral(b, r, c, num);
	  } 
	}  
      }	  
    }
  }
  // if the value of current_constrained is not changed then a most constrained cell
  // doesn't exist
  return (current_constrained != 10);
}



void solve(sudokuboard & b, size_t  r, size_t c, char num)  
{
  while (not b.solved()){
      if(find_most_constrained(r, c, num)){
	
	// if a curent most constrained cell exist place the appropriate numeral on
	// it and push the position of that cell onto the stack.
	b.place(r, c, num);
	st.push(r);
	st.push(c);
      }
      else{
	
	// remove the the position of the current cell from the stack and remove
	// the numeral at that position from board
	do {
 	  c = st.top(); st.pop();
	  r = st.top(); st.pop();
	  num = b.get(r,c);
	  b.remove(r, c);

	  // find the next numeral that can be placed on (r, c)
	  // until we find an appropriate number to be placed there then put
	  // it there and push the (r, c) onto the stack
	  num = next_numeral( b, r, c, num);
	} while (num > '9');
	  b.place(r, c, num);
	  st.push(r);
	  st.push(c);
      }
  }
}   

int main()
{
  // put every numeral on the testfile to appropriate position on the board
  for (int i = 0; i < 9; i++){
    for (int j = 0; j < 9; j++){
      char c;
      cin >> c;
      b.place(i,j,c);
    }
    cin.ignore();
  }
  
  // solve and print the board
  solve(b, 0, 0, '1');
  b.print();
}

