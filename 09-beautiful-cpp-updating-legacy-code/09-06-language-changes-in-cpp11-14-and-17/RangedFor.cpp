#include <vector>
using std::vector;


int main()
{
  vector<int> nums{ 1,2,3,4 };

  int total = 0;
  for (auto it = nums.begin(); it != nums.end(); it++) // access via iterator `it`
  {
    total += *it;
  }
  
  // range-based `for` loop -- equiavalent to `for` loop construct above
  total = 0;
  for (auto num:nums) // access by value via element `num`
  {
    total += num;
  }


  int oldNums[10] = { 2, 3, 4, 56, 3, 2 }; // C-style array -- N.B. the remaining four elements auto-initialized to `0` by compiler

  // old-style: iterate via raw `for` loop
  /*
  for (int i = 0; i < 10; i++)
  {
    oldNums[i] /= 2;
  }
  */

  // better modern approach: range-based `for` loop
  for (auto& num:oldNums) // access by reference via `&num` -- N.B. accessing by value via `num` will not modify the original array, but rather simply access the values
  {
    num /= 2;
  }

  return 0;
}
