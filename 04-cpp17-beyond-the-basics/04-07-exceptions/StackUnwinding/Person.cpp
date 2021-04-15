#include "Person.h"
#include <iostream>
#include "Noise.h"

using std::string;
using std::invalid_argument;

Person::Person() : firstname(""), lastname(""), arbitrarynumber(-1)
{
}

Person::Person(string first, string last, int arbitrary)
  : firstname(first), lastname(last), arbitrarynumber(arbitrary)
{
  Noise np("Speaking");
  if (arbitrarynumber == 0)
  {
    throw invalid_argument("Arbitrary number for a Person cannot be zero.\n");
  } // `np` goes out of scope here if `invalid_argument` is thrown`
} // `np` goes out of scope here under normal execution
