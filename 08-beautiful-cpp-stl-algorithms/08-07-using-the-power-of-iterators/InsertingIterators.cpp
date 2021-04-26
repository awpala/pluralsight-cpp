#include <vector>
using std::vector;
#include <algorithm>
using std::fill;
using std::fill_n;
using std::generate_n;
#include <numeric>
using std::iota;
#include <iterator>
using std::back_inserter;
using std::front_inserter;
#include <deque>
using std::deque;


int main()
{
  // pre-allocating `std::vector` container `v1` before populating
  vector<int> v1(10);
  fill(begin(v1), end(v1), 1);
  fill_n(begin(v1), 6, 2);
  iota(begin(v1), end(v1), 1);

  // alternative approach (better) using inserting iterators to populate `std::vector` container `v2` and `std::deque` container `q3`
  vector<int> v2;
  fill_n(back_inserter(v2), 6, 2); // inserts six elements into `v2`
  generate_n(back_inserter(v2), 10, [n = 0]()mutable{return n++; }); // inserts ten additional elements (to the back of) `v2` -- N.B. `[n = 0]` is an "alias capture,"" a useful feature in modern lambdas (i.e., no need for defining superfluous local variables outside of the lambda scope)

  deque<int> q3;
  fill_n(front_inserter(q3), 6, 2);
  generate_n(front_inserter(q3), 10, [n = 0]()mutable{return n++; });

  //fill_n(front_inserter(v1), 6, 2); // error -- `std::vector` does not support `std::front_inserter()`

  return 0;
}
