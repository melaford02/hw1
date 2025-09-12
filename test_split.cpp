/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"

using namespace std;

void printList(Node* head) {
  Node* cur = head;
  while(cur != nullptr) {
    cout << cur->value << " ";
    cur = cur->next;
  }
  cout << endl;
}

void freeList(Node* head) {
  while(head != nullptr) {
    Node* nxt = head->next;
    delete head;
    head = nxt;
  }
}

int main(int argc, char* argv[])
{
Node* in1 = new Node(1, new Node(2, new Node(3, new Node(4, nullptr))));
  Node* odds1 = nullptr;
  Node* evens1 = nullptr;

split(in1, odds1, evens1);

 cout << "odds1 (expect 1 3): ";
  printList(odds1);
  cout << "evens1 (expect 2 4): ";
  printList(evens1);

  freeList(odds1);
  freeList(evens1);

  //test odd values
  Node* in2 = new Node(1, new Node(3, new Node(5, nullptr)));
  Node* odds2 = nullptr;
  Node* evens2 = nullptr;

  split(in2, odds2, evens2);

cout << "odds2 (expect 1 3 5): ";
  printList(odds2);
  cout << "evens2 (empty): ";
  printList(evens2);

  freeList(odds2);
  freeList(evens2);

  //empty list

  Node* in3 = nullptr;
  Node* odds3 = nullptr;
  Node* evens3 = nullptr;

  split(in3, odds3, evens3);

  cout << "odds3 (empty): ";
  printList(odds3);
  cout << "evens3 (empty): ";
  printList(evens3);

  return 0;




}