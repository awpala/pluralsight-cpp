#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <iostream>
#include "Utility.h"

int main()
{
	// basic comparison operations
  int i=2;
  if (i==3)
    cout << "i is 3" << endl;
  cout << "i " << i <<endl;
  // if (i=3) // this is a common error for novices (i.e., using `=` rather than intended `==`)
  //   cout << "i is 3" << endl;
  // cout << "i " << i <<endl;
  i=4;
  if (3==i) // this is a method to guard against inadvertently writing `i=3` via `3=i`, which generates a compiler error (however, this arguably adversly impacts readability; using this style is ultimately a matter of preference)
    cout << "i is 3" << endl;
  cout << "i " << i << endl;

	cout << endl;


	// An example of where assignment within a test condition is useful
  int p = foo("whatever");
  if (p) // N.B. in C++, `0` is equivalent to `false`; accordingly, it is idiomatic to perform tests in this manner, as opposed to `p != 0`
    something();
  if (p = foo("something else")) // N.B. Assignment within a condition is a common idiom in C++ (as well as C)
    something();


	// An example console prompt using comparisons (prime numbers)
  cout << "enter a number " << endl;
  cin >> i;

  cout << i << " is ";
  if (!IsPrime(i))
    cout << "not ";
  cout << "prime." << endl;

  int j;
  cout << "enter a second number " << endl;
  cin >> j;

  cout << i << " is " ;
  if ((j!=0) && !(i % j == 0)) // this test condition expression is short-circuiting with respect to the operator `&&` (notably, if j == 0, `i % j` in the second expression is not evaluated, which would cause a division-by-zero error)
    cout << "not ";
  cout << "a multiple of " << j << endl;

  return 0;
}
