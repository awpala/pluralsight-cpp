#include <cassert>  // for assert
#include <iostream>
using std::cin;
using std::cout;
#include <map>
using std::map;
#include <string>
using std::string;


void PrintC64Memory( map<string, int> const& memory ) {
  // cout << " The C64 has " << memory["C64"] << "KB of memory. \n"; // error -- cannot use operator `[]` (only overloaded for non-`const` key) to access read-only/`const` key

  // Look up the C64 RAM in the map
  auto it = memory.find("C64");

  // Assume the C64 is in the map
  assert(it != memory.end());

  // Print the amount of memory (it->second)
  cout << " The C64 has " << it->second << "KB of memory. \n"; // use returned iterator `it` to access the value of the element/association
}

int main() {
  map<string, int> computerMemoryKB{};
  computerMemoryKB["C64"]       = 64;  // KB
  computerMemoryKB["Amiga 500"] = 512; // KB
  // ...

  PrintC64Memory(computerMemoryKB);

  return 0;
}
