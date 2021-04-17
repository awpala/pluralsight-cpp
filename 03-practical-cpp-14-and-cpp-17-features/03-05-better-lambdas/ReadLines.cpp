#include <algorithm>  // for std::sort
#include <fstream>    // for std::ifstream
#include <iostream>   // for std::cout
#include <string>     // for std::string, std::getline
#include <vector>     // for std::vector
using namespace std;

int main() { 
  // Open file for reading
  ifstream file{"data.txt"};

  // Read each line from file to vector
  vector<string> lines{};
  string line{};
  while (getline(file, line)) {
    lines.push_back(line);
  }

  // Sort the read lines
  sort(begin(lines), end(lines));

  // Print the sorted lines
  for (auto const& s : lines) {
    cout << s << '\n';
  }
}
