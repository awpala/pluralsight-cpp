#include <vector>
using std::vector;
#include <algorithm>
using std::replace;
using std::replace_if;
#include <numeric>
using std::iota;


int main()
{
  vector<int> v6(10);
  iota(begin(v6), end(v6), 1);

  replace(begin(v6), end(v6), 2, 7); // replace `2` with `7`
  replace_if(begin(v6), end(v6), [](int elem) {return elem < 16; }, 7); // replace all elements where `elem < 16` with `7`

  return 0;
}
