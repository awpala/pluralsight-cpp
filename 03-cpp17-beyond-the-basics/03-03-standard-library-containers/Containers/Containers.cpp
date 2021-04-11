#include "Resource.h"
#include <vector> // provides `std::vector` container
#include <stdexcept>
#include <iostream>

using std::vector;
using std::cout;
using std::endl;


int main()
{
  vector numbers{ 0,1,2 }; // initialize vector via `{...}` -- N.B. C++17 provides class template deduction (i.e., not necessary to write the more verbose `vector<int> numbers{ 0,1, 2};`, as compiler deduces the type from the initializer)
  numbers.push_back(-2); // `push_back()` is one of the most commonly used methods, which simply adds an element to the end of the vector
  numbers[0] = 3; // element access via `[]` (analogously to a C-style array) -- N.B. elements are accessed via zero-based indices
  int num = numbers[2];

  for (int i : numbers) // collections provide the range-based `for` to access its members sequentially in turn (analogous to a `foreach` loop in other languages)
  {
    cout << i << '\n';
  }
	cout << endl;

	// vectors (and other containers) manage their memory automatically
  Resource r("local"); // `Resource` is a class with a `std::string` member variables
  { //braces for scope
    cout << "------------------------------" << '\n';
    vector<Resource> resources; // initialize a vector of <Resource> objects (initially empty)
    resources.push_back(r); // add `r` to the vector -- calls the copy constructor to accomplish this
    cout << "------------------------------" << '\n';
    resources.push_back(Resource("first")); // add an anonymous `Resource` object -- creates a temporary `Resource` object first, resizes the vector, copies both objects (`r` and the anonymous object) to the vector, and then destroys both objects, with the vector now containing the two copied objects
    cout << "------------------------------" << '\n';
    resources.push_back(Resource("second")); // add another anonymous `Resource` object -- similarly performs resizing and copying as in the previous call to `push_back()`
    cout << "------------------------------" << '\n';
  } // when `r` and the vector `resources` go out of scope, all of the `Resource` objects are automatically destroyed -- no need to do this manually! 
  return 0;
}
