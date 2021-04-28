#include <vector>
#include <algorithm>
#include "Utility.h"

int f(int n) { return n-1; }
int f(int* n) { if (n) return *n; else return 2; }


int main()
{
  std::vector<int> nums{ 1,2,3,4 };
  int total = 0;
  for (auto num:nums)
  {
    total += num;
  }


  int* n = NULL;

  if (n == nullptr)
  {
    n = &nums[2];
  }

  n = nullptr;

  if (n == NULL)
  {
    n = &nums[2];
  }

  auto j = f(0);
  j = f(nullptr);
  // j = f(NULL);

  n = NULL;
  j = f(n);

  int odds = std::count_if(begin(nums), end(nums), isOdd);
  int count = std::count_if(begin(nums), end(nums), [](int i) { return ((i == 2) || (i == 3)); });

  auto something = total * 2;

  int oldNums[10] = { 2,3,4,56,3,2 };
  for (auto& num:oldNums)
  {
    num /= 2;
  }

  return 0;
}
