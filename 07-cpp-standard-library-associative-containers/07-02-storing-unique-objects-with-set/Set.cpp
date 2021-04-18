// Basic std::set demo: Shows set creation, element insertion, removal and search

#include <iostream>
using std::cout;
#include <ostream>
using std::ostream;
#include <set>
using std::set;
#include <string>
using std::string;


// Print set<string> content in the form: {s1, s2, ..., sn}
ostream & operator<<(ostream & os, const set<string> & strings) {
  os << '{';

  bool isFirst = true;
  for (const auto & s : strings) { // ranged `for` loop used for `std::set`
    if (isFirst) {
      os << s;
      isFirst = false;
    } else {
      os << ", " << s;
    }
  }

  os << '}';
  return os;
}

// Show basic operations with `std::set`
int main() {
  // initialize set
  set<string> colors{ "red", "yellow", "blue" };
  cout << " Initial set of colors: \n";
  cout << "  " << colors << "\n\n"; // N.B. Elements are inserted in sorted order (e.g., lexicographically by default, in the case of `std::string` elements)

  // insert set elements
  colors.insert("green");
  cout << " After inserting green: \n";
  cout << "  " << colors << "\n\n";

  colors.insert("green");
  cout << " Trying to insert green again: \n";
  cout << "  " << colors << "\n\n";

  // remove set element
  colors.erase("red");
  cout << " After removing red: \n";
  cout << "  " << colors << "\n\n";

  // search for set element
  auto it = colors.find("blue");
  if (it != colors.end()) {
    cout << " The set contains blue. \n";
  } else {
    cout << " The set doesn't contain blue. \n";
  }

  return 0;
}
