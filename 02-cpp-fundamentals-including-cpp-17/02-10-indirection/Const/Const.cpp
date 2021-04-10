#include "Person.h"

int DoubleIt(int const& x) // declaring as `const&` prevents modification of `x` from caller (i.e., "read-only")
{
  return x*2;
}


int main()
{
  /* `const` with references */
  int i = 3;

  int const ci = 3; // declare a `const`
  i = 4;
  // ci = 4; // error -- cannot change a `const`

  int& ri = i; // reference
  ri = 5;

  int const & cri = i; // `const` reference to `i`
  //cri = 6; // error -- cannot change a `const` reference (i.e., while `i` can be changed, `cri` cannot)

  // int& ncri = ci; // error -- cannot create a non-`const` reference to a `const` (if this were permitted, `ncri` could be used to change `i`, which is a `const`)
  

  /* function call by reference */
  int j = 10;
  int DoubleJ = DoubleIt(j); // int variable argument, passed by reference
  int DoubleTen = DoubleIt(10); // int literal argument, passed by reference


  /* working with objects */
  Person Kate("Kate", "Gregory", 234);
  Kate.SetNumber(235);
  Person const cKate = Kate; // `const` object
  //cKate.SetNumber(236); // error -- cannot set member variable for a `const` object
  int KateNumber = cKate.GetNumber(); // N.B. this only works if `GetNumber()` is declared as a `const` function

  return 0;
}
