#include <vector>
using std::vector;
#include <algorithm>
using std::swap;
using std::iter_swap;
using std::swap_ranges;


int main()
{
  int a{ 4 }, b{ 5 };
  swap(a, b); // swap values

  vector<int> evens{ 2, 4, 6, 8, 10 };
  vector<int> odds{ 1 ,3, 5, 7, 9 };

  auto v1 = evens;
  swap(v1[0], v1[1]); // swap within container via element value
  iter_swap(begin(v1), begin(v1) + 1); // swap within container via iterators

  auto v2 = odds;
  swap(v1[0], v2[0]); // swap across containers via element value
  iter_swap(begin(v1), find(begin(v2), end(v2), 5)); // swap across containers via iterators -- N.B. it is idiomatic to perform nested calls as a single step (i.e., `std::find()` as an argument to `std::iter_swap()`)

  v1 = evens;
  v2 = odds;
  swap_ranges(begin(v1), find(begin(v1), end(v1), 6), begin(v2)); // swap multiple elements across containers via iterators

  return 0;
}
