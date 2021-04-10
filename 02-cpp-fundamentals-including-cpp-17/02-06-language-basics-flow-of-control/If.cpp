#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
  int x,y;
  cout << "Enter two numbers" << endl;
  cin >> x >> y;

  cout << x << " " ;
  if (x > y)
  {
    cout << "is larger than ";
  }
  else
  {
    cout << "is not larger than ";
  }
  cout << y << endl;

  if (x+y > 10) // N.B. in general, an arbitrarily complex expression can be used for the test condition, provided it evaluates to `0` (`false`) or a non-zero number (`true`)
    cout << "thanks for choosing larger numbers!" << endl;

  return 0;
}
