#include "Person.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;

int main()
{
  Person p1("Kate", "Gregory", 123);
  {
    Person p2;
  }
  cout << "after innermost block" << endl;

  return 0;
}
