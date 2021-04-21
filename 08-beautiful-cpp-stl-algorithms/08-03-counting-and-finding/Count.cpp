#include <vector>
using std::vector;
#include <algorithm>
using std::count;
#include <map>
using std::map;

int main()
{
  vector<int> v{ 2,7,1,6,2,-2,4,0 };

  //count how many entries have the target value (2)
  int twos = 0;
  int const target = 2;
  for (size_t i = 0; i < v.size(); i++)
  {
    if (v[i] == target)
    {
      twos++;
    }
  }

  // equivalent to previous `for` loop using `std::count()`
  twos = count(v.begin(), v.end(), target); // iterators via member functions
  twos = count(begin(v), end(v), target); //  equivalent to previous statement -- iterators via free/non-member functions

  return 0;
}
