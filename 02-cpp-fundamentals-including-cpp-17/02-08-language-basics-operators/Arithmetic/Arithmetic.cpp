#include <iostream>
using std::cout;
using std::endl;
#include "Utility.h"


int main()
{
	// basic arithmetic operators
  int i=0;
  i += 2; // `i` is 2
  i *= 3; // `i` is 6
  i -= 2; // `i` is 4
  i /= 4; // `i` is 1

	// increment and decrement operators
  int j = i++; // `j` is 1 -- due to postfix `++`, `i` is incremented after assignment
  j = ++i; // `j` is 3 -- due to prefix `++`, `i` is incremented before assignment
  j = i--; // `j` is 3
  j = --i; // `j` is 1

	// example of using arithmetic operators with loops
  i = 2;
  j = 0;
  while (i<101)
    j += IsPrime(i++) ? 1 : 0; // N.B. arbitrarily complex expressions can be used in C++ -- this can make for compact code, but also difficult to read/understand; the appropriate balance comes with experience
  cout << "I found " << j << " primes up to 100" << endl;

  return 0;
}
