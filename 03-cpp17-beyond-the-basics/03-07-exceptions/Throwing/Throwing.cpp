// #include "Noise.h"
#include "Person.h"

#include <vector>
using std::vector;
#include <iostream>
using std::cout;
#include <exception>
using std::exception;
using std::out_of_range;

int main()
{
  vector<int> v;
  v.push_back(1);
  try
  {
    Person Kate("Kate", "Gregory", 0);
    int j = v.at(99);
  }
  catch (out_of_range & e)
  {
    cout << " out of range exception " << e.what();
  }
  catch (exception &  e) // catching `e` by reference allows to catch more specific errors of error classes derived from `std::error` (e.g., `std::invalid_argument`), i.e., no slicing occurs
  {
    cout << e.what();
  }
  return 0;
}
