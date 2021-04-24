#include <vector>
using std::vector;
#include <algorithm>
using std::equal;
using std::mismatch;


int main()
{
  vector<int> a{ 1, 2, 3, 4, 5 };
  vector<int> b{ 1, 2, 0, 4 };

  // comparison via raw `for` loop -- bad practice, use Standard Library instead
  bool same = a.size()==b.size();
  for (size_t i = 0; i < a.size() && same; i++)
  {
    if (a[i] != b[i])
    {
      same = false;
    }
  }

  // equivalent logic to previou statements via `std::equal()`
  same = equal(begin(a), end(a), begin(b), end(b));
  
  auto firstchange = mismatch(begin(a), end(a), begin(b)); // returns `std::pair` of iterators to elements `3` and `0` in containers `a` and `b` (respectively)

  // use properties `.first` and `.second` to access the elements of the `std::pair` object `firstchange`
  int avalue = *(firstchange.first);
  int bvalue = *(firstchange.second);
  auto distance = firstchange.first - begin(a); // `2` via "iterator arithmetic" -- the two collections diverge at the third (index `2`) position (relative to initial index, `0`)

  return 0;
}
