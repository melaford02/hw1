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

static void addNode(Node*& head, Node* curr);

void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE

if (in == nullptr){
    return;
}

Node* curr = in; 
Node* rest = in->next;
curr->next = nullptr;

if (curr->value % 2 == 0){
    addNode(evens, curr);
} else{
    addNode(odds, curr);
}

in = rest;
split(in, odds, evens);

}

/* If you needed a helper function, write it here */
static void addNode(Node*& head, Node* curr){
    if (head == nullptr){
        head = curr;
        return;
    }
    if(head->next == nullptr){
        head->next = curr;
        return;
    }
    addNode(head->next, curr);
}