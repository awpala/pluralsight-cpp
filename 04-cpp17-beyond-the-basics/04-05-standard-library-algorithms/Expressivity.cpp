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
  /* populating a vector */
  vector<int> v;

  // 1) `for` loop with increment in `for`
  for (int i = 0; i < 5; i++)
  {
    v.push_back(i);
  }

  // 2) `for` loop with increment inside loop body
  for (int i = 0; i < 5; )
  {
    v.push_back(i++);
  }

  // 3) using `std::generate_n()`
  int i = 0;
  std::generate_n(std::back_inserter(v), 5,[&]() { return i++; } );


  /* totalling the elements */

  // 1) `for` loop
  int total = 0;
  for (int index = 0; index < 5; index++)
  {
    total += v[index];
  }

  // 2) ranged `for` loop
  total = 0;
  for (int elem : v)
  {
    total += elem;
  }

  // 3) using `std::accumulate()`
  total = std::accumulate(begin(v), end(v), 0); // N.B. does not require an indexing variable `i`


  /* counting the number of `3`s */

  // 1) `for` loop
  int count1 = 0;
  for (unsigned int i = 0; i < v.size(); i++)
  {
    if (v[i] == 3)
    {
      count1++;
    }
  }

  // 2) `for` loop with iterators
  int count2 = 0;
  for (auto it = begin(v); it != end(v); it++)
  {
    if (*it == 3)
    {
      count2++;
    }
  }

  // 3) using `std::count()`
  int count3 = std::count(begin(v), end(v), 3);

  return 0;
}
