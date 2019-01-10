/*
  stack.cc
  EMMERSON ZHAIME
  LAB NUMBER 3
  10/03/2014

  The code defines each of the methods in the stack class defined in stack.h
  file
 */
#include "stack.h"

stack:: stack ()
{
  // set the pointer to NULL
  _head = NULL;
}

stack:: ~stack ()
{
  // destroys each node in the linked list
  node * temp;
  while( _head != NULL){
    temp = _head ->next;
    delete _head;
    _head = temp;
  }

}

void stack:: push (const element  & item)
{
  // adds a new node to the top of the linked list and makes _head
  // point to the new node, and makes the new node pointer point to the node
  // that was previously on top
  node * temp = new node;
  temp -> data = item;
  temp -> next = _head;
  _head = temp;
}

void stack:: pop ()
{
  // deletes the top most element in the stack and makes the pointer
  // point to the new top most element
  node * temp;
  temp = _head;
  _head = _head -> next;
  delete temp;
}

bool stack:: empty () const
{
  // returns true if the stack is empty
  return(_head == NULL);
}

int stack:: top () const
{
  // returns the value stored in the top most node
  return _head -> data;
}
