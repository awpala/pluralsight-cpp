#include "Noise.h"
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
  Noise n1("beep 1");
  try
  {
    Noise n2("bloop 2");
    Person Kate("Kate", "Gregory", 0);
    int j = v.at(99); // this line never executes -- error is thrown by `Kate`'s constructor before reaching this line
  } // before going to the `catch` block, the stack is unwound, resulting in the destruction of `np` (from the scope of `Kate`'s constructor) and `n2` (from this scope's `try` block) -- cleanup occurs automatically!
  catch (out_of_range & e)
  {
    cout << " out of range exception " << e.what();
  }
  catch (exception &  e)
  {
    cout << e.what();
  } 
  cout << "After `catch` block" << '\n';

  return 0;
} // `n1` goes out of scope here
