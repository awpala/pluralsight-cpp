#include "Person.h"
#include "Tweeter.h"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
  Person p1("Kate", "Gregory", 123);
  {
    Tweeter t1("Someone", "Else", 456, "@whoever");
  }
  cout << "after innermost block" << endl;
  cout << "p1: " << p1.GetName() << " " << p1.GetNumber() << endl;
  p1.SetNumber(124);
  cout << "p1: " << p1.GetName() << " " << p1.GetNumber() << endl;

  return 0;
}
