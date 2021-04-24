#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
using std::is_sorted;


int main()
{
  vector<int> v{ 4,1,0,1,-2,3,7,-6,2,0,0,-9,9 };
  auto v2 = v;
  sort(begin(v2), end(v2), 
    [](int elem1, int elem2) {return abs(elem1) > abs(elem2); });

  auto sorted = is_sorted(begin(v2), end(v2)); // `false`
  sorted = is_sorted(begin(v2), end(v2),[](int elem1, int elem2) {return abs(elem1) > abs(elem2); }); // `true`

  return 0;
}
