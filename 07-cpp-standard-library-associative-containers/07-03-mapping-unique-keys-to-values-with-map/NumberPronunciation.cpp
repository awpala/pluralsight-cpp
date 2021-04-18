// Demo: Associate some integer numbers to their pronunciation using std::map

#include <cassert>  // for assertions
#include <iostream>
using std::cout;
#include <map>
using std::map;
#include <string>
using std::string;


int main() {
  // Create an empty map
  map<int, string> numbers{};
  
  // Verify that the map is initially created empty
  assert( numbers.empty() );

  // Create some number-pronunciation associations in the map;
  numbers[1]  = "one";
  numbers[2]  = "two";
  numbers[64] = "sixty-four";
  numbers[4]  = "four";
  numbers[3]  = "three";

  // Print the content of the map -- output shows that associations are in key-sorted order (irrespective of insertion order)
  for (auto const& [num, pronunciation] : numbers) {
    cout << " The number " << num << " is pronounced " << pronunciation << ". \n";
  }

  return 0;
}
