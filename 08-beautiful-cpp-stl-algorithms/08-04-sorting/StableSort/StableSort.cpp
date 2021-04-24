#include <vector>
using std::vector;
#include <algorithm>
using std::sort;
using std::stable_sort;
#include "Employee.h"


int main()
{
  vector<Employee> staff{
    { "Kate", "Gregory", 1000 },
    { "Obvious", "Artificial", 2000 },
    { "Fake", "Name", 1000 },
    { "Alan", "Turing", 2000 },
    { "Grace", "Hopper", 2000 },
    { "Anita", "Borg", 2000 }
  };

  //sort(begin(staff), end(staff)); // only works if `operator<` is defined for `Employee`

  sort(begin(staff), end(staff),
    [](Employee e1, Employee e2) {return e1.getSalary() < e2.getSalary(); }); // sorts by `salary`, however, due to "ties" in salaries, the secondary sort order (i.e., by `lastname`) is non-deterministic
  sort(begin(staff), end(staff),
    [](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); }); // sorts by `lastname`s, which are unique

  sort(begin(staff), end(staff),
    [](Employee e1, Employee e2) {return e1.getSortingName() < e2.getSortingName(); }); // primary sort by `lastname`s
  stable_sort(begin(staff), end(staff),
    [](Employee e1, Employee e2) {return e1.getSalary() < e2.getSalary(); }); // secondary sort via `std::stable_sort()` by `salary` -- results in deterministic sort: primary by `lastname` (via `std::sort()`), secondary by `salary` (via `std::stable_sort()`)

  return 0;
}
