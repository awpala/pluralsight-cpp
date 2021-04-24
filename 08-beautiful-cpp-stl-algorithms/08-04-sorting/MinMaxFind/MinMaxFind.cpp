#include <vector>
using std::vector;
#include <string>
using std::string;
#include <algorithm>
using std::min_element;
using std::max_element;
using std::sort;
using std::lower_bound;
using std::upper_bound;
#include "Employee.h"


int main()
{
  vector<int> v{ 4,1,0,1,-2,3,7,-6,2,0,0,-9,9 };
  auto v2 = v;

  int high = *(max_element(begin(v), end(v))); // `9` -- via full search of `v`
  int low = *(min_element(begin(v), end(v))); // `-9` -- via full search of `v`
  
  sort(begin(v2), end(v2));
  low = *begin(v2); // `9` -- directly via first element of sorted `v2`
  high = *(end(v2)-1); // `-9` -- directly via last element of `v2`
  int positive = *upper_bound(begin(v2), end(v2), 0); // `1` -- first-occurring positive number in `v2` via predicate value `0`


  vector<Employee> staff{
    { "Kate", "Gregory", 1000 },
    { "Obvious", "Artificial", 2000 },
    { "Fake", "Name", 1000 },
    { "Alan", "Turing", 2000 },
    { "Grace", "Hopper", 2000 },
    { "Anita", "Borg", 2000 }
  };

  sort(begin(staff), end(staff),
    [](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); }); // sort by `lastname`s

  // `std::lower_bound()` can be used idiomatically to find a specific element in a sorted collection
  auto p = lower_bound(begin(staff), end(staff), "Gregory, Kate",
    [](Employee e1, string n) {return e1.getSortingName() < n; }); // predicate will return `e1` having `lastname` of `"Gregory"` (predicate is `false` for this condition, and thus `std::lower_bound()` halts further iteration upon reaching this element)
  int sal = p->getSalary();

  return 0;
}
