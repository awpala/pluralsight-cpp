#include <vector>
using std::vector;
#include <algorithm>
using std::copy;
using std::find;
#include <numeric>
using std::iota;
#include <iterator>
using std::back_inserter;


int main()
{
  vector<int> v1(10);
  iota(begin(v1), end(v1), 1); // `v1` contains `{ 1, 2, 3, ..., 10 }`

  vector<int> v2;
  v2.clear();
  copy(rbegin(v1), rend(v1), back_inserter(v2)); // copies contents of `v1` to `v2` in reverse order, i.e., `v2` contains `{ 10, 9, 8, ..., 1 }`

  v1[5] = 2;
  auto two = find(begin(v1), end(v1), 2);
  auto distance = two - begin(v1); // `1` -- pointing to the first-occurring element `2` in `v1`
  two++; // pointing to `3` in `v1`

  auto rtwo = find(rbegin(v1), rend(v1), 2);
  distance = rtwo - rbegin(v1); // `4` -- pointing to the second-occuring element `2` in `v1`
  rtwo++; // pointing to `5` in `v1`

  //distance = rtwo - two; // error -- cannot subtract a reverse iterator from a regular iterator (as before, strong typing in C++ is a feature, not a bug!)

  return 0;
}
