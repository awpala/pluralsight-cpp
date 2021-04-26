#include <vector>
using std::vector;
#include <algorithm>
using std::unique;
using std::unique_copy;


int main()
{
  vector<int> source {3, 6, 1, 0, -2, 5};
  auto v2 = source;
  vector<int> v7(10);

  unique(begin(v2), end(v2)); // moves any consecutive duplicate values to the end (none such occur in `v2`, which remains unchanged)
  
  v2[3] = -2;
  v2.erase(unique(begin(v2), end(v2)),end(v2)); // `v2` now contains only unique elements, with duplicate `-2`s removed -- performing in a single line (i.e., `std::unique()` nested inside of method `erase()`) is a common idiom
  
  auto v8 = v2;
  unique_copy(begin(v8), end(v8), begin(v7)); // copies unique elements from `v8` to `v7`

  return 0;
}

