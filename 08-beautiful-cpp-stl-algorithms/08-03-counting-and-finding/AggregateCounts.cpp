#include <vector>
using std::vector;
#include <algorithm>
using std::count_if;
using std::all_of;
using std::any_of;
using std::none_of;
#include <map>
using std::map;

int main()
{
  vector<int> v{ 2,7,1,6,2,-2,4,0 };

  // A) aggregate count in two steps -- (1) `count_if()`, then (2) Boolean tests
  
  // 1) count how many entries are odd
  int odds = count_if(begin(v), end(v), [](auto elem) {return elem % 2 != 0; });

  // 2) are all, any, or none of the values odd? (Conclude from number of odd entries)
  bool allof, noneof, anyof;
  allof = (odds == v.size());
  noneof = (odds == 0);
  anyof = (odds > 0);


  // B) equivalent single-step count and test via corresponding Standard Library algorithm functions
  allof = all_of(begin(v), end(v), 
    [](auto elem) {return elem % 2 != 0; });
  noneof = none_of(begin(v), end(v), 
    [](auto elem) {return elem % 2 != 0; });
  anyof = any_of(begin(v), end(v), 
    [](auto elem) {return elem % 2 != 0; });

  return 0;
}
