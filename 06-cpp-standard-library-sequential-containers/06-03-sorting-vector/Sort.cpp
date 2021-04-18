#include <algorithm>
using std::sort;
#include <fstream>
using std::ifstream;
#include <iostream>
using std::cout;
#include <string>
using std::string;
using std::getline;
#include <vector>
using std::vector;


int main() {
  // Read lines from text file into `std::vector` object `lines`
  vector<string> lines{};
  ifstream inputFile{ "strings.txt" };
  string line{};
  while (getline(inputFile, line)) {
    lines.push_back(line);
  }

  // Sort the lines in the vector via Standard Library algorithm `std::sort()`
  sort(begin(lines), end(lines));

  // Print the sorted lines
  for (const auto& x : lines) {
    cout << x << '\n';
  }

  return 0;
}
