
#include <vector>
using std::vector;
#include <algorithm>
using std::find;
#include <numeric>
using std::iota;
#include <iterator>
using std::back_inserter;


int main()
{
  vector<int> v1(10);
  iota(begin(v1), end(v1), 1);
  vector<int> v2;
  v2.clear();
  copy(rbegin(v1), rend(v1), back_inserter(v2));
  v1[5] = 2;

  // Is `3` in the first or second half?
  auto three = find(begin(v1), end(v1), 3);
  bool firsthalf = (three - begin(v1) < end(v1) - three); // `true` -- comparison performed via iterator arithmetic
  
  // What about `9`?
  auto nine = find(begin(v1), end(v1), 9);
  firsthalf = (nine - begin(v1) < end(v1) - nine); // `false`

  return 0;
}
