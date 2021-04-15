#include <vector>
using std::vector;
using std::begin;
using std::end;
#include <algorithm>
#include <numeric>
#include <iterator>
#include <string>
using std::string;


int main()
{
  vector<int> v;
  int i = 0;
  std::generate_n(std::back_inserter(v), 5,[&]() { return i++; } );


  /* removing the `3`s */

  // 1) `for` loop
  /*
  auto v2 = v;
  for (unsigned int index = 0; index < v2.size(); index++)
  {
    if (v2[index] == 3)
    {
      v2.erase(v2.begin() + index);
    }
  }
  */

  // 2)  `for` loop using iterators
  /*
  auto v3 = v;
  for (auto it = begin(v3); it != end(v3); it++)
  {
    if (*it == 3)
    {
      v3.erase(it); // this invalidates the iterator for elements containing `3`
    }
  }
  */

  // The last two groups of `for` loops when run in succession invalidate the iterator for elements containing `3`, which breaks subsequent attempts to access `v`

  // 3) using `std::remove_if()` and `std::erase()`
  auto v4 = v;
  auto endv4 = std::remove_if(begin(v4), end(v4), [](int elem) {return (elem == 3); }); // N.B. `std::remove_if()` does not remove any elements from the container, but rather moves the "left-over" elements (i.e., that failed the predicate test condition) to the end of the collection 
  v4.erase(endv4, end(v4)); // the "excess" elements can be removed via method `erase()` by passing in the iterator returned from `std::remove_if()` in the previous line

  // v4.erase(std::remove_if(begin(v4),end(v4),[](int elem){return (elem == 3);}),end(v4)); // The previous two statements can be combined into one line, and indeed this is a common idiom in C++

  return 0;
}
