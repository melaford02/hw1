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
#include <cstddef> // for NULL

/* Add a prototype for a helper function here if you need */
static void addToEnd(Node*& list, Node* item);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
  // WRITE YOUR CODE HERE

  if(in == nullptr) {
    return;
  }

  Node* cur = in;
 
  if (in != nullptr){
    in = in->next;
    cur->next = nullptr;
  }

  // decide if odd or even
  int num_value = cur->value;
  bool even_num = (num_value % 2 == 0);

  if (even_num){
    addToEnd(evens, cur);
  } else {
    addToEnd(odds, cur);
  }

  
  split(in, odds, evens);
}

/* If you needed a helper function, write it here */
static void addToEnd(Node*& list, Node* item) {
if (list == nullptr){
    list = item;
} else if (list->next == nullptr){
    list->next = item;
} else {
    addToEnd(list->next, item);
}
}
