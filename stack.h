/*
  stack.
  EMMERSON ZHAIME
  LAB NUMBER 3
  10/03/2014

  The code declares a node-based stack class which consists of a method
  to construct a stack, destroy a stack, add an element to the stack, 
  remove the top most element from the stack, check whether the stack
  is empty, return the top most element in the stack.
 */
#include <iostream>
using namespace std;

struct node {
  // construct a node which consists of a data element and a node pointer
  int data;
  node *next;
};

class stack{

 public:
  typedef int element;
  // Constructor to make the stack
  stack();
  
  //Destructor to destroy the board
  ~stack();

  // add an element to the stack
  void push (const element  & item);

  // remove the top most element from stack
  void pop ();

  // return true if the stack is empty
  bool empty () const;

  // return the top most element in the stack
  int  top () const;
 
private:
  node *_head;
};
