#include <vector>
using std::vector;
#include <algorithm>
using std::count_if;
#include "Utility.h"


int main()
{
  std::vector<int> nums{ 1,2,3,4 };

  int odds = std::count_if(begin(nums), end(nums), isOdd); // predicate via named function `isOdd`
  
  int count = std::count_if(begin(nums), end(nums), ShouldBeCounted); // predicate via named function `ShouldBeCounted`
  count = std::count_if(begin(nums), end(nums),
    [](int i) { return ((i == 2) || (i == 3)); } // predicate via inline/anonymous lambda -- equivalent to previous line, but more idiomatic since "`ShouldBeCounted`" is not a meaningful function name
  );

  return 0;
}
