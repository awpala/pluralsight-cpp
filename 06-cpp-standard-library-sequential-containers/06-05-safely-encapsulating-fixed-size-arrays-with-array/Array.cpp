// std::array Demo

#include <algorithm>
using std::find;
#include <array>
using std::array;
#include <iostream>
using std::cin;
using std::cout;


int main() {
  array<int, 6> a{11, 22, 33, 44, 55, 66}; // initializes `std::array` object `a` with `6` elements of type `int`
  // array a{11, 22, 33, 44, 55, 66}; // equivalent to previous statement -- requires C++17 or later to automatically deduce element count and their type

  cout << " std::array's elements: \n";
  for (const auto& x : a) {
    cout << ' ' << x;
  }
  cout << "\n\n";

  cout << " The array contains " << a.size() << " elements. \n\n"; // via method `size()`
  
  cout << " Please enter a number to search for : ";
  int n{};
  cin >> n;

  auto it = find(begin(a), end(a), n); // using `std::find()`
  if (it != end(a)) {
    cout << ' '  << n << " was found in the array. \n";
  } else {
    cout << ' '  << n << " not found. \n";
  }

  return 0;
}
