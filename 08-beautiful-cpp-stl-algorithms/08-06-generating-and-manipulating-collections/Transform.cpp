#include <vector>
using std::vector;
#include <algorithm>
using std::transform;
#include <numeric>
using std::iota;


int main()
{
  vector<int> source {3, 6, 1, 0, -2, 5};
  vector<int> v6(10);
  iota(begin(v6), end(v6), 1);

  transform(begin(source), end(source), begin(source), [](int elem) {return elem * 2; }); // doubles each element of `v6`
  transform(begin(source), end(source)-1, begin(source)+1, begin(v6), [](int elem1, int elem2) {return elem1-elem2; }); // transforms the element-wise difference between `v6` and `source` (offset by one index position) into `v6`

  iota(begin(v6), end(v6), 1);
  iota(begin(source), end(source), 2);
  vector<int> v7(10);
  transform(begin(source), end(source), begin(v6), begin(v7), [](int elem1, int elem2) {return elem1 + elem2; }); // transforms the element-wise addition of `source` and `v6` into `v7`

  return 0;
}
