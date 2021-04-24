#include <vector>
using std::vector;
#include <algorithm>
using std::for_each;
#include <string>
using std::string;


int main()
{
  vector<int> a{ 1, 2, 3, 4, 5};
  vector<int> b{ 1, 2, 0, 4 };

  // raw `for` loop using iterators
  b = a;
  for (auto it = begin(b); it != end(b); it++)
  {
    *it = 0;
  }

  // ranged `for` loop -- equivalent to above
  for (auto& i : b) // N.B. pass by reference here to change the element values of the container `b`
  {
    i = 1;
  }

  // `std::for_each()` -- equivalent to above
  for_each(begin(b), end(b), [](int& elem) {elem = 2; });

  // while the ranged `for` loop is particularly useful for the above (equivalent) simple examples, below is an example where `std::for_each()` is particularly useful--when changing only part of the collection
  b = a;
  auto firstthree = find(begin(b), end(b), 3);
  for_each(firstthree, end(b), [](int& elem) {elem = 0; });

  return 0;
}
