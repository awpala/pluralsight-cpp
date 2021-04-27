#include <vector>
using std::vector;
#include <algorithm>
using std::stable_partition;
using std::find;
using std::rotate;
#include <numeric>
using std::iota;


int main()
{
  vector<int> numbers(8);
  iota(begin(numbers), end(numbers), 1);
  auto selected = std::stable_partition(begin(numbers), end(numbers), [](int i) {return i % 2 != 0; }); // partition `numbers` into odds and evens (respectively) with original-collection order preserved, i.e., `{ 1, 3, 5, 7, 2, 4, 6, 8 }` -- returns iterator to start of evens partition (i.e., `2`), stored in `selected` for subsequent rotation
  auto four = std::find(begin(numbers), end(numbers), 4); // iterator pointing to element `4`
  rotate(begin(numbers), selected, four); // rotate (initial-partition) odd elements of `numbers` about element `4`'s position (exclusive), i.e., `{ 2, 1, 3, 5, 7, 4, 6, 8 }` 

  return 0;
}
