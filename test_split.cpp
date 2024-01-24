/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include<iostream>
#include "split.h"
using namespace std;

int main(int argc, char* argv[])
{
  Node *list = new Node (1, nullptr);
  Node *oddList = nullptr;
  Node *evenList = nullptr;
  Node *temp = list;
  split (list, oddList, evenList);

  if(list == nullptr){
    cout << endl << "LIST IS NULLPTR" << endl;
  }else{
    cout << list->value <<endl;
  }

  cout << "Odd Numbers" << endl;
  temp = oddList;
  while (1){
    cout << temp->value << endl;
    if (temp->next != nullptr){
	    temp = temp->next;
	  }else{
	    break;
	  }
  }
  cout << "Even Numbers:" << endl;
  temp = evenList;
  while (temp != nullptr){
    cout << temp->value << endl;
    if (temp->next != nullptr){
	    temp = temp->next;
    }else{
	    break;
	  }
  }
  delete list;
  return (0);
}
