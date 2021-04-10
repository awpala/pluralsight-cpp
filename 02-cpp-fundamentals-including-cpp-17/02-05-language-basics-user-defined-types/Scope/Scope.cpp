#include "Person.h"
#include <iostream>

int main()
{
  Person p1("Kate", "Gregory", 123);
  { // defines a scope
    Person p2;
  } // `p2` goes out of scope here
  std::cout << "after innermost block" << std::endl;

  return 0;
} // `p1` goes out of scope here
