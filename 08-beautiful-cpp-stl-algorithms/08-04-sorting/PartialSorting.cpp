#include <vector>
using std::vector;
#include <algorithm>
using std::partial_sort;


int main()
{
  vector<int> v{ 4,1,0,1,-2,3,7,-6,2,0,0,-9,9 };
  auto v2 = v;

  partial_sort(begin(v2), find(begin(v2), end(v2), 4), end(v2));

  int breakpoint = *is_sorted_until(begin(v2), end(v2));

  vector<int> v3(3);
  partial_sort_copy(begin(v), end(v), begin(v3), end(v3));

  return 0;
}
