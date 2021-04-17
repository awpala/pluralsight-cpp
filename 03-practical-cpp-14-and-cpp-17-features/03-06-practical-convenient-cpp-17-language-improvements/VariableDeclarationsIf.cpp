#include <algorithm>  // For std::find()
#include <iostream>   // For std::cout
#include <string>     // For std::string
#include <vector>     // For std::vector
using namespace std;

// Print message followed by vector content
void print(const string& message, const vector<string>& v) {
  cout << ' ' << message << ": ";
  for (const auto& s : v) {
    cout << s << ' ';
  }  
  cout << '\n';
}

int main() {
  vector<string> names{"C64", "John", "Connie", "Mike", "Beth"};
  print("Before", names);

  // `"Connie"` ==> `"***"`
  if (
    const auto it = find(begin(names), end(names), "Connie");
    it != end(names) // `if` condition
  ) {
    *it = "***"; // `it` is scoped to the `if` statement
  }

  // `"C64"` ==> `"**"`
  if (
    const auto it = find(begin(names), end(names), "C64");
    it != end(names) // `if` condition
  ) {
    *it = "**"; // `it` is scoped to the `if` statement -- independently of the previous `if` statement
  }

  print("After", names);

  return 0;
}
