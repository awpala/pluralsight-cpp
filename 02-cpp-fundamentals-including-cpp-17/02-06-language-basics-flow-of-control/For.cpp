#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
  int x;
  cout << "Enter a number" << endl;
  cin >> x;

  bool prime = true;
  for (int i=2; i <= x/i; i = i + 1)
  {
    int factor = x/i;
    if (factor*i == x)
    {
      cout << "factor found: " << i << " * " << factor << endl;
      prime = false;
      break;
    }
  } // `i` goes out of scope past the `for` loop

  // cout << i << endl; // error -- `i` is out of scope here

  cout << x << " is ";
  if (prime)
    cout << "prime" << endl;
  else
    cout << "not prime" << endl;

  return 0;
}
