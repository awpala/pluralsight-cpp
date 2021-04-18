// Demo: Searching elements in std::vector using std::find

#include <algorithm>
using std::find;
#include <iostream>
using std::cout;
using std::cin;
#include <string>
using std::string;
#include <vector>
using std::vector;


int main() {
  vector<string> v{"Galileo", "C64", "Connie", "Amiga", "C++"};
  
  cout << " String vector contains: \n";
  for (const auto& s : v) {
    cout << "\t" << s << '\n';
  }
  cout << '\n';

  cout << " Please enter a string to search for: ";
  string s;
  cin >> s; // N.B. `cin` is not robust for input including spaces -- in that case, use `std::getline()` instead
  cout << '\n';

  auto pos = find(begin(v), end(v), s);
  if (pos != end(v)) {
    cout << ' ' << s << " was found in the vector! \n";  
  } else {
    cout << " The vector doesn't contain " << s << " \n";
  }

  return 0;
}
