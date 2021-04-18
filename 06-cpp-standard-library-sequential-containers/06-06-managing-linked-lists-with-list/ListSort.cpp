// std::list Sorting

#include <algorithm>
using std::find;
#include <iostream>
using std::cout;
#include <list>
using std::list;
#include <string>
using std::string;


int main() {
  list<string> planets{
    "Mercury", "Venus", "Earth",
    "Mars", "Jupiter", "Saturn",
    "Uranus", "Neptune"
  };
  
  cout << " Initial list of planets: \n";
  for (auto const& name : planets) {
    cout << ' ' << name;
  }
  cout << "\n\n";

  cout << " Sorting the list... \n\n";
  // sort(begin(planets), end(planets)); // compiler error -- `std::sort()` expects random-access iterators, but `std::list` only provides bidirectional iterators
  planets.sort(); // therefore, use method `std::list::sort()` instead

  cout << " Sorted list of planets (alphabetical order): \n";
  for (auto const& name : planets) {
    cout << ' ' << name;
  }
  cout << '\n';

  return 0;
}
