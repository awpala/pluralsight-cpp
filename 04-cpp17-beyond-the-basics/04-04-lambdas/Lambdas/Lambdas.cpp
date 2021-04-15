#include <algorithm>
using std::count_if;
#include <vector>
using std::vector;
using std::begin;
using std::end;


int main()
{
  auto isOdd = [](int candidate) {return candidate % 2 != 0; };

  bool is3Odd = isOdd(3);
  bool is4Odd = isOdd(4);

  vector nums { 2,3,4,-1,1 };

  int odds = count_if(begin(nums), end(nums), isOdd); // counts using `isOdd`
  int evens = count_if(begin(nums), end(nums), [](int candidate) {return candidate % 2 == 0; }); // counts using anonymous lambda -- this is more idiomatic if the lambda is only used for this singular purpose

  return 0;
}
