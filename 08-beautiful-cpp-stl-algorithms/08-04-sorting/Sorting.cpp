#include <vector>
using std::vector;
#include <algorithm>
using std::sort;


int main()
{
  vector<int> v{ 4,1,0,1,-2,3,7,-6,2,0,0,-9,9 };
  auto v2 = v; // N.B. copy `v` to `v2` to preserve pre-sorted state in `v` for later reference
  sort(begin(v2), end(v2)); // sort "numerically ascending" (default via `<` comparison of `int`s) 
  sort(begin(v2), end(v2), 
    [](int elem1, int elem2) {return elem1 > elem2; }); // predicate to sort "numerically descending"
  sort(begin(v2), end(v2), 
    [](int elem1, int elem2) {return abs(elem1) > abs(elem2); }); // predicate to sort "numerically descending by unsigned magnitude"

  return 0;
}
