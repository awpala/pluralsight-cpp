#include <iostream>
using std::cout;

int add(int x, int y)
{
  return x + y;
}

int main()
{
  int total = add(3, 4);
  cout << "3 + 4 is " << total << '\n';

  double another = add(1.2, 3.4); // warning: 1.2 and 3.4 are truncated to 1 and 3 (respectively)

  cout << '\n';
  cout << "1.2 + 3.4 is " << another;
  cout << '\n';

  return 0;
}
