#include "Collection.h"
#include <vector>
using std::vector;
#include <algorithm>
using std::generate_n;
using std::fill;


void Collection::OldOne(int howmany) // allocate array `OldNumbers`
{
  OldNumbers = new int[howmany];
  count = howmany; // update separate variable `count` to track size
}

void Collection::OldTwo(int repeat, int value) // use array `OldNumbers`
{
  if (repeat > count)
    repeat = count;
  while (repeat--) // this is a common idiom in legacy code: use the size variable directly (since its value is no longer needed) rather than a new, separate variable
    OldNumbers[repeat] = value;
}

void Collection::OldThree() // clean up array `OldNumbers`
{
  delete[] OldNumbers; // must deallocate manually to prevent memory leak
}


void Collection::NewOne(int howmany)
{
  generate_n(back_inserter(NewNumbers), howmany, []() { return -1; });
}

void Collection::NewTwo(int repeat, int value)
{
  if (repeat > NewNumbers.size())
    repeat = NewNumbers.size();
  fill(begin(NewNumbers), begin(NewNumbers) + repeat, value);
}

void Collection::NewThree() // this function (corresponding to `OldThree()`) is not necessary -- `std::vector` instance cleans itself up automatically upon going out of scope!
{
}
