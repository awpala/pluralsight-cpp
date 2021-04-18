// std::list Demo

#include <algorithm>
using std::find;
#include <iostream>
using std::cout;
#include <list>
using std::list;
#include <string>
using std::string;


int main() {
  list<string> planets{"Venus", "Mars", "Jupiter", "Saturn", "Uranus"};

  // Insert Mercury at the beginning
  planets.push_front("Mercury");

  // Insert Neptune at the end
  planets.push_back("Neptune");
  
  // Insert Earth before Mars
  auto pos = find(begin(planets), end(planets), "Mars"); // use `std::find()` to determine the position to insert
  planets.insert(pos, "Earth"); // use method `insert()` to insert the element

  cout << " List of planets: \n  ";
  for (auto const& name : planets) { // ranged `for` loop is supported by `std::list` -- no need to implement the corresponding traversal by hand
    cout << ' ' << name;
  }
  cout << '\n';

  return 0;
}
