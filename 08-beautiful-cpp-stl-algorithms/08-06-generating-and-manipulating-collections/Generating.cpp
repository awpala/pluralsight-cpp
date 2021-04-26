#include <vector>
using std::vector;
#include <algorithm>
using std::fill;
using std::fill_n;
using std::generate;
using std::generate_n;
#include <numeric>
using std::iota;


int main()
{
  vector<int> source {3, 6, 1, 0, -2, 5};

  vector<int> v6(10); // initializes all ten elements to `0` by default for `int`s (i.e., `{ 0, 0, 0, ... 0}`)
  fill(begin(v6), end(v6), 1); // fills `v6` with `{ 1, 1, 1, ..., 1 }`
  fill_n(begin(v6), 6, 2); // fills `v6` with `{ 2, 2, 2, 2, 2, 2, ... }`
  iota(begin(v6), end(v6), 1); // fills `v6` with `{ 1, 2, 3, ..., 10 }`

  int index = 10;
  generate(begin(v6), end(v6), [&index]() {return --index; }); // fills `v6` with `{ 9, 8, ..., 0 }`
  
  source = v6;
  index = 1;
  generate_n(begin(v6), 7, [&index]() {return (index *=2); }); // fills `v6` with `{ 2, 4, 8, 16, 32, 64, 128, ... }`

  return 0;
}
