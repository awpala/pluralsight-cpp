#include <iostream> // for std::cout
#include <map>      // for std::map
#include <string>   // for std::string
using namespace std;

int main() {
  map<string, string> italianDictionary{
    {"casa",   "home"},
    {"gatto",  "cat"},
    {"tavolo", "table"}
    // ...
  };

  auto [pos, success] = italianDictionary.insert({"sedia", "chair"}); // structured binding used to store (`std::pair`) return values from method `std::map.insert()`
  if (success) {
    cout << " Insertion OK.\n\n";
  }

  for (const auto& [italian, english] : italianDictionary) { // structured binding can also be used in a ranged `for` loop over a `std::map` object (e.g., `italianDictionary`)
    cout << ' ' << italian << ": " << english << '\n';
  }

  return 0;
}
