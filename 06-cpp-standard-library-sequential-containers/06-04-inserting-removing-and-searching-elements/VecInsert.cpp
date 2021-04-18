// Demo: Inserting elements in std::vector

#include <iostream>
using std::cout;
#include <ostream>
using std::ostream;
#include <vector>
using std::vector;


ostream& operator<<(ostream& os, const vector<int>& v) { // overload of `operator<<` to print out vector as `"[ ... ]"`
  os << "[ ";
  for (const auto& x : v) {
    os << x << ' ';
  }
  os << ']';

  return os;
}

int main() {
  vector<int> v{ 11, 22, 33, 44, 55, 66 };

  cout << " Initial vector: " << v << "\n\n";

  cout << " Inserting a single element (99): \n";
  v.insert(begin(v) + 1, 99);
  cout << "\t" << v << "\n\n";

  cout << " Inserting 3 copies of 100: \n";
  v.insert(begin(v) + 2, 3, 100);
  cout << "\t" << v << "\n\n";

  vector<int> source{ -11, -22, -33 };
  cout << " Inserting values from source range: \n";
  v.insert(begin(v) + 1, begin(source), end(source));
  cout << "\t" << v << "\n\n";

  cout << " Inserting values from initializer list: \n";
  v.insert(begin(v) + 4, { 111, 222, 333 });
  cout << "\t" << v << "\n\n";

  return 0;
}
