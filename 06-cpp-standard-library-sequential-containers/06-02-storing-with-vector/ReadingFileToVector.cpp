#include <fstream>
using std::ifstream;
#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <string>
using std::string;

int main() {
  /* reading `int`s from a file */
  vector<int> v{};

  ifstream inputFileInt{ "ints.txt" };
  int n{};
  while (inputFileInt >> n) { // input via operator `>>`
    v.push_back(n);
  }

  for (const auto& x : v) { // ranged `for` loop, accessing each element by `const` reference (i.e., read-only)
    cout << x << '\n';
  }

  cout << "\n\n";

  /* reading `string`s from a file */
  vector<string> lines{};

  ifstream inputFileStr{ "strings.txt" };
  string line{};
  while (getline(inputFileStr, line)) { // input via function `getline()`
    lines.push_back(line);
  }

  for (const auto& x : lines) {
    cout << x << '\n';
  }

  return 0;
}
