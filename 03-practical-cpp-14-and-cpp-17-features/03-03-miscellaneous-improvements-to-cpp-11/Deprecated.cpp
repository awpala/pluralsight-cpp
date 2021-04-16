// Demo of the [[deprecated]] attribute

#include <iostream>
using namespace std;

// Deprecate this function
[[deprecated("DoSomething() is inefficient; use DoSomethingBetter() instead.")]]
void DoSomething() {
  cout << "I'm doing something the obsolete way.\n";
}

void DoSomethingBetter() {
  cout << "I'm doing something in a better way.\n";
}

int main() {
  // You should get a warning when compiling this code
  DoSomething();
}
