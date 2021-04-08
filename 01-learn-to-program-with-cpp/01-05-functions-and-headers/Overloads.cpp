#include <iostream>
using std::cout;

double add(double x, double y)
{
  return x + y;
}

double add(double a, double b, double c) // function overload
{
  return a + b + c; // N.B. alternatively, `return add(add(a, b), c);`
}

bool test(bool x)
{
  return x;
}

bool test(double x) // function overload
{
  return x > 0;
}

int main()
{
  int total = add(3, 4);
  cout << "3 + 4 is " << total << '\n';

  double another = add(1.2, 3.4);

  cout << '\n';
  cout << "1.2 + 3.4 is " << another;
  cout << '\n';

  auto totalofthree = add(1.1, 2.2, 3.3);
  cout << "1.1 + 2.2 + 3.3 is " << totalofthree;
  cout << '\n';

  add(0, 0, 0); // this statement is valid, however, if the return value is not stored then it is simply unused/discarded in the program

  if (test(true)) // N.B. `test(true)` is idiomatic (i.e., as opposed to the more verbose/explicit `test(true) == true`)
  {
    cout << "true passes the test" << '\n';
  }
  if (test(3.2))
  {
    cout << "3.2 passes the test" << '\n';
  }

  /*
  if (test(3)) // this is an ambiguous test: since there is no overalod taking int as a parameter, `3` can be converted  by the compiler to either bool or double among the available function defintions
  {
    cout << "3 passes the test" << '\n';
  }
  */

  return 0;
}
