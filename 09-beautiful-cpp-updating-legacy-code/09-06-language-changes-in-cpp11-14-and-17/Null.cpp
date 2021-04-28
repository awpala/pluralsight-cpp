#include <vector>
using std::vector;

// overload A
int f(int n) { return n-1; }
// overload B
int f(int* n) { if (n) return *n; else return 2; }


int main()
{
  vector<int> nums{ 1,2,3,4 };

  int* n = NULL;
  if (n == nullptr) // `true` -- `NULL` and `nullptr` are therefore equivalent
  {
    n = &nums[2];
  }

  n = nullptr;
  if (n == NULL) // `true`
  {
    n = &nums[2];
  }


  auto j = f(0); // returns `-1` via overload A
  
  j = f(nullptr); // returns `2` via overload B
  
  // j = f(NULL); // error -- compiler detects ambiguous overloads via `NULL` as a "literal," which aliases the `int` value `0`
  n = NULL;
  j = f(n); // returns `2` via overload B -- this alternative works correctly, however

  return 0;
}
