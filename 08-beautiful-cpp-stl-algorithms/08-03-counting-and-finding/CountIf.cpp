#include <vector>
using std::vector;
#include <algorithm>
using std::count_if;
#include <map>
using std::map;

int main()
{
  vector<int> v{ 2,7,1,6,2,-2,4,0 };

  // count how many entries are odd
  int odds = 0;
  for (auto elem : v)
  {
    if (elem % 2 != 0)
    {
      odds++;
    }
  }

  // equivalent to previous `for` loop using `std::count_if()`
  odds = count_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });

  // using `std::count_if()` with a `std::map` collection
  map<int, int> monthlengths{ { 1,31 },{ 2,28 },{ 3,31 },{ 4,30 },{ 5,31 },{ 6,30 },{ 7,31 },{ 8,31 },{ 9,30 },{ 10,31 },{ 11,30 },{ 12,31 } };
  int longmonths = count_if(begin(monthlengths), end(monthlengths), [](auto elem) {return elem.second == 31; });

  return 0;
}
