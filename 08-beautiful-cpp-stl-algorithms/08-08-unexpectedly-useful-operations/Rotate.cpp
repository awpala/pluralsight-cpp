#include <vector>
using std::vector;
#include <algorithm>
using std::find;
using std::rotate;
#include <numeric>
using std::iota;


int main()
{
  vector<int> tasks(6);
  iota(begin(tasks), end(tasks), 1); // `tasks` contains `{ 1, 2, 3, 4, 5, 6}`
  
  auto two = std::find(begin(tasks), end(tasks), 2);
  auto four = std::find(begin(tasks), end(tasks), 4);
  rotate(two, four, four + 1); // `tasks` now contains `{ 1, 4, 2, 3, 5, 6 }`, with `4` shifted to the original position of `2`

  return 0;
}
