/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"

/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // WRITE YOUR CODE HERE
  //Recursive terminating checkContent
  if(in == nullptr){
    return;
  }
  
  //Stores this steps value. 
  Node* currVal = in;
  //Updates the 'in' list to the next value.
  in = in->next;
  //Ensures that the current value isn't linked to the 'in' (next value)
  currVal->next = nullptr;

  //Checks if the number is odd or even
  if((currVal->value) % 2 == 0){
  //Adds the new value to the list
    evens = currVal;
  //Continues with soritng
    split(in, odds, evens->next);
  //Updates the pointer to the evens so at the end it keeps the first number.
    evens = currVal;
  }else{
    odds = currVal;
    split(in, odds->next, evens);
    odds = currVal;
  }
}

/* If you needed a helper function, write it here */
	













