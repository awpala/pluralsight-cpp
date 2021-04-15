#include "Person.h"
#include <iostream>

using std::string;
using std::invalid_argument;

Person::Person() : firstname(""), lastname(""), arbitrarynumber(-1)
{
}

Person::Person(string first, string last, int arbitrary)
  : firstname(first), lastname(last), arbitrarynumber(arbitrary)
{
  if (arbitrarynumber == 0)
  {
    throw invalid_argument("Arbitrary number for a Person cannot be zero.\n"); // N.B. In C++, it is idiomatic to throw an anonymous error object rather than creating an error object (e.g., on the stack) to throw
  }
  // N.B. Any code here would be skipped if the error is thrown
}
