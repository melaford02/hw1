#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"
using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
ULListStr dat;

  dat.push_back("7");
  dat.push_back("8");
  dat.push_front("first");

  cout << "Expect first 7 8: ";
  for(size_t i=0; i<dat.size(); i++) {
    cout << dat.get(i) << " ";
  }
  cout << endl;

  cout << "Front (expect first): " << dat.front() << endl;
  cout << "Back (expect 8): " << dat.back() << endl;

  dat.pop_front();
  cout << "After pop_front, front (expect 7): " << dat.front() << endl;

  dat.pop_back();
  cout << "After pop_back, back (expect 7): " << dat.back() << endl;

  dat.pop_back();
  cout << "Size after popping everything (expect 0): " << dat.size() << endl;

  return 0;
}