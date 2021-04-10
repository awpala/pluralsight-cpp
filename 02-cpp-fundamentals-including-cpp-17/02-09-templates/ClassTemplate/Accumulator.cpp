#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include "Person.h"
#include "Accum.h"


int main()
{
  Accum<int> integers(0);
  integers += 3;
  integers += 7;
  cout << integers.GetTotal() << endl;

  Accum strings(string("")); // in C++17 and later, compiler can automatically deduce type `string` (i.e., rather than requiring the full declaration Accum<string> strings(""))
  strings += "hello";
  strings += " world";
  cout << strings.GetTotal() << endl;

  // These lines are invalid since `+=` is not overloaded in templated class `Person` -- this is a demonstration of type safety in C++ (i.e., this is a feature, not a bug!)
  //integers += "testing";
  //strings += 4;

  return 0;
}
