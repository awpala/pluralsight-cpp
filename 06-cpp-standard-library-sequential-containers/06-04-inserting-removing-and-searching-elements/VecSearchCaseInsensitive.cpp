// Demo: Searching strings in std::vector ignoring case, using std::find_if

#include <algorithm>
using std::find_if;
using std::equal;
#include <cctype> 
using std::tolower;
#include <iostream>
using std::cin;
using std::cout;
#include <string>
using std::string;
#include <vector>
using std::vector;


// Case-insensitive string comparison (predicate function)
// (Note: doesn't work for UTF-8)
inline bool CaseInsensitiveEquals(const string& s1, const string& s2) {
  return equal(
    begin(s1), end(s1),
    begin(s2), end(s2),
    [](char ch1, char ch2) {
      // Compare char-by-char in lowercase
      return tolower(ch1) == tolower(ch2);
    }
  );
}

int main() {
  vector<string> v{"Galileo", "C64", "Connie", "Amiga", "C++"};
  
  cout << " String vector contains: \n";
  for (const auto& s : v) {
    cout << "\t" << s << '\n';
  }
  cout << '\n';

  cout << " Please enter a string to search for: ";
  string s;
  cin >> s;
  cout << '\n';

  auto pos = find_if(begin(v), end(v), 
    [&s](const auto& x) { // capture `s` by reference
      return CaseInsensitiveEquals(x, s); // case-insensitive string comparison
    });
  if (pos != end(v)) {
    cout << ' ' << s << " was found in the vector! \n";  
  } else {
    cout << " The vector doesn't contain " << s << " \n";
  }

  return 0;
}
