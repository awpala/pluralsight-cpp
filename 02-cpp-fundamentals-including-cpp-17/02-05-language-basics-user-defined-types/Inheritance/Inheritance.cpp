#include "Tweeter.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main()
{
  Person p1("Kate", "Gregory", 123);
  {
    Tweeter t1("Someone", "Else", 456, "@whoever");
    string name2 = t1.getName(); // uses implementation from base class `Person`, since `Twitter` does not implement `getName()`
  }
  cout << "after innermost block" << endl;

  return 0;
}
