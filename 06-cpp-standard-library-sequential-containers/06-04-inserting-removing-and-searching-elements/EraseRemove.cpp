// Demo: Erase-remove idiom with std::vector

#include <algorithm>
using std::remove_if;
#include <iostream>
using std::cout;
#include <ostream>
using std::ostream;
#include <vector>
using std::vector;


ostream& operator<<(ostream& os, const vector<int>& v) {
  os << "[ ";
  for (const auto& x : v) {
    os << x << ' ';
  }
  os << ']';
  return os;
}

inline bool IsOdd(int x) { // predicate function to determine integer parity
  return x % 2 == 1;
}

int main() {
  vector<int> v{11, 22, 33, 44, 55, 66};
  cout << " Initial vector: " << v << "\n\n";
  
  cout << " Removing the odd numbers from the vector.\n\n";

  v.erase(remove_if(begin(v), end(v), IsOdd), end(v)); // erase-remove idiom via nested call to `std::remove_if()` -- N.B. `std::remove_if()` returns an iterator to the beginning of the removed elements

  // v.erase(remove_if(begin(v), end(v), IsOdd)); // N.B. failure to include the second iterator `end(v)` to `std::vector::erase()` will introduce a bug -- only one element is erased, while the remaining "garbage" values are still present in `v`

  // std::erase_if(v, IsOdd); // C++20 provides this wrapper to perform the equivalent erase-remove idiom cleanly in one step

  cout << " Vector content after erase-remove: " << v << "\n\n";

  return 0;
}
