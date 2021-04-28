#include <vector>
using std::vector;


int main()
{
  vector<int> nums{ 1,2,3,4 };

  // old style: loop via iterator type declaration
  int total = 0;
  for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
  {
    total += *it;
  }

  // better modern alternative: loop via `auto` type deduction of iterator
  total = 0;
  for (auto it = nums.begin(); it != nums.end(); it++)
  {
    total += *it;
  }


  // old style: separate declaration and initialization
  /*
  int something;

  // other code in between...

  something = total * 2;
  */

  // better modern alternative: declare and initialize simultaneously, using `auto`
  auto something = total * 2;

  return 0;
}
