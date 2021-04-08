#include <iostream>
using std::cout;

#include "Functions.h" // include user-defined header file

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

  add(0, 0, 0);

  if (test(true))
  {
    cout << "true passes the test" << '\n';
  }
  if (test(3.2))
  {
    cout << "3.2 passes the test" << '\n';
  }

  return 0;
}
