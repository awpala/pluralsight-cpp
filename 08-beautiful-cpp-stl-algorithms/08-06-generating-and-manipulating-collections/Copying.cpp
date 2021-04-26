#include <vector>
using std::vector;
#include <algorithm>
using std::find;
using std::copy;
using std::copy_if;
using std::copy_n;
using std::copy_backward;


int main()
{
  vector<int> source {3, 6, 1, 0, -2, 5};
  vector<int> v2(source.size());

  // copy from `source` to `v2`
  copy(begin(source), end(source), begin(v2));

  // for `std::vector` (and other Standard Library containers), the overloaded operator `=` performs the equivalent to `std::copy()` over range `std::begin()` to `std::end()`
  auto v3 = source;


  // `std::copy()` is more generally useful, however, when copying only a subset of the elements
  auto position = find(begin(source), end(source), 1);
  vector<int> v4(source.size());
  copy(begin(source), position+1, begin(v4)); // `v4` now contains {3, 6, 1, ...}

  vector<int> v5(source.size());
  copy_if(begin(source), end(source), begin(v5), 
    [](int elem) {return elem % 2 == 0; }); // copy only even elements via predicate


  // other copying functions
  copy_n(begin(v5), 3, begin(v2));

  copy(begin(source), position + 1, position + 1); // N.B. `+ 1` offset is used to include the element at `position` (i.e., this exludes the element immediately following `position`)

  copy_backward(begin(v3), end(v3), end(source)); // `std::copy_backward()` prevents "collisions" when copying elements

  // copy(begin(source), end(source) - 1, begin(source) + 1); // `begin(source) + 1` is inside of the range, therefore, a better approach (i.e., to avoid "copy collisions") is to used `std::copy_backward()` instead
  copy_backward(begin(source), end(source) - 1, end(source)); // equivalent to previous line, but better/safer approach via `std::copy_backward()`

  return 0;
}
